#include <stdio.h>
#include <mqueue.h>

#define QUEUE_NAME  "/my_queue"
#define PRIORITY     1
#define SIZE        256

int main(){

    mqd_t ds;
    char new_text[SIZE];
    struct mq_attr attr, old_attr;
    int prio;


    /* Open "/my_queue" for sending and receiving. No blocking when receive a message(O_NONBLOCK).
     * The queue file permissions are set rw for owner and nothing for group/others. 
     */
    if ((ds = mq_open(QUEUE_NAME,  O_RDWR | O_NONBLOCK, 0600, NULL)) == (mqd_t)-1){
        perror("Creating queue error");
        return -1;
    }


    /* Change to blocking receive. (This is done to demonstrate usage of mq_setattr and mq_getattr functions. To put the queue in blocking mode you can also call mq_open above without O_NONBLOCK).
     * Remember that mq_setattr cannot be used to changes values of message queue parameters
     * mq_maxmsg, mq_msgsize etc. It can only be used to change mq_flags field of mq_attr struct.
     * mq_flags is one of O_NONBLOCK, O_RDWR etc.
     */ 
    attr.mq_flags = 0; /* set !O_NONBLOCK */
    if (mq_setattr(ds, &attr, NULL)){
        perror("mq_setattr");
        return -1;
    }

    /* Here we will convince ourself that O_NONBLOCK is not set.Infact this function
     * also populates message queue parameters in structure old_addr */
    if (mq_getattr(ds, &old_attr))
    {
        perror("mq_getattr");
        return -1;
    }
    if (!(old_attr.mq_flags & O_NONBLOCK))
	printf("O_NONBLOCK not set\n");

    /* Now receive the message from queue. This is a blocking call. Priority of message
     * received is stored in prio.The function receives the oldest of the highest pri-
     * ority message(s) from the message queue. If the size of the buffer, specified
     * by the msg_len argument, is less than the  mq_msgsize attribute of the message queue
     * the function shall fail and return an error
     */
   if (mq_receive(ds, new_text, SIZE, &prio) == -1){
	perror("canno receive");
	return -1;
   }

   printf("Message: %s, prio = %d\n", new_text, prio);

    /* Close queue... */
    if (mq_close(ds) == -1)
        perror("Closing queue error");

    /* ...and finally unlink it. After unlink message queue is removed from system. */
    if (mq_unlink(QUEUE_NAME) == -1)
       perror("Removing queue error");

    return 0;
}

