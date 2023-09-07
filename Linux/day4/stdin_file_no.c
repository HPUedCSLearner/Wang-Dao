/*
	与标准的输入输出流对应，在更底层的实现是用标准输入、标准输出、标准错误文件描述符表示的。
	它们分别用 STDIN_FILENO、STDOUT_FILENO 和 STDERR_FILENO 三个宏表示，值分别是 0、1、2 三个整型数字。
		标准输入文件描述符 	➔ STDIN_FILENO 	➔ 0
		标准输出文件描述符 	➔ STDOUT_FILENO ➔ 1
		标准错误输出文件描述符 	➔ STDERR_FILENO ➔ 2
*/

#include <func.h>

int main()
{
	char szBuf[32],szBuf2[50];
	printf("Input string:");
	fflush(stdout); 			//要刷新标准输出流，才可以立即在屏幕上显示”Input string”
						//fflush 用于 linux 中的时候，只对 fflush(stdout)有效。
	int iRet=read(STDIN_FILENO,szBuf,sizeof(szBuf));
	szBuf[iRet]=0; 				//read 是以无类型指针方式读的数据，不会自动在缓冲区后加 0 结束标记。
	sprintf(szBuf2,"The string is:%s",szBuf);
	write(STDOUT_FILENO,szBuf2,strlen(szBuf2));
	return 0;
}
