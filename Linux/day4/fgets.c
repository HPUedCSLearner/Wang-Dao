#include<func.h>

int main()
{
	char szBuf[32];
	printf("Input string:"); 			//向屏幕输出一字符串
	fgets(szBuf,sizeof(szBuf),stdin);		//从键盘读入一行字符串
	fprintf(stdout,"The string is:%s",szBuf);	//向屏幕输出一行字符串
	return 0;
}
