#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
int main()
{
	int fd = open("./thetxt.txt",O_RDWR);
	printf("guangbiao:%ld\n",lseek(fd,0,SEEK_CUR));
	return 0;
}



