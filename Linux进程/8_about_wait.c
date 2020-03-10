# include <stdio.h>
# include <sys/types.h>
# include <unistd.h>
# include <sys/wait.h>

int main()
{
	pid_t pid=-1;
	pid_t ret=-1;
	int status=-1;
	pid = fork();
	if(pid==0)
	{
		printf("子进程：pid=%d\n",getpid());
	}
	if(pid>0)
	{
		ret = wait(&status);//返回值ret是子进程的pid，status是退出的状态
		printf("父进程：ret=%d,status=%d\n",ret,status);
	}
	if(pid<0)
	{
		perror("fork");
		_exit(-1);
	}
	return 0;
}