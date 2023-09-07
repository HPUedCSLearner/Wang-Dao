// 函数原型：
// #include <stdio.h>
// FILE* popen(const char* command, const char* open_mode);
// int pclose(FILE* fp);
// 函数 popen()：允许一个程序将另一个程序作为新进程来启动，并可以传递数据给它或者通过它接收数据。
// 
// 如果 open_mode 是“r”，被调用程序的输出就可以被调用程序(popen)使用
// 如果 open_mode 是“w”，调用程序(popen)就可以用 fwrite 向被调用程序发送数据(被调用程序必须阻塞等待标准输入)
 



#include<stdio.h>
#include<unistd.h>
int main()
{
	char buf[]={"aaa bbb ccc ddd eee fff ggg hhh"};
	FILE *fp = popen("wc -w", "w");
	sleep(2);
	fwrite(buf, sizeof(buf), 1, fp);
	pclose(fp);
	return 0;
}
