//dup实现的文件共享可以实现接续写



# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include <error.h>


int main()
{

	int fd1 = -1;
	int fd2 = -1;

	fd1 = open("test.txt",O_RDWR|O_TRUNC|O_CREAT);
	if(fd1 < 0)
	{
		perror("open");
		_exit(0);
	}
	fd2 = dup2(fd1,10);


	for(int i = 0;i<10;i++)
	{
		write(fd1,"aa",2);
		sleep(1);
		write(fd2,"bb",2);
	}


	close(fd1);

	return 0;
}



