#include <stdio.h>
#include <time.h>
int main()
{
	char *wday[] = { "sunday", "monday", "tuesday", "wednesday", "thursday", 
		"friday","saterday" };
	time_t timep;
	struct tm *pTm;
	time(&timep);
	pTm = gmtime(&timep);
	printf("%04d-%02d-%02d\t",(1900 + pTm->tm_year), (1 + pTm->tm_mon), (pTm->tm_mday));
	printf("%02d:%02d:%02d\t",(8 + pTm->tm_hour), (pTm->tm_min), (pTm->tm_sec)); //似乎小时总是相差 8，所以加上 8 试试
	printf("%s\n",wday[pTm->tm_wday]);
}
