# include <stdio.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <string.h>
# include <poll.h>




int main()
{
	int fd = -1;
	int ret = -1;
	struct pollfd read_fd[2] = {0};
	char buf[100];

	fd = open("/dev/input/mouse0",O_RDONLY);
	if(fd < 0)
	{
		perror("open");
		_exit(-1);
	}

	while(1)
	{
		read_fd[0].fd = 0;
		read_fd[0].events = POLLIN;


		read_fd[1].fd = fd;
		read_fd[1].events = POLLIN;
		
		ret = poll(read_fd,fd+1,1000);
		if(ret < 0)
		{
			perror("select");
			_exit(-1);
		}
		else if(ret == 0)
		{
			printf("timeout.\n\n");//这行打不出来不知道为什么,好像timeout不管用？不知道是不是虚拟机的问题
		}
		else
		{
			if(read_fd[0].events == read_fd[0].revents)
			{
				memset(buf,0,sizeof(buf));
				read(0,buf,10);
				printf("键盘：[%s].\n",buf);
			}

			if(read_fd[1].events == read_fd[1].revents)
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


