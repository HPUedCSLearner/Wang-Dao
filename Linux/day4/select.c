#include<func.h>

#define FILENAME1 "1.pipe"
#define FILENAME2 "2.pipe"

int main()
{
	char buf[10] = {0};
	int fd1 = open(FILENAME1,O_RDWR);
	int fd2 = open(FILENAME2,O_RDWR);
	int fd3 = open(FILENAME1,O_RDWR);
	int fd4 = open(FILENAME2,O_RDWR);

	printf("fd1=%d, fd2=%d, fd3=%d, fd4=%d\n", fd1, fd2, fd3, fd4);
	
	if( (-1 == fd1) || (-1 == fd2) || (-1 == fd3) || (-1 == fd4) )
	{
		perror("open");
		exit(-1);
	}
	fd_set fdrd,fdwr; 	//绑定读写集合
	FD_ZERO(&fdrd); 	//清除以前读的绑定
	FD_ZERO(&fdwr); 	//清除以前写的绑定
	int max1 = fd1 > fd2 ? fd1 : fd2; 	//获取读绑定中的文件描述词最大值
	int max2 = fd3 > fd4 ? fd3 : fd4; 	//获取写绑定中的文件描述词最大值
	int max = max1 > max2 ? max1 : max2; 	//获得读写文件描述词最大值
	struct timeval tv; 			//用于记录时间，表示过这么长时间不响应就退出
	tv.tv_sec = 2; 	//秒
	tv.tv_usec = 0; //微妙
	while(1)
	{
		FD_SET(fd1,&fdrd); //将 fd1 与读绑定
		FD_SET(fd2,&fdrd);
		FD_SET(fd3,&fdwr); //将 fd3 与写绑定
		FD_SET(fd4,&fdwr);
		if( select(max+1, &fdrd, &fdwr, NULL, &tv) == -1 ) //从 1—max+1 查找
		{
			perror("select");
			break;
		}
		if( FD_ISSET(fd1,&fdrd) ) //如果 fd1 设置的是读绑定
		{
			memset(buf,0,sizeof(buf));
			read(fd1,buf,sizeof(buf)-1);
			puts(buf);
			sleep(1);
		}
		if( FD_ISSET(fd2,&fdrd) )
		{
			memset(buf,0,sizeof(buf));
			read(fd2,buf,sizeof(buf)-1);
			puts(buf);
			sleep(1);
		}
		if( FD_ISSET(fd3,&fdwr) ) //如果 fd3 设置的是写绑定
		{
			strcpy(buf,"hello3");
			write(fd3,buf,strlen(buf));
			sleep(2);
		}
		if( FD_ISSET(fd4,&fdwr) )
		{
			strcpy(buf,"hello4");
			write(fd4,buf,strlen(buf));
			sleep(2);
		}
	}
	close(fd1);
	close(fd2);
	close(fd3);
	close(fd4);
	return 0;
}
