/*可以通过 fstat 和 stat 函数获取文件信息，调用完毕后，文件信息被填充到结构体 struct stat
  变量中*/


#include <func.h>

int main()
{
	struct stat buf;
	stat ("/etc/passwd", &buf);
	printf("/etc/passwd file size = %ld \n", buf.st_size);	//st_size 可以得到文件大小
	return 0;
}
