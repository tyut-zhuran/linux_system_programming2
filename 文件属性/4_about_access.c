//判断当前用户在当前环境是否具有某种权限



# include <stdio.h>
# include <unistd.h>

# include <string.h>

int main()
{
	int ret = -1;
	//struct stat buf;
	//memset(&buf,0,sizeof(buf));

/*
	ret = stat("test.txt",&buf);
	if(ret < 0)
	{
		perror("stat");
		_exit(-1);
	}

*/
	ret = access("test.txt",F_OK);
	if(ret == 0)
	{
		printf("文件存在\n");
	}

	ret = access("test.txt",R_OK);
	if(ret == 0)
	{
		printf("文件可读\n");
	}

	ret = access("test.txt",W_OK);
	if(ret == 0)
	{
		printf("文件可写\n");
	}

	ret = access("test.txt",X_OK);
	if(ret == 0)
	{
		printf("文件可执行\n");
	}
	return 0;
}















