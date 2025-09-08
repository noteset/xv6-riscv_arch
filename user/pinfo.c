#include "kernel/types.h"
#include "user/user.h"
#include "procinfo.h"

int main(int argc, char *argv[]) {
    if(argc != 2){
        printf("Usage: pinfo <pid>\n");
        exit(1);
    }

    int pid = atoi(argv[1]);
    struct proc_info info;

    if(pinfo(pid, &info) < 0){
        printf("Invalid PID %d\n", pid);
        exit(1);
    }

    printf("PID: %d\n", info.pid);
    printf("Name: %s\n", info.name);
    printf("State: %s\n", info.state);
    printf("Size: %ld\n", info.sz);

    exit(0);
}
