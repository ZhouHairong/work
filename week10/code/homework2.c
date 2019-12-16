#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
int main()
{
	pid_t pid;
	int fd = open("./thetxt.txt",O_RDWR);
	pid = vfork();
	if(pid<0)
		printf("error in fork!\n");
	else if(pid == 0)
	{
		printf("这是子进程(先行)，光标位置为：%ld\n",lseek(fd,0,SEEK_CUR));
		write(fd,"123",3);
		_exit(0);
	}
	else
	{
		printf("这是父进程(后行)，光标位置为：%ld\n",lseek(fd,0,SEEK_CUR));
	}
	return 0;
}
