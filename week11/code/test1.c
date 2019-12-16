#include <unistd.h>
#include <signal.h>
#include <sys/param.h>
#include <sys/types.h>
#include <sys/stat.h>
void init_daemon(void)
{
	pid_t child1,child2;
	int i;
	child=fork();
	if(child1>0)
	exit(0);
	else if(child1<0)
	{
		perror("fail to make child");
		exit(0);
	}
	setsid();
	chdir("/tmp");
	umark(0);
	for(i=0,i<NOFILE,i++)
	close(i);
	return 0;
}
