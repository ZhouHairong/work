#include "my.h"
int count=0;
int main()
{
	pid_t p1,p2,p3;
	p1=fork();
	int s1,s2,s3,r1,r2,r3;
	int pipefd1[2],pipefd2[2];
	char w_buf[100],r_buf[100];
	memset(w_buf,0,100);
	memset(r_buf,0,100);
	if(pipe(pipefd1)<0)
	{
		perror("pipe failed\n");
		return -1;
	}
	if(pipe(pipefd2)<0)
	{
		perror("pipe failed\n");
		return -1;
	}
	if(p1<0)
	{
		perror("fork1 falied\n");
		return -1;
	}
	else if(p1==0)
		{
		int a=0;
		close(pipefd1[0]);
		for(int i=0;i<65536;i++);
		{
			write(pipefd1[1],w_buf,sizeof(w_buf));
			printf("child write %d times\n",a);
		}	
		close(pipefd1[1]);
		printf("fork 1 is running !\n");
		}
		else
		{
			printf("parent fork second time\n");
			p2=fork();
			if(p2<0)
			{
				perror("fork2 failed\n");
				return -1;
			}
		else if(p2==0)
		{
			int g=0;
			close(pipefd1[1]);
			close(pipefd2[0]);
			for(int i=0;i<65536;i++)
			{
				read(pipefd1[0],buf,sizeof(i));
				printf("%d:parent read from pipe:%s\n",i,buf);
				g=g+i;
			}
			write(pipefd2[1],&g,sizeof(g));
			close(pipefd1[0]);
			close(pipefd2[1]);
			printf("fork 2 is running !\n");
			

		}
		else
		{
			printf("parent fork third time\n");
			p3=fork();
		if(p3<0)
		{
			perror("fork3 failed\n");
			return -1;	
		}
		else if(p3==0)
		{
			close(pipefd2[1]);
			read(pipefd2[0],buf,100);
			printf("65535!=%s",buf);
			printf("fork 3 is running !\n");
		}
		else{
			printf("parent waiting\n");
			r1=wait(&s1);
			r2=wait(&s2);
			r3=wait(&s3);
			printf("r1=%d,s1=%d,r2=%d,s2=%d,r3=%d,s3=%d",r1,WEXITSTATUS(s1),r2,WEXITSTATUS(s2),r3,WEXITSTATUS(s3));
			printf("\n.parent pid=%d,count=%d\n",getpid(),count);
			return 0;
		}
		
	}
	}
}
