# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdio.h>
# include <unistd.h>
# include <string.h>
int main(int args, char *argv[])
{
	int fd;
	char buf[] = "test_in_3_test_write_c\n";
	int ret;
	fd = open("test.txt",O_RDWR);
	if(fd<0)
	{
		printf("文件打开失败！\n");
		return 0;
	}
	ret = write(fd,buf,strlen(buf));
	if(ret<0)
	{
		printf("写入失败！\n");
	}
	else
	{
		printf("写入成功！ret=%d\n",ret);
	}	
	return 0;
}
