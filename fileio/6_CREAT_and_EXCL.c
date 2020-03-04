# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>
# include <string.h>
# include <stdio.h>
int main()
{
	int fd = -1;
	char buf[] = "zhuran";
	int res=-1;
	fd = open("a.txt",O_RDWR|O_CREAT,0666);
	//O_CREAT参数作用，当文件不存在时自动创建新的空文件
	//此时可以通过open()的第三个参数mode设置创建的文件的权限

	//fd = open("a.txt",O_RDWR|O_CREAT|O_EXCL);//O_EXCL作用，在O_CREAT作用下，若文件已经存在，则报错
	if(fd < 0)
	{
		printf("打开失败！\n");
		_exit(-1);
	}
	printf("文件打开成功！\n");
	res = write(fd,buf,strlen(buf));
	printf("res=%d\n",res);
	close(fd);
	return 0;
}