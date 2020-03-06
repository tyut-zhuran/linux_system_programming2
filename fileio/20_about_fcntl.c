//fcntl()管理文件


//这里用它完成一个dup功能

# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>


int main()
{

	int fd1 = -1;
	int fd2 = -1;

	fd1 = open("test.txt",O_RDWR|O_TRUNC|O_CREAT);

	fd2 = fcntl(fd1,F_DUPFD,5);//表示在大于等于5的数字中找出一个最小的作为返回值
	
	printf("fd1=%d\n",fd1);
	printf("fd2=%d\n",fd2);

	close(fd1);
	return 0;
}