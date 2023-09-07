#include <func.h>


int main()
{
	int fd = open("a.txt", O_RDONLY);
	if(fd == -1)
	{
		perror("open error");
		exit(-1);
	}
	struct stat buf;
	int iRet = fstat(fd, &buf);
	if(iRet == -1)
	{
		perror("fstat error");
		exit(-1);
	}
	if(S_ISREG(buf.st_mode))
	{
		printf("regular file!\n");
	}
	if(S_ISDIR(buf.st_mode))
	{
		printf("directory!\n");
	}
	if(S_ISLNK(buf.st_mode))
	{
		printf("link file!\n");
	}
	printf("the size of file is : %ld\n", buf.st_size);
	time_t tt = buf.st_atime;
	struct tm *pT = gmtime(&tt);
	printf("%4d-%02d-%02d %02d:%02d:%02d\n", (1900+pT->tm_year), (1+pT->tm_mon),
			pT->tm_mday, (8+pT->tm_hour), pT->tm_min, pT->tm_sec);
	// printf("the last access time is : %d\n", buf.st_atime);
	close(fd);
	return 0;
}
