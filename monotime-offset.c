#include <stddef.h>
#include <stdio.h>
#include <time.h>
#include <sys/sysinfo.h>

int main(void){
    struct timespec monotime;
    clock_gettime(CLOCK_MONOTONIC, &monotime);

    struct timespec realtime;
    clock_gettime(CLOCK_REALTIME, &realtime);

    long seconds = realtime.tv_sec - monotime.tv_sec;
    long nanos = realtime.tv_nsec - monotime.tv_nsec;

    if (nanos < 0) {
        --seconds;
        nanos += 1000000000l;
    }

    printf("%ld.%09ld\n", seconds, nanos);

    return 0;
}
