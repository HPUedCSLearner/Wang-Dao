


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(void)
{
	pid_t pid, wpid;
	int status;

	pid = fork();
	if(pid == 0){               //子进程
		printf("I am child --- my parent is %d\n", getppid());
		sleep(30);              //子进程睡眠30秒
		printf("child is die\n");
	}else if(pid>0){           //父进程
		printf("I am fathter-- my fork ret = %d\n", pid);
		wpid = wait(&status);   //等待回收子进程
		if(wpid == -1){
			perror("wait error:");
			exit(1);
		}
		//正常退出判断
		if(WIFEXITED(status)){
			printf("child exit with %d\n", WEXITSTATUS(status));
		}

		//因为某种信号中断获取状态
		if(WIFSIGNALED(status)){
			printf("child killed by %d\n", WTERMSIG(status));
		}

		while(1)
		{
			printf("parent pid = %d, sonpid = %d\n", getpid(), pid);
			sleep(1);
		}
	} else {
		perror("fork error");
		exit(1);
	}

	return 0;
}
