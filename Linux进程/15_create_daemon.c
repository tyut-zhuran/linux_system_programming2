# include <stdio.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>


void create_daemon();

int main()
{
	create_daemon();


	while(1)
	{
		printf("zhuran\n");
		sleep(1);
	}
	return 0;
}



void create_daemon()
{
	//1、子进程等待父进程退出
	pid_t pid = -1;
	pid = fork();
	if(pid > 0)
	{
		//父进程
		_exit(0);
	}
	if(pid < 0)
	{
		//出错
		perror("fork");
		_exit(-1);
	}
	if(pid == 0)
	{
		//子进程
		//2、子进程脱离控制台
		//可以用setsid()函数创建新的会话期
		pid = setsid();
		if(pid < 0)
		{
			perror("setsid");
			_exit(-1);
		}

		//3、调用chdir()函数将当前工作目录设置为根目录
		chdir("/");

		//4、设置umask()设置为0取消文件的权限屏蔽
		umask(0);

		//5、关闭所有文件描述符
		for(long  fd = 0;fd < sysconf(_SC_OPEN_MAX);fd ++)
		{
			close(fd);
		}


		//6、重定向012三个文件
		open("/dev/null",O_RDWR);
		open("/dev/null",O_RDWR);
		open("/dev/null",O_RDWR);


	}
}





