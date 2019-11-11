#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#define MAX 50
int theopen()
{
    int fd;
    char buf[MAX];
    fd = open("1.txt",O_WRONLY|O_CREAT|O_APPEND);
    if(fd == -1)
    {
        printf("文件创建失败");
        return -1;
    }
    printf("请输入要写入的句子：");
    fgets(buf,MAX,stdin);
    write(fd,buf,MAX);
    printf("写入成功\n");
    return 0;
}
