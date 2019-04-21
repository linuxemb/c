/* Kernel module header file */
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/sched.h>
#include <linux/stat.h>
#include <asm/io.h>

/* RTAI APIs that we are using are in these headers */
#include <rtai.h>
#include <rtai_sched.h>

/* Timer tick rate in nanosecond */
#define TIMER_TICK  500000    /* 0.5 msec */

/* Task structure for our real-time task */
static RT_TASK hello_task;

static void hello_thread(int dummy);
/* This will be called when the module is loaded */
int init_module(void)
{
   /* ‘period’ of our periodic task*/
   RTIME period;
   RTIME curr;  /* currenttime */
   /* 
    * rt_task_init creates a real-time task in suspended state 
    */   

   rt_task_init(&hello_task,    /* task structure */
                hello_thread,   /* task function  */
                0,              /* argument to task function */
                1024,           /* stack size */
                0,              /* Priority. 
                                   Highest priority –>0, 
                                   Lowest ->RT_LOWEST_PRIORITY
                                 */
                0,              /* task does not use FPU */
                0               /* no signal handler */
              );

  /* The following two timer functions are meant to be called 
   * just once at the start of the whole real-time activity. The 
   * timer started is actually ‘real-time system clock’. The 
   * timer is used by scheduler as a timing reference
   */

  /* Timers can be set in periodic or oneshot mode */
  rt_set_oneshot_mode();

  /* 
   * Timer tick in nanoseconds is converted into internal 
   * countunits 
   */
  period = start_rt_timer(nano2count(TICKS));

  /* Get the current time */
  curr = rt_get_time();
  /* Finally make the task periodic */
  rt_task_make_periodic(&hello_task,  // pointer to task structure
                         curr + 5*period, /* start time of the 
                                             task */                    
                         period      // period of the task
                        );
  return 0;
}

void cleanup_module(void)
{
  /* 
   * Stop the timer, busy wait for some time and finally delete 
   * the task 
   */
  stop_rt_timer();
  rt_busy_sleep(10000000);
  rt_task_delete(&hello_task);
}

static void hello_thread(int dummy)
{
  while(1){
    rt_printk("Hello Real-time world\n");

    /* wait for next period */
    rt_task_wait_period();
  }
}
