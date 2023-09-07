#include<func.h>

int main(int argc, char* argv[])
{
	ARGS_CHECK(argc, 1);
	FILE *fp;
	int ret;

	ret = chdir("/home");
	ERROR_CHECK(ret, -1, "chdir");
	
	char path[512] = {0};
	ret = getcwd(path, sizeof(path));
	ERROR_CHECK(ret, -1, "getcwd");
	printf("current path %s\n", path);
	
	return 0;
}
