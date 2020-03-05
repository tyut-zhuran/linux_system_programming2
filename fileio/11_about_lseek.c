//文件指针：表征正在操作文件流的位置
//刚打开文件时，文件指针默认指向文件开始
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include <string.h>



int main()
{
	int fd = -1;
	int ret1 = -1;
	int ret2 = -1;
	char buf[30] = {0};
	fd = open("test.txt",O_RDWR);
	if(fd < 0)
	{
		printf("open失败！\n");
		_exit(-1);
	}

	ret1 = lseek(fd,1,SEEK_SET);//从头开始
	printf("ret1=%d\n",ret1);//相对开始位置
	ret2 = read(fd,buf,30);//这里第三个参数竟然不能用strlen(buf)，怪哉
	printf("buf长度：%d\n",strlen(buf));
	printf("ret2=%d\n",ret2);//实际读取的字节
	printf("%s\n",buf);
	close(fd);
	return 0;
}






