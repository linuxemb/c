#include <stdio.h>

/*
 * This is a real-time function
 */
void hello_rt_world(void){
	extern char rt_data[],rt_bss[100];
	/*
	 * operating on rt_data
	 */
	printf("%s", rt_data);
	/*
	 * operating on rt_bss
	 */
	memset(rt_bss, 0xff, sizeof(rt_bss));
	return ;
}
