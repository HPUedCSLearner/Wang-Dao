#include<func.h>

int main(int argc,char *argv[])
{
	char szBuf[32]={0};
	int fda=open("./a.txt",O_RDWR); //假设 a.txt 的内容为：hello world
	int fdaa=dup(fda);
	read(fda,szBuf,4);
	puts(szBuf); //关闭之前先输入原来的内容
	close(fda);
	//lseek(fdaa, 0, SEEK_SET);
	read(fdaa,szBuf,sizeof(szBuf));
	puts(szBuf); //输出现在的内容
	close(fdaa);
	return 0;
}
