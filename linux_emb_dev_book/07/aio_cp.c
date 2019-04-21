#include <unistd.h>
#include <aio.h>
#include <sys/types.h>
#include <errno.h>

#define INPUT_FILE "./input"
#define OUTPUT_FILE "./output"
#define XFER_SIZE   1024
#define MAX 3

/* Function to fill the aiocb values
 */
void populate_aiocb(struct aiocb *aio, int fd, off_t offset, int bytes, char *buf){
        aio->aio_fildes = fd;
        aio->aio_offset = offset;
	/* We are not using any notification mechanism here to put more emphasis on
	 * AIO interfaces. We can use SIGEV_SIGNAL or SIGEV_THREAD notification mechanisms 
	 * to get notification after AIO is complete.
	 */
        aio->aio_sigevent.sigev_notify = SIGEV_NONE;
        aio->aio_nbytes = bytes;
        aio->aio_buf = buf;
}

/*
 * The application copies one file to other
 */
int main(){
	
	int fd_r , fd_w;
	struct aiocb a_write, a_read;
	struct aiocb *cblist[MAX];
	int err_r, err_w;
	int read_n = 0;
	int quit = 0;
	char read_buf[XFER_SIZE];
	char write_buf[XFER_SIZE];

	/* Its good practice to clear the aiocbs before 
	 * using them
	 */
	memset(&a_write, 0 , sizeof(struct aiocb));
	memset(&a_read, 0 , sizeof(struct aiocb));

	/* Open files for reading and writing */
	fd_r = open(INPUT_FILE, O_RDONLY, 0444);
	fd_w = open(OUTPUT_FILE, O_CREAT | O_WRONLY, 0644);

	/* populate aiocbs to defaults */
	populate_aiocb(&a_read, fd_r, 0, XFER_SIZE, read_buf);
	populate_aiocb(&a_write, fd_w, 0, XFER_SIZE, write_buf);

	/* Start async read. The function will read a_read.aio_nbytes bytes
	 * from file a_read.aio_fildes starting from a_read.aio_offset into 
	 * buffer a_read.aio_buf. On success 0 is returned. This function will
	 * return immediately after queueing the request
	 */
	aio_read(&a_read);

	/* After starting any async operation (read or write), you can get its status
	 * using aio_error function. This function returns EINPROGRESS if the request has not been completed
	 * It  returns ECANCELED if the request was cancelled.It returns 0
         * if the request completed successfully.  Otherwise  an  error  value  is returned
	 */
	while((err_r = aio_error(&a_read)) == EINPROGRESS){
		/* The  aio_suspend  function  suspends the calling process until at least
       		 * one of the asynchronous I/O requests in the list  cblist have completed,
       		 * a signal is delivered, or timeout occurs. Here we are waiting for
	   	 * aio_read completion on a_read.
		 */
		cblist[0] = &a_read;
		aio_suspend(cblist, 1, NULL);
	}

	/* aio_error returns 0 that is success. Call aio_return to find of number of 
	 * bytes read. The function should be called only once after aio_error returns
	 * something other than EINPROGRESS.
	 */
	if (err_r == 0){
		read_n  = aio_return(&a_read);
		if (read_n == XFER_SIZE)
			a_read.aio_offset += XFER_SIZE;
		else
			quit = 1;
	}

	while(1){

		memcpy(write_buf, read_buf, read_n);

		/* Setup write control block. Call aio_write to queue write request. The function 
		 * will write a_write.aio_nbytes bytes from buffer a_write.aio_buf to file a_write.aio_fildes
		 * at offset a_write.aio_offset. Returns 0 on success
		 */
		a_write.aio_nbytes = read_n;
		aio_write(&a_write);

		a_read.aio_nbytes = read_n;
		if (aio_read(&a_read) == -1){
			/* Cancel any pending writes. The function cancels any outstanding AIO requests.
			 * It returns AIO_CANCELED on success, AIO_NOTCANCELED if request is in progress,
			 * or AIO_ALLDONE if requested operation is already done
			 */
			aio_cancel(fd_w, &a_write);
			return -1;
		}

		/* Wait for both read and write to get complete before proceeding */
		while((err_r = aio_error(&a_read)) == EINPROGRESS || (err_w = aio_error(&a_write)) == EINPROGRESS){
			cblist[0] = &a_read;
			cblist[1] = &a_write;
			aio_suspend(cblist, 2, NULL);
		}

		/* Increment the write pointer */
		if (err_w == 0)
			a_write.aio_offset += aio_return(&a_write);

		/* This will get set if we reached EOS for input file */
		if (quit)
			break;

		/* Increment the read pointer */
		if (err_r == 0){
			read_n = aio_return(&a_read);
			if (read_n == XFER_SIZE)
				a_read.aio_offset += XFER_SIZE;
			else
				quit = 1;
		}
	}

	/* cleanup */
	close(fd_r);
	close(fd_w);
}
