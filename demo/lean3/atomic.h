

typedef struct s_ATOMIC {
    volatile s32_t a_count;
} atomic_t;

static inline s32_t atomic_read(const atomic_t *v) {
    return (*(volatile u32_t*)&(v)->a_count);
}

static inline void atomic_write(atomic_t *v, int i) {
    v->a_count = i;
}
//"lock;" "addl %1,%0" 是汇编指令部分，%1,%0是占位符，它表示输出、输入列表中变量或表态式，占位符的数字从输出部分开始依次增加，这些变量或者表态式会被GCC处理成寄存器、内存、立即数放在指令中。 
//: "+m" (v->a_count) 是输出列表部分，“+m”表示(v->a_count)和内存地址关联
//: "ir" (i) 是输入列表部分，“ir” 表示i是和立即数或者寄存器关联
static inline void atomic_add(int i, atomic_t *v) {
    __asm__ __volatile__("lock;" "addl %1,%0" 
        : "+m" (v->a_count)
        : "ir" (i));
}

static inline void atomic_sub(int i, atomic_t *v) {
    __asm__ __volatile__("lock;" "subl %1,%0" 
        : "+m" (v->a_count)
        : "ir" (i));
}

//原子加1
static inline void atomic_inc(atomic_t *v)
{ 
    __asm__ __volatile__("lock;" "incl %0" 
    : "+m" (v->a_count));
}
//原子减1
static inline void atomic_dec(atomic_t *v)
{ 
    __asm__ __volatile__("lock;" "decl %0" 
    : "+m" (v->a_count));
}