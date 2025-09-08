#ifndef PROCINFO_H
#define PROCINFO_H

#include "kernel/types.h"   // for uint64

struct proc_info {
    int pid;
    char name[16];
    char state[16];
    uint64 sz;
};

#endif

