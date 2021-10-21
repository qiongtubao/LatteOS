KERNELCE_PATH	= ./
HEADFILE_PATH = -I ../../include
# # HEADFILE_PATH = -I ../include/script/ -I ../include/ -I ../include/bastypeinc -I ../include/halinc
CCBUILDPATH	= $(KERNELCE_PATH)
LMKFBUID = ../lmkfbuild
CPPFLGSLDS	= $(HEADFILE_PATH) -E -P 

PREMENTMKI_OBJS = krnlobjs.mki cosmoslink.lds krnlbuidcmd.mki krnlbuidrule.mki hal.mki krl.mki drv.mki drv.mki lib.mki task.mki link.mki
# PREMENTMK_OBJS = krnlobjs.mk  krnlbuidcmd.mk krnlbuidrule.mk hal.mk krl.mk drv.mk lib.mk task.mk link.mk


build_kernel:  everything

everything : $(PREMENTMKI_OBJS) 

everymk : $(PREMENTMK_OBJS)

clean:
	$(RM) -f *.mki


%.lds : $(CCBUILDPATH)%.S
	$(CC) $(CPPFLGSLDS) -o $(BUILDPATH)$@ $<
	$(PRINTCSTR)

%.mkh : $(CCBUILDPATH)%.S
	$(CC) $(CPPFLGSLDS) -o $(BUILDPATH)$@ $<
	$(PRINTCSTR)

BUILDPATH = ../../release/

%.mki : $(CCBUILDPATH)%.S
	$(CC) $(CPPFLGSLDS) -o $(BUILDPATH)$@ $<
	$(PRINTCSTR)
