#include "kernel/types.h"
#include "user/user.h"

#define PAGESIZE 4096
#define MAXPAGES 1024

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Usage: tlbtest <numpages> <trials>\n");
        exit(1);
    }

    int numpages = atoi(argv[1]);
    int trials = atoi(argv[2]);

    if (numpages < 1 || numpages > MAXPAGES) {
        printf("numpages out of range (1..%d)\n", MAXPAGES);
        exit(1);
    }

    int jump = PAGESIZE / sizeof(int);
    //int i,t;

    int *arr = (int *)sbrk(numpages * PAGESIZE);
    if (arr == (void*)-1) {
        printf("sbrk failed for %d pages\n", numpages);
        exit(1);
    }

    int pf_before = getpagefaults();

    uint start_ticks = uptime();

    for (int t = 0; t < trials; t++) {
        for (int i = 0; i < (numpages / 2) * jump; i += jump) {
            arr[i] += 1;
        }
    }

    uint end_ticks = uptime();
    int pf_after = getpagefaults();

    printf("Pages: %d\tTrials: %d\tTicks: %d\tPageFaults: %d\n",
           numpages, trials, end_ticks - start_ticks, pf_after - pf_before);

    exit(0);
}
