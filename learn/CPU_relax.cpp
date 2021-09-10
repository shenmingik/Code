

#define CPU_RELAX asm volatile("pause" ::: "memory")

/*
 * "pause" ::: "memory":它是mm_pause()和编译内存屏障
 * mm_pause():提示CPU空转一会儿，一般用于多核场景下
 * memory:内存屏障，保证编译器不会因为优化将一些指令的顺序颠倒
*/