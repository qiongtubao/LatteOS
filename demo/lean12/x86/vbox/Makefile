MAKEFLAGS = -sR
.PHONY : all moutvmhd clean idectrnul crtidectr startvm tranvdi moutraw

all:  hd_img moutraw tranvdi idectrnul crtidectr moutvmhd startvm

#tranvdi idectrnul crtidectr moutvmhd startvm

loop:
	echo `losetup -f`

hd_img:
	dd bs=512 if=/dev/zero of=hd.img count=204800
	sudo losetup  /dev/loop8 hd.img
	sudo mkfs.ext4 -q /dev/loop8
	sudo mkdir ./hdisk
	echo 'create img'



# 第一步挂载虚拟硬盘文件为loop0回环设备
# sudo losetup /dev/loop0 hd.img
# sudo mount -o loop ./hd.img ./hdisk/ ;挂载硬盘文件
# 第二步安装GRUB
# sudo grub-install --boot-directory=./hdisk/boot/ --force --allow-floppy /dev/loop0
# ；--boot-directory 指向先前我们在虚拟硬盘中建立的boot目录。
# ；--force --allow-floppy ：指向我们的虚拟硬盘设备文件/dev/loop0


# sudo cp /home/dong/Documents/learn/cosmos-master/lesson13/Cosmos/release/Cosmos.eki ./hdisk/boot/
# sudo cp ../release/Cosmos.eki ./hdisk/boot/
#sudo cp /home/dong/Documents/learn/cosmos-master/lesson13/Cosmos/Cosmos.eki ./hdisk/boot/
moutraw:
	sudo mount -o loop ./hd.img ./hdisk/
	sudo mkdir ./hdisk/boot/
	sudo grub-install --boot-directory=./hdisk/boot/ --force --allow-floppy /dev/loop8 --target=i386-pc
	sudo cp ./grub.cfg ./hdisk/boot/grub/grub.cfg
	sudo cp ../release/Cosmos.eki ./hdisk/boot/
	sudo umount ./hdisk/
	echo 'add Cosmos.eki'

clean:
	sudo losetup -d /dev/loop8
	sudo rm -rf hd.img hd.vdi hdisk 
	echo 'clean over'

tranvdi:
	VBoxManage convertfromraw ./hd.img --format VDI ./hd.vdi
	echo 'create vdi'

idectrnul:
	VBoxManage storagectl Cosmos --name "IDE" --remove 

crtidectr:
	VBoxManage storagectl Cosmos --name "IDE" --add ide --controller PIIX4

startvm:
	VBoxManage startvm Cosmos

moutvmhd:
	VBoxManage closemedium disk ./hd.vdi
	VBoxManage storageattach Cosmos --storagectl "IDE" --port 0 --device 0 --type hdd --medium ./hd.vdi
	echo 'mountvmhd'

