# include <stdio.h>
# include <pthread.h>
# include <unistd.h>

int main()
{
	int ret = -1;
	pthread_mutex_t mutex;

	ret = pthread_mutex_init(&mutex,NULL);
	if(ret != 0)
	{
		printf("pthread_mutex_init error.\n");
		_exit(0);
	}


	pthread_mutex_lock(&mutex);
	printf("some critical code.\n");
	pthread_mutex_unlock(&mutex);



	ret = pthread_mutex_destroy(&mutex);
	if(ret != 0)
	{
		printf("pthread_mutex_destroy error.\n");
		_exit(-1);
	}
	return 0;
}





