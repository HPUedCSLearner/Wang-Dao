


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
typedef struct tagmag
{
	int client_pid ;
	char my_data[512] ;
}MSG;

int main()
{
	// 1、创建带有pid名字的管道，用于读取服务器发来的结果
	int server_fifo_fd,client_fifo_fd ;
	char client_fifo[256]={0};
	sprintf(client_fifo,"CLIENT_FIFO_%d",getpid());
	MSG my_msg ;
	memset(&my_msg , 0 , sizeof(MSG));
	my_msg.client_pid = getpid();
	// 2、以写的方式，打开用于发送服务请求的管道
	server_fifo_fd = open("./SERVER_FIFO_NAME",O_WRONLY);
	mkfifo(client_fifo , 0777);
	// 循环 发出请求
	while(1)
	{
		// 3、从标准输入读取数据
		int n = read(STDIN_FILENO,my_msg.my_data , 512);
		my_msg.my_data[n] = '\0' ;
		// 4、写到自己创建的管道,发出请求
		write(server_fifo_fd , &my_msg , sizeof(MSG));
		// 5、以读的方式，打开服务端的管道，获取请求结果
		client_fifo_fd = open(client_fifo , O_RDONLY);
		//memset(&my_msg , 0 , sizeof(MSG));
		n = read(client_fifo_fd,&my_msg , sizeof(MSG));
		my_msg.my_data[n]= 0 ;
		write(STDOUT_FILENO, my_msg.my_data ,strlen(my_msg.my_data) );
		close(client_fifo_fd);
	}
	unlink(client_fifo);
}



