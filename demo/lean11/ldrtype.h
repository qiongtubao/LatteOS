
typedef struct s_MACHBSTART
{
    u64_t   mb_krlinitstack;//内核栈地址
    u64_t   mb_krlitstacksz;//内核栈大小
    u64_t   mb_imgpadr;//操作系统映像
    u64_t   mb_imgsz;//操作系统映像大小
    u64_t   mb_bfontpadr;//操作系统字体地址
    u64_t   mb_bfontsz;//操作系统字体大小
    u64_t   mb_fvrmphyadr;//机器显存地址
    u64_t   mb_fvrmsz;//机器显存大小
    u64_t   mb_cpumode;//机器CPU工作模式
    u64_t   mb_memsz;//机器内存大小
    u64_t   mb_e820padr;//机器e820数组地址
    u64_t   mb_e820nr;//机器e820数组元素个数
    u64_t   mb_e820sz;//机器e820数组大小
    //……
    u64_t   mb_pml4padr;//机器页表数据地址
    u64_t   mb_subpageslen;//机器页表个数
    u64_t   mb_kpmapphymemsz;//操作系统映射空间大小
    //……
    graph_t mb_ghparm;//图形信息
}__attribute__((packed)) machbstart_t;