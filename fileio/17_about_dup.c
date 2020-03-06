//dup对文件描述符进行复制，会返回一个新的文件描述符
//两个文件描述符操作同一个文件，实际构成了文件共享
//dup函数并不能确定返回的fd,(实际上dup2可以)

//若关闭标准输出流（fd=1），可以用这个函数实现标准输出重定向
//close(1);fd2 = dup(fd1);这时fd2一定是1，也就是标准输出
//之后进行printf()函数就会输出到相应文件



# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include <error.h>


int main()
{
	int fd1 =-1;
	int fd2 = -1;

	fd1 = open("test.txt",O_RDWR|O_CREAT|O_TRUNC);
	if(fd1 <0)
	{
		perror("open");
		_exit(-1);
	}
	printf("fd1= %d\n",fd1);

	//close(1);
	fd2 = dup(fd1);
	printf("fd2= %d\n",fd2);

	close(fd1);
	//close(fd2);//这一行多余因为这两个fd操作的是同一个文件

	return 0;
}

