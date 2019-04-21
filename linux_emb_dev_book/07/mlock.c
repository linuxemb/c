#include <sys/mman.h>
#include <unistd.h>

#define RT_BUFSIZE 200
int main(){

	/*
	 * rt_buffer should be locked in memory
	 */
	char *rt_buffer = (char *)malloc(RT_BUFSIZE);
	unsigned long pagesize, offset;

	/*
	 * In Linux, you need not page align the address, Kernel does that
	 * for you. But POSIX mandates page alignment by application before calling
	 * mlock. Following increases portability
	 */
	pagesize = sysconf(_SC_PAGESIZE);
	offset = (unsigned long) rt_buffer % pagesize;
	/*
	 * Lock rt_buffer in memory
	 */
	if (mlock(rt_buffer - offset, RT_BUFSIZE + offset) != 0){
		perror("cannot mlock");
		return 0;
	}
	/*
	 * unlock rt_buffer
	 */
	if (munlock(rt_buffer - offset, RT_BUFSIZE + offset) != 0){
		perror("cannot mulock");
		return 0;
	}
	/*
	 * Lock current process memory as well as all the future
	 * memory allocations.
	 * MCL_CURRENT - Lock all the pages that are currently mapped in 
	 *		 process address space
	 * MCL_FUTURE  -  Lock all the future mappings as well.
	 */
	if (mlockall(MCL_CURRENT | MCL_FUTURE) != 0){
		perror("cannot mlockall");
		return 0;
	}

	/*
	 * New memory allocations will be locked
	 */
	rt_buffer = (char *)realloc(rt_buffer , 2*RT_BUFSIZE);
	/*
	 * Unlock any memory that was locked either by mlock or 
	 * by mlockall
	 */
	if (munlockall() != 0){
		perror("cannot munlock");
		return 0;
	}

	return 0;
}	
		
