//popen 函数类似于 system 函数，与 system 的不同之处在于它使用管道工作。原型为：
//#include <stdio.h>
// FILE *popen(const char *command, const char *type);
// int pclose(FILE *stream);
//command 为可执行文件的全路径和执行参数；



#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
int main()
{
	FILE *read_fp;
	char buffer[BUFSIZ + 1];
	printf("BUFSIZ=%d\n", BUFSIZ);
	int chars_read;
	memset(buffer, '\0', sizeof(buffer));
	//read_fp = popen("ps -ax", "r");
	read_fp = popen("ls -l", "r");
	if (read_fp != NULL) {
		chars_read = fread(buffer, sizeof(char), BUFSIZ, read_fp);
		printf("read %d chars\n", chars_read);
		while (chars_read > 0) {
			buffer[chars_read - 1] = '\0';
			printf("Reading:-\n %s\n", buffer);
			chars_read = fread(buffer, sizeof(char), BUFSIZ, read_fp);
			printf("read %d chars\n", chars_read);
		}
		pclose(read_fp);
		exit(EXIT_SUCCESS);
	}
	exit(EXIT_FAILURE);
}
