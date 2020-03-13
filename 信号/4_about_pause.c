//pause()将当前的进程挂起。可以被信号退出


# include <stdio.h>
# include <signal.h>
# include <unistd.h>

void func(int sig)
{
	printf("alarm\n");
}
void mysleep(int sec)
{
	struct sigaction act = {0};

	act.sa_handler = func;
	sigaction(SIGALRM,&act,NULL);

	alarm(sec);
	pause();//这样当有信号到达时才会继续
	printf("exit mysleep\n");
}

int main()
{
	printf("before...\n");
	mysleep(3);
	printf("after...\n");
	return 0;
}




