/*
 * 	新的描述符由用户用参数 fdnew 显示指定
 * 	如果 fdnew 已经指向一个已经打开的文件，内核会首先关闭掉 fdnew 所指向的原来的文
 *	int retFdNew =  dup2(fdold, fdnew)
 *	如果成功 dup2 的返回值于fdnew 相同,否则为-1.
*/

#include<func.h>

int main(int argc,char *argv[])
{
	char szBuf[32]={0};
	int fda=open("./a.txt",O_RDONLY);
	int fdb=open("./b.txt",O_RDONLY);
	int fdbb=dup(fdb);
	int fda2=dup2(fda,fdb); 		//可以设定为：int fda2 = dup2(fda,5);即自己设为 5
	printf("fda:%d fdb:%d fdbb:%d fda2:%d\n",fda,fdb,fdbb,fda2);
	read(fdb,szBuf,sizeof(szBuf)-1); 	//此时 fdb 已经不再定位 b.txt 而是 a.txt
	printf("result:%s\n",szBuf);
	close(fda);
	close(fdb);
	close(fdbb);
	close(fda2);
	return 0;
}

