#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <wait.h>
#include <signal.h>
#include <errno.h>
#include <limits.h>
#include <pthread.h>
#include <assert.h>
#include <errno.h>
#define check_error(return_val,msg){             \
			if(return_val != 0){			\
				fprintf(stderr,"%s: %s\n",msg,strerror(return_val));\
				exit(-1);\
			}\
}
