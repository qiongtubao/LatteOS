

build: all
	
pretreatment: 
	cd pretreatment && $(MAKE) -f ./Makefile
	@echo '*********pretreatment编译构建系统结束*************'


all: pretreatment 
	cd pretreatment && $(MAKE) -f ./Makefile
	cd initldr && $(MAKE) -f ./Makefile
	@echo '*********x86编译构建系统结束*************'

clean:
	cd pretreatment && $(MAKE) clean