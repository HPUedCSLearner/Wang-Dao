

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <ctype.h>
typedef struct tagmag
{
	int client_pid ;
	char my_data[512] ;
}MSG;

int main()
{
	int server_fifo_fd , client_fifo_fd ;
	char client_fifo[256];
	MSG my_msg ;
	char * pstr ;
	memset(&my_msg , 0 , sizeof(MSG));
	// 打开服务端用的管道，主要是循环读取不同客户端发来的请求
	mkfifo("SERVER_FIFO_NAME",0777);
	server_fifo_fd = open("./SERVER_FIFO_NAME",O_RDONLY);
	if(server_fifo_fd == -1)
	{
		perror("server_fifo_fd");
		exit(-1);
	}
	int iret ;
	// 循环读取客户端发来的请求(当管道不可读的时候，阻塞)
	while( (iret = read(server_fifo_fd , &my_msg ,sizeof(MSG))>0))
	{
		//iret = read(server_fifo_fd , &my_msg ,sizeof(MSG));
		// 1、输出读到的数据
		pstr = my_msg.my_data ;
		printf("%s\n",my_msg.my_data);
		// 2、逐个字符转成大写
		while(*pstr != '\0')
		{ 
			*pstr = toupper(*pstr);
			pstr ++ ;
		}
		// 3、以写的方式打开客服端创建的管道(pid区分)
		memset(client_fifo , 0 , 256);
		sprintf(client_fifo , "CLIENT_FIFO_%d" , my_msg.client_pid);
		client_fifo_fd = open(client_fifo , O_WRONLY);
		if(client_fifo_fd == -1)
		{
			perror("client_fifo_fd");
			exit(-1);
		}
		// 4、将结果写道管道
		write(client_fifo_fd , &my_msg, sizeof(MSG));
		printf("%s\n", my_msg.my_data);
		printf("OVER!\n");
		close(client_fifo_fd);
	}
	return 0 ;
}

