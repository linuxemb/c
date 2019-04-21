#include <sched.h>

int main(){
	struct sched_param param, new_param;

	/*
	 * A process starts with the default policy SCHED_OTHER unless
	 * it's spawned by a SCHED_RR or SCHED_FIFO process. 
	 */
	printf("start policy = %d\n", sched_getscheduler(0));
	/* output -> start policy = 0 */

	/* 0 <- SCHED_OTHER, 1 <- SCHED_FIFO, 2 <- SCHED_RR */

	/*
	 * Create a SCHED_FIFO process running with average priority
	 */
	param.sched_priority = (sched_get_priority_min(SCHED_FIFO) + sched_get_priority_max(SCHED_FIFO))/2;
	printf("max priority = %d, min priority = %d, my priority = %d\n",
		sched_get_priority_max(SCHED_FIFO), sched_get_priority_min(SCHED_FIFO), param.sched_priority);
	/* output -> max priority = 99, min priority = 1, my priority = 50 */

	if (sched_setscheduler(0, SCHED_FIFO, &param) != 0){
		perror("sched_setscheduler failed\n");
		return;
	}

	/*
	 * perform time critical operation
	 */

	/*
	 * Lets give some other RT thread / process a chance to run. Note that call to sched_yield will 
	 * put the current process at the end of its priority queue. If there are no other process in the queue
	 * then the call will have no effect
	 */ 	
	sched_yield();

	/*
	 * You can also change the priority at run time
	 */
	param.sched_priority = sched_get_priority_max(SCHED_FIFO);
	if (sched_setparam(0, &param) != 0){
		perror("sched_setparam failed\n");
		return;
	}
	sched_getparam(0, &new_param);
	printf("I am running at priority %d\n", new_param.sched_priority);
	/* output -> I am running at priority 99 */
	
	return ;
}
