# include <stdio.h>
# include <sys/types.h>
# include <unistd.h>
# include <sys/wait.h>


int main()
{

	pid_t pid = -1;
	int status = -1;
	int ret = -1;
	pid = fork();
	if(pid == 0)
	{
		//子进程
		sleep(1);
		printf("child：%d\n",getpid());
	}
	if(pid > 0)
	{
		//父进程
		//此时pid的值为子进程的pid
		//第一个参数若为-1表示等待任意一个子进程
		//第三个参数0表示使用默认阻塞式
		//若第一个参数不是其子进程会返回-1
		//若子进程未结束会返回0
		//ret = waitpid(pid,&status,0);
		ret = waitpid(pid,&status,WNOHANG);
		printf("parent:ret=%d\n",ret);
		printf("parent:%d\n",getpid());
		printf("子进程是否正常退出？%d\n",WIFEXITED(status));
		printf("子进程非正常退出？%d\n",WIFSIGNALED(status));

	}
	if(pid < 0)
	{
		//出错
		
		perror("fork");
		_exit(-1);
	}



	return 0;
}

