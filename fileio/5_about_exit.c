# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>//for open()

# include <unistd.h>//for _exit()
# include <stdio.h>

int main()
{
	int fd;
	fd = open("dont_exist.txt",O_RDONLY);
	if(fd < 0)
	{
		printf("打开文件失败！\n");
		_exit(-1);
	}	
	printf("不应被打印！\n");
	return 0;
}


