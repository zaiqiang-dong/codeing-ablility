#include <sys/time.h>
#include <stdio.h>

long get_time_usec(){
	struct timeval tv;
    gettimeofday(&tv, NULL);
	return  tv.tv_sec * 1000000 + tv.tv_usec;
}
