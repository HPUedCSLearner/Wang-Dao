


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <sys/ipc.h>
#include <sys/shm.h> 			//头文件包含
#include <sys/types.h>

int main()
{
	//1. 写入端先用 ftok 函数获得 key
	key_t key = ftok("b.dat",1); 	
	if(key == -1)
	{
		perror("ftok");
		exit(-1);
	}
	//2. 写入端用 shmget 函数创建一共享内存段
	int shmid = shmget(key,4096,IPC_CREAT); 
	if(shmid == -1)
	{
		perror("shmget");
		exit(-1);
	}
	//3. 获得共享内存段的首地址
	char *pMap = (char *)shmat(shmid, NULL, 0); 
	memset(pMap, 0, 4096);
	//4. 往共享内存段中写入内容
	memcpy(pMap, "hello world", 4096); 
	//5. 关闭共享内存段
	if(shmdt(pMap) == -1) 
	{
		perror("shmdt");
		exit(-1);
	}
	return 0;
}
