//若文件已经打开，可以用fchmod用fd进行相同操作

# include <sys/stat.h>
# include <stdio.h>


int main(int argc, char * argv[])
{
	int ret = -1;
	if(argc != 2)
	{
		printf("usage: %s filename\n",argv[0]);
		return -1;
	}
	ret = chmod(argv[1],S_IRUSR|S_IWUSR|S_IXUSR);
	if(ret < 0)
	{
		perror("chmod");
		return -1;
	}
	return 0;
}
