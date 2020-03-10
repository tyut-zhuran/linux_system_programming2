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
		return 93;
	}
	if(pid>0)
	{
		ret = wait(&status);//返回值ret是子进程的pid，status是退出的状态
		printf("父进程：ret=%d,status=%d\n",ret,status);

		printf("是否正常退出？%d\n",WIFEXITED(status));
		printf("是否非正常退出？%d\n",WIFSIGNALED(status));
		printf("正常退出时的返回值：%d\n",WEXITSTATUS(status));

	}
	if(pid<0)
	{
		perror("fork");
		_exit(-1);
	}
	return 0;
}