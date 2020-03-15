# include <stdio.h>
# include <string.h>
# include <pthread.h>
# include <semaphore.h>
# include <unistd.h>

//编译链接 gcc filename -lpthread

sem_t sem;
char buf[100];


void *func(void *val)
{
	while(1)
	{
		sem_wait(&sem);
		if(strcmp(buf,"end") == 0)
		{
			break;
		}
		printf("test in func. buf=%s.\n",buf);
		memset(buf,0,sizeof(buf));
	}
	sem_wait(&sem);
	pthread_exit(NULL);
}

//思路:主线程中完成输入功能，在子线程中进行输出结果
int main()
{

	
	int ret = -1;
	pthread_t thread = -1;
	ret = pthread_create(&thread,NULL,func,NULL);
	if(ret != 0)
	{
		printf("线程创建错误！\n");
		_exit(-1);
	}
	sem_init(&sem,0,0);


	printf("从键盘输入字符(end退出程序):\n");
	while(1)
	{

		scanf("%s",buf);
		sem_post(&sem);
		if(strcmp(buf,"end") == 0)
		{
			break;
		}
	}
	sem_post(&sem);


	printf("before join.\n");
	ret = pthread_join(thread,NULL);
	if(ret != 0)
	{
		printf("join error.\n");
	}
	printf("after join.\n");

	printf("before destroy.\n");
	ret = sem_destroy(&sem);
	if(ret != 0)
	{
		perror("sem_destroy");
		_exit(-1);
	}
	printf("after destroy.\n");
	return 0;
}





