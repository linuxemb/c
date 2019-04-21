/* Headers that define scheduling and memory locking functions */
#include <sys/mman.h>
#include <sched.h>

/* RTAI headers */
#include <rtai.h>
#include <rtai_sched.h>
#include "rtai_lxrt.h"

#define TICK_TIME 500000

int main(){

  RT_TASK *task;
  RTIME period;
  struct sched_param sched;
  int count;

  /* Create a SCHED_FIFO task with max priority */
  sched.sched_priority = sched_get_priority_max(SCHED_FIFO);
  if (sched_setscheduler(0, SCHED_FIFO, &sched) != 0){
    perror("sched_setscheduler failed\n");
    exit(1);
  }

  /* Lock all the current and future memory allocations */
  mlockall(MCL_CURRENT | MCL_FUTURE);

  /* ---- module_init ---- */

  /* rt_task_init creates a real-time proxy in kernel for this   
   * task. All the RTAI APIs will be executed by the proxy under 
   * RTAIscheduler on the behalf of this task. Please note that 
   * the first argument is a unsigned long. A string can be 
   * converted to unsigned long using nam2num function. 
   */
  if (!(task = rt_task_init(nam2num("hello"), 0,0,0))) {
    printf("LXRT task creation failed\n");
    exit(2);
  }

  rt_set_oneshot_mode();
  period = start_rt_timer(nano2count(TICK_TIME));
   /* Finally make the task periodic */
  rt_task_make_periodic(task, rt_get_time() + 5*period, period);

  /* ---- Main job of our real-time task ---- */

  count = 100;
  while(count--) {
    rt_printk("Hello Real-time World\n");
    rt_task_wait_period();
  }

  /* ---- cleanup_module ---- */

  stop_rt_timer();
  rt_busy_sleep(10000000);
  rt_task_delete(task);
}

