# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>


# include <unistd.h>

# include <stdio.h>
# include <string.h>
//O_APPEND  追加文件内容
//O_TRUNC 清空文件内容


int main()
{

	int fd = -1;
	char buf[] = "written in 4_TRUNC_and_APPEND.c\n";
	int ret=-1;
	fd = open("test.txt",O_RDWR|O_TRUNC);//O_RDWR|O_APPEND

	if(fd < 0)
	{
		printf("打开文件失败！\n");
		_exit(-1);		
	}
	ret = write(fd,buf,strlen(buf));
	if(ret<0)
	{
		printf("文件写入失败！\n");
		_exit(-1);
	}
	printf("文件写入成功！ret=%d.\n",ret);
	close(fd);
	return 0;
}

















