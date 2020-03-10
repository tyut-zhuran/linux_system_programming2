# include <stdio.h>
# include <sys/types.h>
# include <unistd.h>


int main()
{
	pid_t pid = -1;

	pid = fork();

	if(pid==0)
	{
		//子进程
		sleep(1);//使它变成一个孤儿进程
		printf("pid=%d,ppid=%d\n",getpid(),getppid());
	}
	if(pid>0)
	{
		//父进程
	}
	if(pid<0)
	{
		//出错
		perror("fork");
		_exit(-1);
	}
	return 0;	
}