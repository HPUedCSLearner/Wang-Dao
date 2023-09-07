#include<func.h>

int main(int argc, char* argv[])
{
	ARGS_CHECK(argc, 2);
	FILE *fp;
	int ret;
	fp = fopen(argv[1], "ab+");
	ERROR_CHECK(fp, NULL, "fopen");
	char buf[128] = {0};
	ret = fread(buf, sizeof(char), 5, fp);
	ERROR_CHECK(ret, -1, "fread");
	printf("buf=%s\n", buf);
	const char *p = "how are you";
	fwrite(p, sizeof(char), strlen(p), fp);
	fclose(fp);
	return 0;
}
