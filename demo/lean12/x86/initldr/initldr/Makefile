
MAKEFLAGS = -s
HEADFILE_PATH = ./include/
KRNLBOOT_PATH = ./src/
CCBUILDPATH	= $(KRNLBOOT_PATH)
ASM		= nasm
CC		= gcc
LD		= ld
DD		= dd 
RM		= rm
OBJCOPY = objcopy
OJCYFLAGS = -S -O binary

LDRIMG		= ./lmoskrlimg
ASMBFLAGS	= -I $(HEADFILE_PATH) -f elf
ASMKFLAGS	= -I $(HEADFILE_PATH) -f elf64  #-mregparm=0-finline-functions-mcmodel=medium -mcmodel=large 
BTCFLAGS	= -I $(HEADFILE_PATH) -c -Os -std=c99 -m32 -Wall -Wshadow -W -Wconversion -Wno-sign-conversion  -fno-stack-protector -fomit-frame-pointer -fno-builtin -fno-common  -fno-ident -ffreestanding  -fno-stack-protector -fomit-frame-pointer -Wno-unused-parameter -Wunused-variable
CFLAGS	= -I $(HEADFILE_PATH) -c -O2 -m64  -mcmodel=large -mno-red-zone -std=c99 -Wall -Wshadow -W -Wconversion -Wno-sign-conversion -fno-stack-protector  -fomit-frame-pointer -fno-builtin -fno-common  -fno-ident -ffreestanding  -Wno-unused-parameter -Wunused-variable #-fdata-sections -gstabs+
CPPFLGSLDS	= $(HEADFILE_PATH) -E -P 
CSCFLAGS = -I $(HEADFILE_PATH) -c   -fno-builtin -fno-common -fno-stack-protector -fno-ident -ffreestanding
SCFLAGS	= -I $(HEADFILE_PATH) -S  -std=c99 -fno-ident -Wall -fno-builtin -fno-common -fno-stack-protector
LDFLAGS		= -s -static -T boot.lds -n  -Map boot.map 
FDLDRLDFLG	= -s -Ttext 0 -n  -Map fdldr.map 
LOADERLDFLAGS	= -s -T ldrld.lds -n  -Map hdldr.map  
LDRIMHLDFLAGS = -s -T initldrimh.lds -n  -Map initldrimh.map
LDRKRLLDFLAGS = -s -T initldrkrl.lds -n  -Map initldrkrl.map  
LDRSVELDFLAGS = -s -T initldrsve.lds -n  -Map initldrsve.map 
LDRIMGFLAGS = -m k
KERNELLDFLAGS	= -s -static -T kernelld.lds -n  -Map kernel.map #--entry=_start#-Ttext 0x500 target remote localhost:1234

DBGKERNELLDFLAGS	= -static -T kernelld.lds -n  -Map kernel.map #--entry=_start#-Ttext 0x500 target remote localhost:1234

INITSHELLLDFLAGS = -s -static -T app.lds -n  -Map initshellldr.map


INITLDRIMH_OBJS :=
INITLDRIMH_LINK :=
INITLDRIMH_OBJS += imginithead.o inithead.o vgastr.o
INITLDRIMH_LINK += $(INITLDRIMH_OBJS)
INITLDRIMH_ELF = initldrimh.elf
INITLDRIMH = initldrimh.bin

INITLDRKRL_OBJS :=
INITLDRKRL_LINK :=
INITLDRKRL_OBJS += ldrkrl32.o ldrkrlentry.o fs.o chkcpmm.o graph.o bstartparm.o
INITLDRKRL_LINK += $(INITLDRKRL_OBJS) vgastr.o
INITLDRKRL_ELF = initldrkrl.elf
INITLDRKRL = initldrkrl.bin

INITLDRSVE_OBJS :=
INITLDRSVE_LINK :=
INITLDRSVE_OBJS += realintsve.o
INITLDRSVE_LINK += $(INITLDRSVE_OBJS)
INITLDRSVE_ELF = initldrsve.elf
INITLDRSVE = initldrsve.bin

.PHONY : all everything  build_kernel

all: build_kernel print

print:
	@echo '*********构建完成*************'


build_kernel:everything
	
everything : $(INITLDRIMH_OBJS) $(INITLDRKRL_OBJS) $(INITLDRSVE_OBJS)


CCSTR		= 	'CC -[M] 正在构建... '$<
PRINTCSTR 	=	@echo $(CCSTR) 

%.o : $(CCBUILDPATH)%.asm
	$(ASM) $(ASMBFLAGS) -o $@ $<
	@echo 'AS -[M] 正在构建...' $<
	
%.o : $(CCBUILDPATH)%.c
	$(CC) $(BTCFLAGS) -o $@ $<
	$(PRINTCSTR) 

%.lds : $(CCBUILDPATH)%.S
	$(CC) $(CPPFLGSLDS) -o $@ $<
	$(PRINTCSTR)

%.mh : $(CCBUILDPATH)%.S
	$(CC) $(CPPFLGSLDS) -o $@ $<
	$(PRINTCSTR)

%.lib : $(CCBUILDPATH)%.c
	$(CC) $(CFLAGS) -o $@ $<
	$(PRINTCSTR)

%.lib : $(CCBUILDPATH)%.asm
	$(ASM) $(ASMKFLAGS) -o $@ $<
	@echo 'AS -[M] 正在构建...' $< 

clean:
	$(RM) -f *.o
