// 管道两端的关闭是有先后顺序的
// 如果先关闭写端则从另一端读数据时, read函数将返回 0，表示管道已经关闭；
// 是如果先关闭读端，则从另一端写数据时，将会使写数据的进程接收到 SIGPIPE 信号:
// 	如果写进程不对该信号进行处理，将导致写进程终止; (就是write处终止)
// 	如果写进程处理了该信号，则写数据的 write 函数返回一个负值，表示管道已经关闭。



#include <signal.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
	int fds[2];
	pipe(fds);
	//注释掉这部分将导致写进程被信号SIGPIPE终止
	sigset_t setSig;
	sigemptyset(&setSig);
	sigaddset(&setSig,SIGPIPE);
	sigprocmask(SIG_BLOCK,&setSig,NULL);
	char szBuf[10] = {0};
	if(fork() == 0){
		close(fds[1]);//子关闭写
		sleep(2);//确保父关闭读
		if(read(fds[0], szBuf, sizeof(szBuf)) > 0) // 如果没有处理signal, write就会被终止，那么这个打印，就不会打印 （I am father, pid is %d） 
			puts(szBuf);
		close(fds[0]);
	}else{
		close(fds[0]);//父关闭读
		write(fds[1], "hello", 6);
		wait(NULL);
		write(fds[1], "world", 6);//子的读关闭，父还在写
		close(fds[1]);//父关闭写
		printf("I am father, pid is %d\n", getpid());
	}
	return 0;
}

