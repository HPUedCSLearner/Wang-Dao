#include <func.h>

int main()
{
	int fd = open("a.txt", O_WRONLY | O_CREAT);	//默认打开了 0,1,2 表示标准输入，标准输出，标准错误输出。
	printf("this fd = %d\n", fd);			// 符到当前未打开的最小描述符
	if(fd == -1)
	{
		perror("open error");
		exit(-1);
	}
	printf("\n"); /* 必不可少 */
	close(1);			// 用 close(1);则表示关闭标准输出，此时这个文件描述符就空着了
	int fd2 = dup(fd);
	close(fd);
	printf("wys: hello world\n"); 	// 然后在用标准输出的时候，发现标准输出重定向到你指定的文件了
	close(fd2);
	return 0;
}
