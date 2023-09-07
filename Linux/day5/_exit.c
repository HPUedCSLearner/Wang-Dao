// 前 3 种方式为正常的终止
// 1、main函数返回
// 2、exit退出
// 3、_exit退出
// 
// exit 和_exit 函数都是用来终止进程的。当程序执行到 exit 和_exit 时，进程会无条件的
// 停止剩下的所有操作，清除包括 PCB 在内的各种数据结构，并终止本程序的运行。但是它
// 们是有区别的，exit 和_exit 的区别如图所示：
// 
// exit 函数和_exit 函数的最大区别在于 exit 函数在退出之前会检查文件的打开情况，把文
// 件缓冲区中的内容写回文件，就是图中的“清理 I/O 缓冲”。

#include <stdio.h>
#include <unistd.h>
int main()
{
	printf("Using _exit...\n");			// '\n'可以刷新标准输出缓冲区
	printf("This is the content in buffer");
	_exit(0);
}
