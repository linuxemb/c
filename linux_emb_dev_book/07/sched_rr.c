#include <sched.h>

int main(){
	struct sched_param param;
	struct timespec ts;
	param.sched_priority = sched_get_priority_max(SCHED_RR);

	/* 
	 * need maximum timeslice
	 */
	nice(-20);
	sched_setscheduler(0, SCHED_RR, &param);
	sched_rr_get_interval(0, &ts);
	printf ("max timeslice = %d msec\n", ts.tv_nsec/1000000);
	/* output -> max timeslice = 199 msec */

	/*
	 * Need minimum timeslice. Also note the argument to nice represents 'increment' and not 
	 * absolute value. Thus we are doing nice(39) to make it running at nice priority +19
	 */
	nice(39); 
	sched_setscheduler(0, SCHED_RR, &param);
	sched_rr_get_interval(0, &ts);
	printf ("min timeslice = %d", ts.tv_nsec/1000000);
	/* output -> min timeslice = 9 msec */
	
	return ;
}
