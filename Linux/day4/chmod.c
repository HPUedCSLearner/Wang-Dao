#include<func.h>

int main(int argc, char* argv[])
{
	ARGS_CHECK(argc, 2);
	FILE *fp;
	int ret;
	ret = chmod(argv[1], 0777);
	ERROR_CHECK(ret, -1, "chmod");
	return 0;
}
