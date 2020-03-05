/*
	若同时打开两次同一文件
	进行读取操作不会影响对方的文件指针
	进行写操作也是
*/

# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include <string.h>

//这里测试读操作
int main()
{
	int fd1 = -1;
	int fd2 = -1;
	char buf[10]={0};
	fd1 = open("test.txt",O_RDONLY);
	fd2 = open("test.txt",O_RDONLY);

	if(fd1<0 || fd2 <0)
	{
		perror("文件打开错误！\n");
		_exit(-1);
	}

	for(int i=0;i<5;i++)
	{
		read(fd1,buf,2);
		printf("fd1:[%s]\n",buf);
		memset(buf,0,2);//fill the first 2 bytes of buf with 0

		read(fd2,buf,2);
		printf("fd2:[%s]\n",buf);
		memset(buf,0,2);	
	}

	close(fd1);
	close(fd2);
	return 0;
}












