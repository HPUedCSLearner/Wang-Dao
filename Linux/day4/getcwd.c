#include<func.h>

int main(int argc, char* argv[])
{
	printf("current path %s\n", getcwd(NULL, 0));
	return 0;
}
