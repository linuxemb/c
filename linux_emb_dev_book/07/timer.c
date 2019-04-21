#include <unistd.h>
#include <time.h>
#include <signal.h>

#define MAX_EXPIRE 10
int expire;

void timer_handler(int signo, siginfo_t *info, void *context)
{
    int overrun;
    printf("signal details: signal (%d), code (%d)\n", info->si_signo, info->si_code);
    if (info->si_code == SI_TIMER){
	printf("timer-id = %d \n", info->si_timerid);
    	expire++;
	/* Specification says that only a single signal shall be queued to the process for a given timer
       	 * at any point in time. When a timer for which a signal is still pending
         * expires, no signal shall be queued, and a timer overrun  shall  occur. timer_getoverrun returns
         * the  number  of  extra timer expirations that occurred between the time
         * the signal  was  generated  (queued)  and  when  it  was  delivered  or
         * accepted
	 */
    	if ((overrun = timer_getoverrun(info->si_timerid)) != -1 && overrun != 0){
		printf("timer overrun %d\n", overrun);
		expire += overrun;
    	}
    }
}

int main(){
	struct timespec ts, tm, sleep;
	sigset_t mask;
    	siginfo_t info;
	struct sigevent sigev;
    	struct sigaction sa;
	struct itimerspec ival;
	timer_t tid;

	/* Get the clock resolution and current time for
	 * CLOCK_MONOTONIC. resolution should be 1/HZ and 
	 * gettime should give system boot time
	 */
	clock_getres(CLOCK_MONOTONIC, &ts);
	clock_gettime(CLOCK_MONOTONIC, &tm);
	printf("CLOCK_MONOTONIC res: [%d]sec [%d]nsec\n", ts.tv_sec, ts.tv_nsec);
	printf("system up time: [%d]sec [%d]nsec\n", tm.tv_sec, tm.tv_nsec);

 	/* We don't want any blocked signals */
  	sigemptyset(&mask);
    	sigprocmask(SIG_SETMASK, &mask, NULL);

	/* Register handler for SIGRTMIN */
    	sa.sa_flags = SA_SIGINFO;
    	sigemptyset(&sa.sa_mask);
    	sa.sa_sigaction = timer_handler;
  	if (sigaction(SIGRTMIN, &sa, NULL) == -1) {
        	perror("sigaction failed");
		return -1;
	}

	/* Signal notification desired. Timer expiry should send
	 * SIGRTMIN signal with some dummy value 1
	 */
	sigev.sigev_notify = SIGEV_SIGNAL;
	sigev.sigev_signo = SIGRTMIN;
	sigev.sigev_value.sival_int = 1;
	/* Create timer. Note that if the call is successful timer id 
	 * is returned in the third argument. Also if second arg is passed
	 * NULL, the effect is same as passing sigev with values
	 *		sigev.sigev_notify = SIGEV_SIGNAL;
	 *		sigev.sigev_signo = SIGALRM;
	 *		sigev.sigev_value.sival_int = Timerid;
	 */
	if (timer_create(CLOCK_MONOTONIC, &sigev, &tid) == -1){
		perror("timer_create");
		return -1;
	}
	printf("timer-id = %d\n", tid);

	/* Create a periodic timer that will 5 seconds from now (it_value)
	 * After expiry, timer shall get rearmed for 4 seconds(it_interval) and
	 * the process will continue
	 */
	ival.it_value.tv_sec = 5;
	ival.it_value.tv_nsec = 0;
	ival.it_interval.tv_sec = 4;
	ival.it_interval.tv_nsec = 0;
	/* The second argument can also be TIMER_ABSTIME flag. If the flag is set
         * then the  timer  shall  expire  when  the clock  reaches  the value specified 
   	 * by the ival.it_value . i.e third argument represents the absolute time 
         * wrt to clock. If the flag is not set then third argument represents the relative time
	 */
	if (timer_settime(tid, 0, &ival, NULL) == -1){
		perror("timer_settime");
		return -1;
	}

	/* Sleep and wait for signal */
	for(;;){
		sleep.tv_sec = 3;
		sleep.tv_nsec = 0;
		/* As mentioned above the second arg of clock_nanosleep could be 
	         * TIMER_ABSTIME
	 	 */
		clock_nanosleep(CLOCK_MONOTONIC, 0, &sleep, NULL);
		printf("woken up\n");
		if (expire >= MAX_EXPIRE){
			printf("Program quitting.\n");
			/* If it_value == 0 then call to timer_settime disarms the
			 * the timer
			 */ 
			memset(&ival, 0, sizeof (ival));
			timer_settime(tid, 0, &ival, NULL);
			return 0;
		}
	}

    /* Delete the timer */
    timer_delete(tid);

	return 0;
}

