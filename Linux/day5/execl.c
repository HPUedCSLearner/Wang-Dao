//fork 是在复制一份原进程，而 exec 函数是用 exec 的第一个参数指定的程序覆盖现有进程空间
//arg 是可执行文件的命令行参数，多个用，分割注意最后一个参数必须为 NULL


#include <stdio.h>
#include <string.h>
#include <unistd.h>

int main()
{
	execl("./add" , "add" , "3" , "4" , NULL);
	return 0 ;
}
