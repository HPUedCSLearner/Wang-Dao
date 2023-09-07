// 用 fork 继承打开的文件 
// fork 以后的子进程自动继承了父进程的打开的文件，继承以后，父进程关闭打开的文件不会对子进程造成影响。


#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
int main()
{
	char szBuf[32] = {'\0'};
	int iFile = open("./a.txt", O_RDONLY);
	pid_t chld_pid = fork();
	if(chld_pid > 0){		//parent process
		printf("I am father: pid = %d\n", getpid());
		printf("fork ret = %d\n", chld_pid);
		close(iFile);
		return 0;
	}
	//child process
	printf(" I am child: pid = %d\n", getpid());
	sleep(3); 		//wait for parent process closing fd
	if(read(iFile, szBuf, sizeof(szBuf)-1) < 1){
		perror("read fail");
	}else{
		printf("string:%s\n",szBuf);
	}
	close(iFile);
	return 0;
}
