// 无名管道的特点：
// 1 只能在亲缘关系进程间通信（父子或兄弟）
// 2 半双工（固定的读端和固定的写端）
// 3 他是特殊的文件，可以用 read、write 等，只能在内存中
// 
// 管道在程序中用一对文件描述符表示，其中一个文件描述符有可读属性，一个有可写的
// 属性。fds[0]是读，fds[1]是写。
// 
// 函数 pipe 用于创建一个无名管道，如果成功，fds[0]存放可读的文件描述符，fds[1]存放
// 可写文件描述符,并且函数返回 0，否则返回-1。
// 
// 管道不象真正的物理文件，不是持久的，即两进程终止后，管道也自动消失了。
// 

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

int main()
{
	int fds[2] = {0};
	pipe(fds);
	char szBuf[32] = {'\0'};
	if(fork() == 0) { 		//表示子进程
		close(fds[1]); 		//子进程关闭写
		sleep(2); 		//确保父进程有时间关闭读，并且往管道中写内容
		if(read(fds[0], szBuf, sizeof(szBuf)) > 0)
			puts(szBuf);
		close(fds[0]); 		//子关闭读
		exit(0);
	} else { 			//表示父进程
		close(fds[0]); 		//父关闭读
		write(fds[1], "hello", 6);
		waitpid(-1, NULL, 0); 	//等子关闭读
				      	//write(fds[1], "world",6); //此时将会出现“断开的管道”因为子的读已经关闭了
		close(fds[1]); 		//父关闭写
		exit(0);
	}
	return 0;
}
