// user/prioritytest.c
#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"


int
main(int argc, char *argv[])
{
  int pid1, pid2;
  printf("Starting priority scheduling test...\n");

  pid1 = fork();
  if(pid1 == 0){
    setpriority(10); // higher priority
    printf("Child 1 (pid %d) with high priority started.\n", getpid());
    for (int i = 0; i < 50000000; i++) {} // Busy loop
    printf("Child 1 finished.\n");
    exit(0);
  }

  pid2 = fork();
  if(pid2 == 0){
    setpriority(50); // lower priority
    printf("Child 2 (pid %d) with low priority started.\n", getpid());
    for (int i = 0; i < 50000000; i++) {} // Busy loop
    printf("Child 2 finished.\n");
    exit(0);
  }

  wait(0);
  wait(0);
  printf("Priority scheduling test complete.\n");
  exit(0);
}
