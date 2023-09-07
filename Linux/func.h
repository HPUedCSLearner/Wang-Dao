#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>
#include <sys/types.h>
#include <dirent.h>
#include <fcntl.h>
#include <errno.h>
#include <time.h>
#include <sys/time.h>
#include <sys/select.h>

#define ARGS_CHECK(argc, val) {		\
	if (argc != val) {		\
		printf("error args\n");	\
		return -1;		\
	}				\
}					\

#define ERROR_CHECK(ret, retVal, funcName) {	\
	if (ret == retVal) {			\
		perror(funcName);		\
		return -1;			\
	}					\
}						\
