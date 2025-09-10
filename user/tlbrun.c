#include "kernel/types.h"
#include "user/user.h"

#define PAGESIZE 4096
#define MAXPAGES 1024
int main(int argc, char *argv[]) {
int jump = PAGESIZE / sizeof(int);
//int i,t;
printf("PageCount\tTrials\tTicks\tPageFaults\n");
for (int numpages = 1; numpages <= MAXPAGES; numpages *= 2)
{
int trials = 5000000;
int faults_before = getpagefaults(); 
uint start = uptime();
int *arr = (int *) sbrk(numpages * PAGESIZE);
if (arr == (void *) -1) {
printf("sbrk failed for %d pages\n", numpages);
exit(1);
}
for (int t = 0; t < trials; t++) {
for (int i = 0; i < (numpages/2) * jump ; i += jump)
{

}
}
uint end = uptime();
int faults_after = getpagefaults();
printf("%d\t\t%d\t%d\t%d\n",numpages, trials, end - start,
faults_after - faults_before);
}
exit(0);
}
