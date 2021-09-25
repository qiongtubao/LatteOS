imginithead.asm GRUB头汇编部分
inithead.c GRUB头的C语言部分 用于放置2级引导到指定内存中
realintsve.asm 实现调用BIOS中断的功能
ldrkl32.asm   二级引导起核心入口汇编部分
ldrkrlentry.c 二级引导器核心入口
bstartparm.c 实现收集机器信息建立页面数据
chkcpmm.c  实现检查CPU 工作模式和内存视图
fs.c       实现解析映像文件的功能
graph.c    实现切换显卡图形模式
vgastr.c   实现字符串输出



Makfile(all)
    Makefile.x86()
        initldr
            build
                initldr.mk
                    krnlbuidcmd.mh
                    ldrobjs.mh
                        imginithead.o inithead.o vgastr.o
                    krnlbuidrule.mh