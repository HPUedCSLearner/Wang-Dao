// 如果父进程先于子进程退出，则子进程成为孤儿进程，此时将自动被 PID 为 1 的进程（即 init）接管。
// 孤儿进程退出后，它的清理工作有祖先进程 init 自动处理。但在 init 进程清理子进程之前，它一直消耗系统的资源，所以要尽量避免。
// 通过 ps –ef 就可以看到此时子进程一直在运行，并且父进程是 1 号进程。

// 总体来说，孤儿进程就是，父进程退出，进程还在运行，然后交由1号进程init接管
// 按道理来讲，子进程的资源应该由父进程来回收，不然init也忙不过来呀
// 子进程其实跟线程差不多：
// 	多进程：fork 	多进程run 	父进程wait()
// 	多线程：create	多线程run	主线程jion()

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int main()
{
	printf("Parent process id:%d\n",getpid());
	pid_t iRet = fork();
	if (iRet < 0) {			//出错
		printf("Create child process fail!\n");
	} else if (iRet == 0) {		//表示子进程
		printf("child process id:%d ppid:%d\n",getpid(),getppid());
		while(1){}
	} else {			//表示父进程
		printf("parent process success,child id:%d\n",iRet);
	}
	return 0;
}
