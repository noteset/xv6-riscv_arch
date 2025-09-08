#include "types.h"


struct proc_info {
    int pid;
    char name[16];
    char state[16];
    uint64 sz;
};
