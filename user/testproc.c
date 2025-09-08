#include "kernel/types.h"
#include "user/user.h"

int main(void) {
    int num_children = 5;

    for(int i = 0; i < num_children; i++) {
        int pid = fork();
        if(pid < 0) {
            printf("Fork failed\n");
            exit(1);
        }
        if(pid == 0) {
            // Child just spins forever
            while(1);
        } else {
            // Parent prints info
            printf("Child process %d started with PID %d\n", i+1, pid);
        }
    }

    exit(0);
}

