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
    while(1) {
        usleep(1000);
        idx = (rand() * rand()) % size;
        char ch = 'a' + idx % 26;
        //printf("\ridx=%lu", idx);
        mbuf[idx] = ch; 
    }
}

int main(int argc, char* argv[]) {
    printf("Usage:%s <fraction[0.2(20%%) default]>\n", argv[0]);

    float frac = 0.2f;
    if(argc > 1) {
        frac = atof(argv[1]);
        if(frac > 1.0) {
            frac = 1.0f;
        }
        return -1;
    }

    srand(time(NULL));
    unsigned long long total = total_memory();
    int mb = 1024*1024;
    printf("total.memory=%llu MB\n", total/mb);

    size_t needed = total * frac;
    if(needed > total) {
        needed = total;
    }
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

