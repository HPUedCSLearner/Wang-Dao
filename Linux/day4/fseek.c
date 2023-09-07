#include <func.h>
/*利用该函数可以实现文件空洞（对一个新建的空文件，可以定位到偏移文件开头 1024 个字节的地
方，在写入一个字符，则相当于给该文件分配了 1025 个字节的空间，形成文件空洞）通常用于多
进程间通信的时候的共享内存。*/

int main()
{
	int fd = open("c.txt", O_WRONLY | O_CREAT);
	lseek(fd, 1024, SEEK_SET);
	write(fd, "a", 1);
	close(fd);
	return 0;
}
