
//用lseek测量文件长度

# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include <error.h>


//用法：直接编译后执行./a.out filename
int main(int argc,char *argv[])
{
	int fd = -1;
	int ret = -1;
	if(argc != 2)
	{
		printf("用法错误！\n");
		_exit(-1);
	}
	fd = open(argv[1],O_RDONLY);
	if(fd < 0)
	{
		perror("文件打开错误！");
		_exit(-1);
	}

	ret = lseek(fd,0,SEEK_END);
	printf("文件长度：%d\n",ret);
	close(fd);
	return 0;
}