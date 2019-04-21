#include <unistd.h>
#include <aio.h>
#include <sys/types.h>
#include <errno.h>

#define INPUT_FILE "./input"
#define OUTPUT_FILE "./output"
#define XFER_SIZE   1024
#define MAX 3

char read_buf[1024];
char write_buf[1024];


void populate_aiocb(struct aiocb *aio, int fd, off_t offset, int bytes, char *buf, int opcode){
	aio->aio_fildes = fd;
	aio->aio_offset = offset;
	aio->aio_sigevent.sigev_notify = SIGEV_NONE;
	aio->aio_nbytes = bytes;
	aio->aio_buf = buf;
    /* This field could be LIO_READ for read request or LIO_WRITE for write
     * request
     */
	aio->aio_lio_opcode = opcode;
}
	
int main(){
	
	int fd_r , fd_w;
	struct aiocb a_write, a_read;
	struct aiocb *cblist[MAX];
	int err_r, err_w;
	int read_n = 0;
	int quit = 0;
	struct aiocb *cblist_lio[MAX];

	memset(&a_write, 0 , sizeof(struct aiocb));
	memset(&a_read, 0 , sizeof(struct aiocb));

	fd_r = open(INPUT_FILE, O_RDONLY, 0444);
	fd_w = open(OUTPUT_FILE, O_CREAT | O_WRONLY, 0644);

	populate_aiocb(&a_read, fd_r, 0, XFER_SIZE, read_buf, LIO_READ);
    populate_aiocb(&a_write, fd_w, 0, XFER_SIZE, write_buf, LIO_WRITE);

	if (aio_read(&a_read) == -1){
		perror("aio_read");
		return -1;
	}

	while((err_r = aio_error(&a_read)) == EINPROGRESS){
		printf("suspending..\n");
		cblist[0] = &a_read;
		aio_suspend(cblist, 1, NULL);
	}

	if (err_r == 0){
		read_n  = aio_return(&a_read);
		printf("read_n = %d\n", read_n);
		if (read_n == XFER_SIZE)
			a_read.aio_offset += XFER_SIZE;
		else
			quit = 1;
	}else{
		perror("aio_error");
		return -1;
	}

	while(1){

		memcpy(write_buf, read_buf, read_n);

		a_write.aio_nbytes = read_n;
		a_read.aio_nbytes = read_n;

        /* Prepare aiocb list for lio_listio */
		cblist_lio[0] = &a_read;
		cblist_lio[1] = &a_write;
	
        /* Call lio_listio to submit read and write AIO requests. If first
         * argument is LIO_WAIT then whilr loop following the call is not needed
         */
		lio_listio(LIO_NOWAIT, cblist_lio, 2, NULL);

		while((err_r = aio_error(&a_read)) == EINPROGRESS || (err_w = aio_error(&a_write)) == EINPROGRESS){
			cblist[0] = &a_read;
			cblist[1] = &a_write;
			aio_suspend(cblist, 2, NULL);
		}

		if (err_w == 0)
			a_write.aio_offset += aio_return(&a_write);
		else{
			perror("a_write");
			return -1;
		}

		if (quit)
			break;

		if (err_r == 0){
			read_n = aio_return(&a_read);
		printf("read_n = %d\n", read_n);
			if (read_n == XFER_SIZE)
				a_read.aio_offset += XFER_SIZE;
			else
				quit = 1;
		}else{
			perror("aio_read");
			return -1;
		}
	}

	close(fd_r);
	close(fd_w);
}

		
