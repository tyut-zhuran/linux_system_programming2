# include <stdio.h>
# include <signal.h>
# include <unistd.h>

void func(int sig)
{

	printf("handle sig:%d\n",sig);
	_exit(0);
}

int main()
{
	signal(SIGINT,func);//SIG_IGN忽略，SIG_DFL默认
	while(1)
	{
		printf("test...\n");
		sleep(1);
	}
	return 0;
}