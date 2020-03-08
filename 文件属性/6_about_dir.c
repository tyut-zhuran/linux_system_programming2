//主要是关于opendir和readdir
# include <stdio.h>
# include <sys/types.h>
# include <dirent.h>
# include <unistd.h>
int main(int argc, char ** argv)
{

	DIR *pDir = NULL;
	struct dirent *pEnt = NULL;

	if(argc != 2)
	{
		printf("usage:%s dirname",argv[0]);
		return -1;
	}

	pDir = opendir(argv[1]);//man 3 opendir
	if(pDir == NULL)
	{
		perror("opendir");
		_exit(-1);
	}

	while(1)
	{
		pEnt = readdir(pDir);//man 3 readdir
		if(pEnt != NULL)
		{
			printf("name: %s ",pEnt->d_name);
			if(pEnt->d_type == DT_DIR)
			{
				printf("是目录");
			}
			printf("\n");
		}
		else
		{
			break;
		}
	}

	return 0;
}