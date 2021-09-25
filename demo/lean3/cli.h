

void hal_cli() 
{
    __asm__ __volatile__("cli": : : "memory");
}

void hal_sti() 
{
    __asm__ __volatile__("sti": : : "memory");
}

void foo() 
{
    hal_cli();
    //doing...
    hal_sti();
}

void bar() 
{
    hal_cli();
    //doing...
    hal_sti();
}


typedef u32_t cpuflg_t;
static inline void hal_save_flags_cli(cpuflg_t* flags) {
    __asm__ __volatile__(
        "pushfl \t\n"
        "cli    \t\n"
        "popl %0 \t\n"
        : "=m"(*flags)
        : 
        : "memory"
    );
}

static inline void hal_restore_flags_sti(cpuflg_t* flags) {
    __asm__ __volatile__ (
        "pushl %0 \t\n"
        "popfl \t\n"
        :
        : "m"(*flags)
        : "memory"
    );
}


typedef struct 
{
    volatile u32_t lock;

} spinlock_t;

static inline void x86_spin_lock_init(spinlock_t * lock) 
{
    lock->lock = 0;
}

static inline void x86_spin_lock(spinlock_t *lock) {
    __asm__ __volatile__ (
        "1: \n"
        "lock: xchg %0, %1 \n"
        "cmpl $0, %0 \n"
        "jnz  2f \n"
        "jmp 3f \n"
        "2:     \n"
        "cmpl $0, %1  \n"
        "jne  2b        \n" //自旋 一直查到数据变化为0 重新执行抢锁
        "jmp  1b        \n"
        "3: \n" :
        : "r"(1), "m"(*lock));
}

static inline void x86_spin_unlock(spinlock_t *lock)
{
    __asm__ __volatile__(
        "movl  $0, %0\n"
        :
        : "m"(*lock));
}



#define SEM_FLG_MUTEX 0
#define SEM_FLG_MULTI 1
#define SEM_MUTEX_ONE_LOCK 1
#define SEM_MULTI_LOCK 0
//等待链数据结构，用于挂载等待代码执行流（线程）的结构，里面有用于挂载代码执行流的链表和计数器变量，这里我们先不深入研究这个数据结构。
typedef struct s_KWLST
{
    spinlock_t wl_lock;
    uint_t wl_tdnr;
    list_h_t wl_list;
} kwlst_t;

typedef struct s_SEM
{
    spinlock_t sem_lock;
    uint_t sem_flg;
    sint_t sem_count;
    kwlst_t sem_waitlst;
} sem_t;


