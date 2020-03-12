# include <stdio.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <errno.h>
# include <unistd.h>
# include <stdlib.h>



# define FILE "test_singleton_pattern"

void delete_file()
{
	remove(FILE);
}


int main()
{
	int fd = -1;
	fd = open(FILE,O_RDONLY|O_TRUNC|O_CREAT|O_EXCL);
	if(fd < 0)
	{
		if(errno == EEXIST)
		{
			printf("进程已经在运行\n");
			return -1;
		}
	}

	atexit(delete_file);

	for(int i = 0;i<10;i++)
	{
		printf("test...%d\n",i);
		sleep(1);
	}


	return 0;
}