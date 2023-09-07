#include<func.h>

int main()
{
	int fd = open("a.txt", O_WRONLY);
	ftruncate(fd, 1);
	close(fd);
	return 0;
}
