#include <stdio.h>
#include <semaphore.h>
#include <sys/types.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <sys/fcntl.h>
#include <errno.h>

#define SEM_NAME "/mysem"

/*
 * unnamned semaphore usage
 *    sem_init()
 *      ...
 *    sem_destroy()
 *
 *  Named semaphore usage
 *    sem_open()
 *     ...
 *    sem_close()
 *    sem_unlink()
 */

int main(){
	sem_t *sema_n;
	int ret,val;
	
	/* open named semaphore, create it if it not already exists (O_CREAT).
	 * Its initial value is 1 */
	if ((sema_n = sem_open(SEM_NAME, O_CREAT , 0600, 1)) == SEM_FAILED){
		perror("sem_open");
		return -1;
	}

	/* get the semaphore value */
	sem_getvalue(sema_n, &val);
	printf("semaphore value = %d\n", val);

	/* call trywait and wait for get the semaphore */
	if ((ret = sem_trywait(sema_n)) != 0 && errno == EAGAIN)
		/* permanent wait */
		sem_wait(sema_n);
	else if (ret != 0){
		perror("sem_trywait");
		return -1;
	}

	/*
	 * OPERATE ON SHARED DATA
	 */

	/* release the semaphore */
	if (sem_post(sema_n) != 0)
		perror("post error");

	/* close and remove */
	sem_close(sema_n);
	sem_unlink(SEM_NAME);
	
	return 0;
}

