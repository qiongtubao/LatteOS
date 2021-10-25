

build: all
	
buildMakefile: 
	cd build_makefile && $(MAKE) -f ./Makefile
	@echo '*********pretreatment编译构建系统结束*************'

BUILD_TOOLS_PATH = ./build_tools/

all: clean mkdir_release buildMakefile 
	cd initldr && $(MAKE) -f ./Makefile
	$(MAKE) -C release -f hal.mk 
	$(MAKE) -C release -f krl.mk
	$(MAKE) -C release -f drv.mk
	$(MAKE) -C release -f lib.mk
	$(MAKE) -C release -f task.mk
	$(MAKE) -C release -f link.mk
	$(MAKE) build_eki
	cd vbox && $(MAKE) -f ./Makefile
	@echo '*********x86编译构建系统结束*************'

RELEASE_PATH = ./release/

build_eki:
	cp -rf ./build_tools/* ./release/
	cd ./release && ./lmoskrlimg -m k -lhf initldrimh.bin -o ./Cosmos.eki -f initldrsve.bin  initldrkrl.bin Cosmos.bin font.fnt logo.bmp background.bmp

mkdir_release:
	mkdir $(RELEASE_PATH) 

clean:
	rm -rf $(RELEASE_PATH) 
	cd build_makefile && $(MAKE) clean
	cd vbox && $(MAKE) clean

