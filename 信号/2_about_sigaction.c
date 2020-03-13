# include <stdio.h>
# include <signal.h>
# include <unistd.h>

void func(int sig)
{
	printf("handle sig:%d\n",sig);
	_exit(-1);
}
int main()
{
	struct sigaction sig = {0};//不初始化会出问题（无法调用func）
	sig.sa_handler = func;
	//sig.sa_flags = 0;//这个标志应该很少用

	sigaction(SIGINT,&sig,NULL);
	while(1)
	{
		printf("test...\n");
		sleep(1);
	}
	return 0;
}

