#include "stdio.h"
#include "stdlib.h"
#include "string.h"

char* retn_ifilenm(int gc,char* argv[])
{
    //参数错误
	if(gc<1||NULL==argv)
	{
		return NULL;
	}
	for(int i=0;i<gc;i++)
	{
		if(strcmp("-i",argv[i])==0)
		{
            //-i 参数后属性
			if(i<(gc-1))
			{
				return argv[i+1];
			}
		}
	}
	return NULL;
}

char* retn_ofilenm(int gc,char * argv[])
{
	if(gc<1||NULL==argv)
	{
		return NULL;
	}
	for(int i=0;i<gc;i++)
	{
		if(strcmp("-o",argv[i])==0)
		{
            // -o 输出文件名
			if(i<(gc-1))
			{
				return argv[i+1];
			}
		}
	}
	return NULL;
}

int main(int argc, char *argv[])
{
	if(argc<4)
	{
        //参数不够
		printf("pram argc:%d\n", argc);
		exit(1);
	}
    //-i 输入参数
	char* ifnm=retn_ifilenm(argc,argv);
    //-o 输出参数
	char* ofnm=retn_ofilenm(argc,argv);
    //读取文件
	FILE* ifp=fopen(ifnm,"r");
    //写文件
    FILE* ofp=fopen(ofnm,"w+");
    //打开文件失败
    if (NULL==ifp||NULL==ofp)
    {
    	printf("open fail:%s:%s\n", ifnm,ofnm);
    	exit(1);
    }
    //读取文件 每次一个字节 直到EOF
	char fch=fgetc(ifp); 
	while(fch!=EOF)
    {
        //[ 转换成 tab？
    	if('['==fch)
    	{
    		fch='\t';
    	}
        //写到输出文件
        fputc(fch,ofp);
        //继续读取 单个字符内容
        fch=fgetc(ifp);
    } 
    
    fclose(ifp); 
    fclose(ofp);    
	return 0;
}