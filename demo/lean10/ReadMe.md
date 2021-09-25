
1. dd bs=512 if=/dev/zero of=hd.img count=204800

;bs:表示块大小，这里是512字节
;if：表示输入文件，/dev/zero就是Linux下专门返回0数据的设备文件，读取它就返回0
;of：表示输出文件，即我们的硬盘文件。
;count：表示输出多少块

2. ls -ll /dev/loop* 找到没有创建的loop就可以使用
    比如当前我查看到的已经有了loop8 
    那么我就创建执行
    sudo losetup /dev/loop9 hd.img
3. 格式化设备 设置ext4文件系统
   sudo mkfs.ext4 -q /dev/loop9 
4. 先mkdir 创建一个 hdisk
sudo mount -o loop ./hd.img ./hdisk/ ;挂载硬盘文件
sudo mkdir ./hdisk/boot/ ;建立boot目录
如果使用虚拟机自己生成的硬件文件 mount就无法识别 我们就不好创建文件夹和写入文件了

5. sudo grub-install --boot-directory=./hdisk/boot/ --force --allow-floppy /dev/loop9
    a.第一个报错
        正在为 x86_64-efi 平台进行安装。
        grub-install：错误： 无法找到 EFI 目录.
        解决方案：
            sudo grub-install --target i386-pc --boot-directory hdisk/boot --force --allow-floppy /dev/loop9 
    b. /usr/lib/grub/i386-pc/modinfo.sh 不存在。请指定 --target 或 --directory.
        解决方案：
            1.cd /tmp
            2.sudo apt-get download grub-pc-bin
                查看下载的deb
                    grub-pc-bin_2.04-1ubuntu26.13_amd64.deb
            3.dpkg-deb -R grub-pc-bin_2.04-1ubuntu26.13_amd64.deb grub/
            4.sudo mv grub/usr/lib/grub/i386-pc /usr/lib/grub 
    c.最终执行成功后
        正在为 i386-pc 平台进行安装。
        grub-install：警告： 文件系统“ext2”不支持嵌入.
        grub-install：警告： 无法嵌入。在此次安装中 GRUB 只能通过使用块列表安装。但是块列表是不可信赖的，不推荐使用。.
        安装完成。没有报告错误。
sudo vim ./hdisk/boot/grub/grub.cfg

    menuentry 'HelloOS' {
    insmod part_msdos
    insmod ext2
    set root='hd0,msdos1' #发现VM 报错的时候把这里修改成hd0 我们的硬盘只有一个分区所以是'hd0,msdos1'
    multiboot2 /boot/HelloOS.eki #加载boot目录下的HelloOS.eki文件
    boot #引导启动
    }
    set timeout_style=menu
    if [ "${timeout}" = 0 ]; then
    set timeout=10 #等待10秒钟自动启动
    fi


VBoxManage convertfromraw ./hd.img --format VDI ./hd.vdi
;convertfromraw 指向原始格式文件
；--format VDI  表示转换成虚拟需要的VDI格式


#第一步 SATA的硬盘其控制器是intelAHCI
VBoxManage storagectl HelloOS --name "SATA" --add sata --controller IntelAhci --portcount 1
#第二步
VBoxManage closemedium disk ./hd.vdi #删除虚拟硬盘UUID并重新分配
#将虚拟硬盘挂到虚拟机的硬盘控制器
VBoxManage storageattach HelloOS --storagectl "SATA" --port 1 --device 0 --type hdd --medium ./hd.vdi



VBoxManage startvm HelloOS #启动虚拟机