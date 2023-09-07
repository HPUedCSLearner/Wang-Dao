#include<func.h>

#define FILENAME1 "./aaa.txt" 			//用宏定义文件的路径，可以实现一改都改
#define FILENAME2 "./bbb.txt"
int main()
{
	char buf[512] = {0};
	int fo1 = open(FILENAME1, O_RDONLY);	//fo1,fo2 都是文件描述词
	int fo2 = creat(FILENAME2, 0755); 	//创建文件
					  	//int fo2 = open(FILENAME2, O_WRONLY | O_CREAT);
	if( (-1 == fo1) || (-1 == fo2) )
	{
		perror("open failed!\n");
		//用于输出错误信息.类似于：fputs(”open failed\n”,stderr);
		exit(-1);
	}
	int fr = 0;
	while( (fr = read(fo1, buf, sizeof(buf))) > 0 )
		//如果 read 读取成功，返回的是长度，否则，返回-1
	{
		int fw = write(fo2, buf, fr);
		if( -1 == fw )
		{
			perror("write failed!");
			exit(-1);
		}
	}
	close(fo1);
	close(fo2);
	return 0;
}
