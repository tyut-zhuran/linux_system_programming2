# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdio.h>
# include <unistd.h>
int main(int argc,char *argv[])
{
	int fd = -1;
	fd = open("test.txt",O_RDWR);
	if(fd == -1)
	{
		printf("文件打开出错！");
	}
	printf("文件打开成功！fd=%d\n",fd);
	
	close(fd);
	
	return 0;
}
