
CC		= gcc
MAKE = make 


all: clean build
	@echo 'pretreatment'

clean:
	$(RM) -f lmkfbuild

build: build_tool buildPrementMk buildPrementMki
	@echo build
	
build_tool:
	gcc ./lmkfbuild.c -o ./lmkfbuild

buildPrementMk:
	cd build_prement_mk && $(MAKE) -f ./Makefile 
	@echo build_prement_mk
	
buildPrementMki:
	cd build_prement_mki && $(MAKE) -f ./Makefile 
	@echo build_prement_mki
	
