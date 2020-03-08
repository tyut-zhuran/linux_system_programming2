/*

用代码判断文件类型
struct stat 有一属性(mode_t st_mode)

*/


# include <sys/stat.h>
# include <sys/types.h>
# include <unistd.h>
# include <stdio.h>
# include <string.h>

int main()
{
	int ret = -1;
	struct stat buf;
	memset(&buf,0,sizeof(buf));

	ret = stat("test.txt",&buf);
	if(ret < 0)
	{
		perror("stat错误");
		_exit(-1);
	}


//判断文件类型更多宏可通过man inode 7查看
	ret = S_ISREG(buf.st_mode);
	if(ret)
	{
		printf("普通文件\n");
	}
	else
	{
		printf("不是普通文件\n");
	}

	//还可以获取文件权限
	if(buf.st_mode & S_IRUSR == S_IRUSR)
	{
		printf("user有read权限\n");
	}
	if(buf.st_mode & S_IWUSR == S_IWUSR)
	{
		printf("user有write权限\n");
	}
	if(buf.st_mode & S_IXUSR == S_IXUSR)
	{
		printf("user有执行权限\n");
	}
	printf("buf.st_mode=%o\n",buf.st_mode);


	return 0;
}




