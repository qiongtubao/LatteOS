
dd bs=512 if=/dev/zero of=hd.img count=204800

;bs:表示块大小，这里是512字节
;if：表示输入文件，/dev/zero就是Linux下专门返回0数据的设备文件，读取它就返回0
;of：表示输出文件，即我们的硬盘文件。
;count：表示输出多少块


sudo losetup /dev/loop8 hd.img

sudo mkfs.ext4 -q /dev/loop8 

mkdir hdisk

sudo mount -o loop ./hd.img ./hdisk

sudo mkdir ./hdisk/boot

sudo grub-install --boot-directory=./hdisk/boot --force --allow-floppy /dev/loop8 --target=i386-pc




#第一步 SATA的硬盘其控制器是intelAHCI
VBoxManage storagectl Cosmos --name "SATA" --add sata --controller IntelAhci --portcount 1
#第二步
VBoxManage closemedium disk ./hd.vdi #删除虚拟硬盘UUID并重新分配
#将虚拟硬盘挂到虚拟机的硬盘控制器
VBoxManage storageattach HelloOS --storagectl "SATA" --port 1 --device 0 --type hdd --medium ./hd.vdi


