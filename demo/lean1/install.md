# df /boot/
会查看到 /dev/sda2
对应修改下面的配置msdos2
# 举例子 ubuntu 20
先修改 /etc/default/grub
注释掉 #GRUB_TIMEOUT_STYLE=hidden
修改一下
GRUB_TIMEOUT=10
GRUB_CMDLINE_LINUX_DEFAULT="text"
需要执行 
sudo update-grub
# 修改 /boot/grub/grub.cfg
menuentry 'HelloOS' { 
    insmod part_msdos #GRUB加载分区模块识别分区 
    insmod ext2 #GRUB加载ext文件系统模块识别ext文件系统 
    set root='hd0,msdos5' #注意boot目录挂载的分区，这是我机器上的情况 
    multiboot2 /boot/HelloOS.bin #GRUB以multiboot2协议加载HelloOS.bin 
    boot #GRUB启动HelloOS.bin
}

# 拷贝 HelloOS.bin 到 /boot/HelloOS.bin