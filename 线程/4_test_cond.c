# include <stdio.h>
# include <pthread.h>
# include <string.h>
# include <unistd.h>

char buf[200];
pthread_mutex_t mutex;
pthread_cond_t cond;


void *func(void * val)
{
	while(1)
	{
		pthread_mutex_lock(&mutex);
		pthread_cond_wait(&cond,&mutex);
		
		
		if(strcmp(buf,"end") == 0)
		{
			printf("test in func.end.\n");
			break;
		}
		printf("test in func. buf=%s.\n",buf);
		pthread_mutex_unlock(&mutex);
		memset(buf,0,sizeof(buf));
	}
	pthread_exit(NULL);	
}

int main()
{
	pthread_t th;
	pthread_create(&th,NULL,func,NULL);
	pthread_mutex_init(&mutex,NULL);
	pthread_cond_init(&cond,NULL);

	printf("输入字符串然后回车（end退出程序）。\n");
	while(1)
	{
		scanf("%s",buf);
		pthread_cond_signal(&cond);
		if(strcmp("end",buf) == 0)
		{
			break;
		}
	}


	pthread_join(th,NULL);

	pthread_cond_destroy(&cond);
	pthread_mutex_destroy(&mutex);
	printf("程序退出！\n");
	return 0;
}


