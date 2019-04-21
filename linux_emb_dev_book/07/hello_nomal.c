#include <stdio.h>

/*
 * define macros for using gcc section attribute
 */

/*
 * Linker is very kind. It has defined these symbols for us
 */

/*
 * This should go in real_bss section
 */
char rt_bss[100];
/*
 * This should go in real_data section
 */
char rt_data[]  = "Hello Real World";


/*
 * This function should go in real_text section
 */
void  hello_rt_world(void){
        printf("%s", rt_data);
//        memset(rt_bss, 0xff, sizeof(rt_bss));
        return ;
}

void hello_world(void) {
        printf("hello world");
        return;
}

int main(){
//	rt_lockall();
	hello_world();
	hello_rt_world();
	return 0;
}

