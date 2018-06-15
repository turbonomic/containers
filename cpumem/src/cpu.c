#include <sys/time.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

typedef long long int int64;

int64 get_tickt(){
    struct timeval now;
    gettimeofday(&now, NULL);
    int64 sec = now.tv_sec;
    int64 usec = now.tv_usec;
    return sec*1000000 + usec;
}

void do_it(float usage) {
    int total = 30000;
    int busy = (int)(total*(usage+0.15)/100.0);
    int idle = total - busy;
    if(idle < 0) {
        idle = 1;
    }
    while(1) {
        int64 start = get_tickt(); 
        while(get_tickt() < (start + busy)) {
            ;
        }
        usleep(idle); 
    } 
}

void do_sleep() {
    int idle = 1024;
    printf("In long sleep, cpu.usage will be 0.0\n");
    while(1) {
        sleep(idle);
    }
}

int main(int argc, char* argv[]) {
    float usage = 10;
    if(argc > 1) {
        usage = atof(argv[1]);
    }

    if (usage > 100) {
        usage = 100;
    }

    printf("Expected CPU usage is: %.2f%%\n", usage);

    if((int)usage < 1) {
        do_sleep();
    }
    
    do_it(usage);
    return 0;
}
