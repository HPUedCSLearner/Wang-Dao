


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#define PERM S_IRUSR | S_IWUSR //表示用户可读可写 即 0600

int main(int argc,char **argv)
{
	/*在两个有亲属关系进程间通信,KEY 采用 IPC_PRIVATE 由系统自选*/
	int shmid = shmget(IPC_PRIVATE, 1024, PERM); //只有 IPC_PRIVATE 情况可以不设置 IPC_CREAT
	if(shmid == -1) /* 创建 byte 的共享内存*/
	{
		fprintf(stderr,"Create Share Memory Error:%s\n\a",strerror(errno));
		exit(1);
	}
	if(fork() > 0) /* 父进程代码*/
	{
		char *p_addr = (char*)shmat(shmid, NULL, 0); //获得该段共享内存的首地址
		memset(p_addr, '\0', 1024); //初始化为 0
		strncpy(p_addr, "share memory", 1024); //存入（写入）内容
		printf("parent %d Write buffer: %s\n", getpid(), p_addr);
		sleep(2);
		wait(NULL); //防止僵尸进程
		shmctl(shmid, IPC_RMID, 0);/*删除共享内存,用 ipcs -m 看共享内存*/
		exit(0);
	}
	else /* 子进程代码*/
	{
		sleep(5); //让父有足够的时间写
		char *c_addr = (char*)shmat(shmid, NULL, 0); //取出（读出）内容
		printf("Client pid=%d,shmid =%d Read buffer: %s\n",getpid(),shmid,c_addr);
		exit(0);
	}
}
