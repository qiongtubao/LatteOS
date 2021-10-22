

build: all
	
buildMakefile: 
	cd build_makefile && $(MAKE) -f ./Makefile
	@echo '*********pretreatment编译构建系统结束*************'


all: clean mkdir_release buildMakefile 
	cd initldr && $(MAKE) -f ./Makefile
	$(MAKE) -C release -f hal.mk 
	$(MAKE) -C release -f krl.mk
	$(MAKE) -C release -f drv.mk
	$(MAKE) -C release -f lib.mk
	$(MAKE) -C release -f task.mk
	$(MAKE) -C release -f link.mk
	@echo '*********x86编译构建系统结束*************'

RELEASE_PATH = ./release

mkdir_release:
	mkdir $(RELEASE_PATH) 

clean:
	rm -rf $(RELEASE_PATH) 
	cd build_makefile && $(MAKE) clean
	