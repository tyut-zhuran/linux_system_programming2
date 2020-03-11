# include <stdio.h>
# include <sys/types.h>
# include <unistd.h>
# include <sys/wait.h>


//关于execl,execv   man exec
//还有一个execle关于环境变量的这里略过了
int main()
{
	pid_t pid=-1;
	int status = -1;
	int ret = -1;
	char * arg[] = {"ls","-l","-a",NULL};

	pid = fork();

	if(pid==0)
	{
		//子进程
		//execl("/bin/ls","ls","-l","-a",NULL);
		//execv("/bin/ls",arg);//其实他们差异很小
		//execl("./hello","hello","zhu","ran",NULL);
		//execlp和execvp除了会在指定路径找命令外还会在环境变量中找
		execlp("ls","ls","-l","-a",NULL);
	}
	if(pid>0)
	{
		//父进程
		printf("parent:%d\n",getpid());
		ret = waitpid(pid,&status,0);
		printf("end,ret=%d\n",ret);
	} 
	if(pid<0)
	{
		//出错
		perror("fork");
		_exit(-1);
	}
	return 0;
}





