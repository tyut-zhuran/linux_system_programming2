#include <stdio.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>
int main(int args, char* argv[])
{
	int fd;
	char buf[100] = {0};
	int res;
	//1、打开文件
	fd = open("test.txt",O_RDWR);
	if(fd <0 )
	{
		printf("文件打开失败！\n");
	}
	else
	{
		printf("文件打开成功！fd=%d\n",fd);
	}

	//2、读取文件
	res = read(fd,buf,20);
	if(res == -1)
	{
		printf("读取失败！\n");
	}
	else
	{
		printf("实际读取了%d字节\n",res);
		printf("文件内容是：%s.\n",buf);
	}

	//3、关闭文件
	close(fd);

	return 0;
}
