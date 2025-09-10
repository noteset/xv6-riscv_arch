#define SBRK_EAGER 1
#define SBRK_LAZY  2

int vmfault(pagetable_t pagetable, uint64 va, int write);