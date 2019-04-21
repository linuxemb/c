#include <stdio.h>

extern void hello_world(void);
extern void hello_rt_world(void);

/*
 * We are defining these symbols in linker script
 */
extern unsigned long __start_rt_text, __end_rt_text;
extern unsigned long __start_rt_data, __end_rt_data;
extern unsigned long __start_rt_bss, __end_rt_bss;

/*
 * This function locks all the real-time function and data 
 * in memory
 */
void rt_lockall(void){
	mlock(&__start_rt_text, &__end_rt_text - &__start_rt_text);
	mlock(&__start_rt_data, &__end_rt_data - &__start_rt_data);
	mlock(&__start_rt_bss, &__end_rt_bss - &__start_rt_bss);
}

int main(){

	/*
	 * First step is to do memory locking
	 */
	rt_lockall();
	hello_world();
	/*
	 * This is our rt function
	 */
	hello_rt_world();
	return 0;
}

