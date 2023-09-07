// 打印参数小测试
#include<stdio.h>

int main(int argc,char ** argv)
{
	int i = 0;
	for( ; i< argc; i++)
		printf("%s\n",argv[i]); 
	return 0;
}
