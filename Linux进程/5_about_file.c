# include <stdio.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>



//父进程中打开文件之后，在父子进程中分别写入，该操作为接续写
//如果实在两个程序中各自打开写，那么结果为分别写。若用O_APPEND参数打开可变为接续写
int main()
{
	int fd = -1;
	pid_t pid = -1;
	fd = open("test.txt",O_RDWR|O_CREAT|O_TRUNC);
	if(fd < 0)
	{
		perror("open");
		_exit(-1);
	}
	pid = fork();
	if(pid == 0)
	{
		//子进程
		write(fd,"child",5);
		sleep(1);//防止实验中该进程先运行完然后将程序结束
	}
	if(pid > 0)
	{
		//父进程
		write(fd,"parent",6);
		sleep(1);;
		close(fd);
	}
	if(pid < 0)
	{
		//出错
		perror("fork");
		_exit(-1);
	}
	return 0;


}