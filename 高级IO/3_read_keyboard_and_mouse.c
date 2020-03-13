# include <stdio.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>
# include <string.h>
int main()
{
	int fd = -1;
	char buf[100];
	int ret = -1;
	int flag = -1;
	fd = open("/dev/input/mouse0",O_RDONLY|O_NONBLOCK);

	if(fd < 0)
	{
		perror("open");
		_exit(-1);
	}
	while(1)
	{
		//读鼠标
		memset(buf,0,sizeof(buf));
		ret = read(fd,buf,10);
		if(ret > 0)
		{
			//读到内容
			printf("从鼠标中读到:[%s].\n",buf);
		}

		//读键盘
		memset(buf,0,sizeof(buf));
		
		//设置非阻塞
		flag = fcntl(0,F_GETFL);
		flag |= O_NONBLOCK;
		fcntl(0,F_SETFL,flag);
		
		ret = read(0,buf,10);
		if(ret > 0)
		{
			printf("从键盘中读到：[%s].\n",buf);
		}

	}
	

	close(fd);
	return 0;
}


