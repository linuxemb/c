#include <signal.h>
#include <sys/types.h>
#include <unistd.h>
#include <errno.h>

int child(void);
int parent(pid_t);
void rt_handler(int signum, siginfo_t *siginfo, void * extra);

int main(){
    pid_t cpid;

    if ((cpid = fork()) == 0)
        child();
    else
        parent(cpid);
}

int child(void){
        
        sigset_t mask, oldmask;
        siginfo_t siginfo;
        struct sigaction action;
        struct timespec tv;
        int count = 0, recv_sig;

        /* clear mask */
        sigemptyset(&mask);
        /* add SIGRTMIN to mask */
        sigaddset(&mask, SIGRTMIN);
        /* add SIGRTMIN+1 to mask */
        sigaddset(&mask, SIGRTMIN+1);

        /* Block SIGRTMIN, SIGRTMIN+1 signal delivery. After return,previous value of signal
         * mask is stored in oldmask*/
        sigprocmask(SIG_BLOCK, &mask, &oldmask);

        /* specify 1 sec timeout */
        tv.tv_sec = 1;
        tv.tv_nsec = 0;
        /* wait for signal delivery. We wait two signals SIGRTMIN and
         * SIGRTMIN+1. Loop will terminate on receiving both of them */
        while(count < 2){
            if ((recv_sig = sigtimedwait(&mask, &siginfo, &tv)) == -1){
                if (errno == EAGAIN){
                    printf("Timed out\n");
                    continue;
                }else{
                    perror("sigtimedwait");
                    return -1;
                }
            }else{
                printf("signal %d with val %d received\n", recv_sig, siginfo.si_value.sival_int);
                count++;
            }
        }

        /* We spacify SA_SIGINFO */
        action.sa_flags = SA_SIGINFO;
        /* clear the mask */
        sigemptyset(&action.sa_mask);
        /* register real-time signal handler */
        action.sa_sigaction = rt_handler;
        if (sigaction(SIGRTMIN, &action, NULL) == -1){
            perror("sigaction");
            return 0;
        }

        /* Wait from SIGRTMIN */
        sigsuspend(&oldmask);
}

int parent(pid_t cpid){
        union sigval value;

        /* send the signal to child */
        sleep(3);
        value.sival_int = 1;
        sigqueue(cpid, SIGRTMIN, value);

        /* send SIGRTMIN+1 to child */
        sleep(3);
        value.sival_int = 2;
        sigqueue(cpid, SIGRTMIN+1, value);

        /* Finally send SIGRTMIN once more */
        sleep(3);
        value.sival_int = 3;
        sigqueue(cpid, SIGRTMIN, value);
}

/* Signal handler for SIGRTMIN
 */
void rt_handler(int signum, siginfo_t *siginfo, void * extra){

    printf("signal %d received. code = %d, value = %d\n", siginfo->si_signo, siginfo->si_code, siginfo->si_int);

}


