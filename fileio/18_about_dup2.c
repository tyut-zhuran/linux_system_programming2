//dup2和dup作用是一样的，但是它允许指定fd的值



# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>


int main()
{
	int fd1 = -1;
	int fd2 = -1;

	fd1 = open("test.txt",O_RDWR|O_CREAT|O_TRUNC);
	fd2 = dup2(fd1,16);

	printf("fd1=%d\n",fd1);
	printf("fd2=%d\n",fd2);
	close(fd1);
	return 0;
}



