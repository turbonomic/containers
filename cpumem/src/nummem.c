#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

unsigned long long total_memory() {
    long long pages = sysconf(_SC_PHYS_PAGES);
    long long page_size = sysconf(_SC_PAGE_SIZE);

    return (pages * page_size);
}

void use_it(char *mbuf, size_t size) {
    unsigned long idx = 0;
    for(idx = 0; idx < size; idx ++) {
        mbuf[idx] = 3;
    }
    printf("%lu bytes memory is in use.\n", size);
    while(1) {
        usleep(1000);
        idx = (rand() * rand()) % size;
        char ch = 'a' + idx % 26;
        //printf("\ridx=%lu", idx);
        mbuf[idx] = ch; 
    }
}

int main(int argc, char* argv[]) {
    setbuf(stdout, NULL);
    printf("Usage:%s <Memory in MB] (default=200MB)>\n", argv[0]);
    size_t default_num = 200;
    if(argc > 1) {
        default_num = atoi(argv[1]);
        if(default_num < 1) {
            default_num = 1;
        }
    }

    srand(time(NULL));
    unsigned long long total = total_memory();
    int mb = 1024*1024;
    printf("total.memory=%llu MB\n", total/mb);

    size_t needed = default_num * mb;
    char *mbuf = (char*)malloc(needed);
    if(mbuf == NULL) {
        printf("failed to alloc %lu MB memory.\n", needed);
        return -1;
    }

    printf("total:%llu MB memory, requested: %lu MB\n", total/mb, needed/mb);
    
    use_it(mbuf, needed);

    free(mbuf);
    return 0;
}

