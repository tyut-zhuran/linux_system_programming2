# include <stdio.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <string.h>
# include <sys/select.h>
# include <sys/time.h>




int main()
{
	int fd = -1;
	int ret = -1;
	fd_set read_set;
	struct timeval tm = {0};
	char buf[100];

	fd = open("/dev/input/mouse0",O_RDONLY);
	if(fd < 0)
	{
		perror("open");
		_exit(-1);
	}

	

	

	while(1)
	{
		FD_ZERO(&read_set);
		FD_SET(0,&read_set);
		FD_SET(fd,&read_set);//必须在循环里重新初始化,具体看man手册
		tm.tv_sec = 1;
		tm.tv_usec = 0;
		ret = select(fd+1,&read_set,NULL,NULL,&tm);
		if(ret < 0)
		{
			perror("select");
			_exit(-1);
		}
		else if(ret == 0)
		{
			printf("timeout.\n");
		}
		else
		{
			if(FD_ISSET(0,&read_set))
			{
				memset(buf,0,sizeof(buf));
				read(0,buf,10);
				printf("键盘：[%s].\n",buf);
			}

			if(FD_ISSET(fd,&read_set))
			{
				memset(buf,0,sizeof(buf));
				read(fd,buf,10);
				printf("鼠标：[%s].\n",buf);
			}
		}
	}
	

	close(fd);
	return 0;

}


