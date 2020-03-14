# include <stdio.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>

# include <string.h>

int main()
{
	int ret = -1;
	int fd = -1;
	char buf[100];
	ret = fork();

	if(ret == 0)
	{
		//子进程
		//进行读取鼠标操作
		fd = open("/dev/input/mouse0",O_RDONLY);
		if(fd < 0)
		{
			perror("open");
			_exit(-1);
		}
		while(1)
		{
			memset(buf,0,sizeof(buf));
		
			ret = read(fd,buf,20);
			printf("鼠标：[%s].\n",buf);
		}

		close(fd);
	}
	else if(ret > 0)
	{
		//父进程
		while(1)
		{
		memset(buf,0,sizeof(buf));
		ret = read(0,buf,20);
		printf("键盘：[%s].\n",buf );
		
		}
	}
	else
	{
		perror("fork");
		_exit(-1);
	}

	return 0;
}



