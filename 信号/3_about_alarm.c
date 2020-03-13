# include <stdio.h>
# include <unistd.h>
# include <signal.h>



void func(int sig)
{
	printf("hanlde:%d\n",sig);
	_exit(0);
}
int main()
{
	struct sigaction act = {0};
	unsigned int ret = -1;
	act.sa_handler = func;
	
	sigaction(SIGALRM,&act,NULL);
	ret = alarm(5);
	while(1)
	{
		printf("ret = %d\n",ret);
		sleep(1);
	}
	return 0;
}