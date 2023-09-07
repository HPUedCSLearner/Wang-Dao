/*
 * 原型：
#include <stdlib.h>
int system(const char *string);
system 函数通过调用 shell 程序/bin/sh –c 来执行 string 所指定的命令，该函数在内部是通过调用
execve(“/bin/sh”,..)函数来实现的。通过 system 创建子进程后，原进程和子进程各自运行，相互间关联较
少。如果 system 调用成功，将返回 0。
*/

#include <stdio.h>
#include <stdlib.h>
int main()
{
	system("ls -l "); //system(“clear”);表示清屏
	printf("step 1\n");
        //system("vi a.c"); // 会阻塞进程
        system("vi a.c &"); // 放到后太执行，不会阻塞进程
	printf("step 2\n");
	return 0;
}
