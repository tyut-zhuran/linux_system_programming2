//这里用O_APPEND参数完成文件的“接续写”


# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>


int main()
{

	int fd1=-1;
	int fd2=-1;
	//fd1 = open("temp.txt",O_WRONLY|O_TRUNC|O_CREAT);
	//fd2 = open("temp.txt",O_WRONLY|O_TRUNC|O_CREAT);
	//这样写就是各自文件指针独立


	//O_APPEND参数完成接续写文件
	//其内部原理就是在read和write完成之后，虽然文件指针还是两个，但会同步更新
	//此时对文件的读写是原子操作
	fd1 = open("temp.txt",O_WRONLY|O_TRUNC|O_CREAT|O_APPEND);
	fd2 = open("temp.txt",O_WRONLY|O_TRUNC|O_CREAT|O_APPEND);
	for(int i=0;i<10;i++)
	{
		write(fd1,"ab",2);
		write(fd2,"cd",2);
	}
	close(fd1);
	close(fd2);
	return 0;
}




