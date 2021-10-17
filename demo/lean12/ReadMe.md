1.首先我需要创建一个空的img 存放启动光盘
    lmoskrlimg -m k -lnf GRUB头文件 -o 映像文件 -f 输入的文件列表
    内核映像文件
        4Kb GRUB
        映像文件头描述符
        文件头描述符
        文件
    
    Makefile
        cd ./release/
        ./lmoskrlimg -m k -lnf initldrimh.bin -o Cosmos.eki -f initldrsve.bin initldrkrl.bin Cosmos.bin font.fnt logo.bmp background.bmp
1. all 编译 
2. cp 负责从文件夹中拷贝编译好的文件到release 文件中 
3. 最后在生成映像