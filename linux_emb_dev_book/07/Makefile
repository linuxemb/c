LDFLAGS = -lrt -lpthread

#all: aio_cp hello hello_rt mlock mqueue sched sched_rr sem shm signal timer
all: aio_cp hello hello_rt mlock sched sched_rr sem shm signal timer

aio_cp: aio_cp.o

hello: hello.o

hello_rt: hello_main.o hello_rt_bss.o hello_rt_data.o hello_rt_world.o hello_world.o

mlock: mlock.o

#mqueue: mqueue-1.o mqueue-2.o #Requires kernel 2.6.6+

sched: sched.o

sched_rr: sched_rr.o

sem: sem.o

shm: shm.o

signal: signal.o

timer: timer.o

clean:
	rm -f *.o aio_cp hello hello_rt mlock mqueue sched sched_rr sem shm signal timer
