###################################################################
#		主控自动化编译配置文件 Makefile
#				彭东  
###################################################################

MAKEFLAGS = -sR

MKDIR = mkdir
RMDIR = rmdir
CP = cp
CD = cd
DD = dd
RM = rm

BUILD_PATH = ./build
MAKE = make
INITLDRMFLGS = -C $(BUILD_PATH) -f initldr.mk
INITLDRLINKMFLGS = -C $(BUILD_PATH) -f ldrlink.mk
SRCFILE = $(BOOTEXCIMG) $(KRNLEXCIMG) $(LDEREXCIMG) $(SHELEXCIMG)
RSRCFILE = $(BOOTEXCIMG) $(KRNLEXCIMG) $(LDEREXCIMG) $(SHELEXCIMG) $(VDIFNAME) $(VMDKFNAME)
.PHONY : build print clean all

all: build_initldr build_ldrlink

build: clean initldr ldrlink print

build_initldr:
	cd initldr && $(MAKE) -f ./Makefile

build_ldrlink:
	cd ldrlink && $(MAKE) -f ./Makefile

clean_initldr:
	cd initldr && $(MAKE) clean

clean_ldrlink:
	cd ldrlink && $(MAKE) clean


clean: clean_initldr clean_ldrlink
	@echo 'Initldr:清理全部已构建文件... ^_^'
	

print:
	@echo '*********正在开始编译构建系统*************'




