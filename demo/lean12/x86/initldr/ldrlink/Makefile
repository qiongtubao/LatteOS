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

INITLDR_DIR := ../initldr/
INITLDRIMH_OBJS :=
INITLDRIMH_LINK :=
INITLDRIMH_OBJS += $(INITLDR_DIR)/imginithead.o $(INITLDR_DIR)/inithead.o $(INITLDR_DIR)/vgastr.o
INITLDRIMH_LINK += $(INITLDRIMH_OBJS)
INITLDRIMH_ELF = initldrimh.elf
INITLDRIMH = initldrimh.bin

INITLDRKRL_OBJS :=
INITLDRKRL_LINK :=
INITLDRKRL_OBJS += $(INITLDR_DIR)/ldrkrl32.o $(INITLDR_DIR)/ldrkrlentry.o $(INITLDR_DIR)/fs.o $(INITLDR_DIR)/chkcpmm.o $(INITLDR_DIR)/graph.o $(INITLDR_DIR)/bstartparm.o
INITLDRKRL_LINK += $(INITLDRKRL_OBJS) $(INITLDR_DIR)/vgastr.o
INITLDRKRL_ELF = initldrkrl.elf
INITLDRKRL = initldrkrl.bin

INITLDRSVE_OBJS :=
INITLDRSVE_LINK :=
INITLDRSVE_OBJS += $(INITLDR_DIR)/realintsve.o
INITLDRSVE_LINK += $(INITLDRSVE_OBJS)
INITLDRSVE_ELF = initldrsve.elf
INITLDRSVE = initldrsve.bin


.PHONY : all everything build_kernel
all: build_kernel 
#INITLDR
build_kernel:everything build_bin
everything : $(INITLDRIMH_ELF) $(INITLDRKRL_ELF) $(INITLDRSVE_ELF)
build_bin:$(INITLDRIMH) $(INITLDRKRL) $(INITLDRSVE)

$(INITLDRIMH_ELF): $(INITLDRIMH_LINK)
	$(LD) $(LDRIMHLDFLAGS) -o $@ $(INITLDRIMH_LINK)

$(INITLDRKRL_ELF): $(INITLDRKRL_LINK)
	$(LD) $(LDRKRLLDFLAGS) -o $@ $(INITLDRKRL_LINK)

$(INITLDRSVE_ELF): $(INITLDRSVE_LINK)
	$(LD) $(LDRSVELDFLAGS) -o $@ $(INITLDRSVE_LINK)

$(INITLDRIMH):$(INITLDRIMH_ELF)
	$(OBJCOPY) $(OJCYFLAGS) $< $@
	@echo 'OBJCOPY -[M] 正在构建...' $@  

$(INITLDRKRL):$(INITLDRKRL_ELF)
	$(OBJCOPY) $(OJCYFLAGS) $< $@
	@echo 'OBJCOPY -[M] 正在构建...' $@ 

$(INITLDRSVE):$(INITLDRSVE_ELF)
	$(OBJCOPY) $(OJCYFLAGS) $< $@
	@echo 'OBJCOPY -[M] 正在构建...' $@ 

clean:
	$(RM) -f *.elf *.map