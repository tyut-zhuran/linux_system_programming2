# include <stdio.h>
# include <sys/types.h>
# include <unistd.h>



int main()
{
	pid_t p1=-1;

	p1 = fork();//fork()函数会返回两次
	//若p1==0表示为子进程
	if(p1==0)
	{
		//子进程中p1为0
		printf("子进程：p1=%d,getpid=%d,getppid=%d\n",p1,getpid(),getppid());
		printf("子进程执行\n");
	}

	if(p1>0)
	{
		//父进程
		printf("父进程：p1=%d,getpid=%d\n",p1,getpid());
		printf("父进程执行\n");
	}

	if(p1<0)
	{
		//出错
	}
	printf("zhuran:%d\n",getpid());
	return 0;
}
