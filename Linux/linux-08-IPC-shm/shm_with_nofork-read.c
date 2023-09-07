
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/types.h>
void main()
{	//1. 读入端用 ftok 函数获得 key
	key_t key = ftok("b.dat",1); 
	if(key == -1)
	{
		perror("ftok");
		exit(-1);
	}
	//2. 读入端用 shmget 函数打开共享内存段
	int shmid = shmget(key,4096,0600|IPC_CREAT); 
	if(shmid == -1)
	{
		perror("shmget");
		exit(-1);
	}
	//3. 获得共享内存段的首地址
	char *pMap = (char *)shmat(shmid, NULL, 0);
	//4. 读取共享内存段中的内容
	printf("receive the data:%s\n",pMap);
	//5. 删除共享内存段 
	if(shmctl(shmid, IPC_RMID, 0) == -1) 
	{
		perror("shmctl");
		exit(-1);
	}
}

