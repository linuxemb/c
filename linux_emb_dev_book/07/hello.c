#include <stdio.h>

/*
 * define macros for using gcc section attribute
 */
#define __rt_text __attribute__ ((__section__ ("real_text")))
#define __rt_data __attribute__ ((__section__ ("real_data")))
#define __rt_bss  __attribute__ ((__section__ ("real_bss")))

/*
 * Linker is very kind. It has defined these symbols for us
 */
extern unsigned long __start_real_text, __stop_real_text;
extern unsigned long __start_real_data, __stop_real_data;
extern unsigned long __start_real_bss, __stop_real_bss;

/*
 * This should go in real_bss section
 */
char rt_bss[100] __rt_bss;
/*
 * This should go in real_data section
 */
char rt_data[] __rt_data = "Hello Real World";

void rt_lockall(void){
	mlock(&__start_real_text, &__stop_real_text - &__start_real_text);
	mlock(&__start_real_data, &__stop_real_data - &__start_real_data);
	mlock(&__start_real_bss, &__stop_real_bss - &__start_real_bss);
}

/*
 * This function should go in real_text section
 */
void __rt_text hello_rt_world(void){
        printf("%s", rt_data);
        memset(rt_bss, 0xff, sizeof(rt_bss));
        return ;
}

void hello_world(void) {
        printf("hello world");
        return;
}

int main(){
	rt_lockall();
	hello_world();
	hello_rt_world();
	return 0;
}

