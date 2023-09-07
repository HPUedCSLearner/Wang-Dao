// 对 FIFO 类型的文件的打开/关闭跟普通文件一样，都是使用 open 和 close 函数。
// 	如果打开时使用 O_WRONLY 选项，则打开 FIFO 的写入端;
// 	如果使用 O_RDONLY 选项，则打开FIFO 的读取端;
// 	写入端和读取端都可以被几个进程同时打开;

// 如果以读取方式打开 FIFO，并且还没有其它进程以写入方式打开 FIFO，open 函数将被阻塞；
// 如果以写入方式打开 FIFO，并且还没其它进程以读取方式 FIFO，open 函数也将被阻塞。
// 与 PIPE 相同，关闭 FIFO 时，如果先关读取端，将导致继续往 FIFO 中写数据的进程接收 SIGPIPE 的信号。


#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

int main()
{
	int fdFifo = open("MyFifo.pip",O_WRONLY); 	//1. 打开（判断是否成功打开略）
	write(fdFifo, "hello", 6); 			//2. 写
	close(fdFifo); 					//3. 关闭
	return 0;
}
