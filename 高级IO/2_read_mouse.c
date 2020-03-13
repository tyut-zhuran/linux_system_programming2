//ubuntu子系统里没有鼠标驱动。。
//略过了



//还是用虚拟机试一下
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

	memset(buf,0,sizeof(buf));
	fd = open("/dev/input/mouse0",O_RDONLY);
	if(fd < 0)
	{
		perror("open");
		_exit(-1);
	}

	read(fd,buf,10);

	printf("从鼠标中读到了：[%s].\n",buf);

	close(fd);
	return 0;

}
