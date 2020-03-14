
//异步IO看起来有点像软件中断


# include <stdio.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <string.h>
# include <signal.h>

int mousefd = -1;


void func(int sig)
{
	char buf[100];
	if(sig != SIGIO)
	{
		perror("func");
		_exit(-1);
	}
	memset(buf,0,sizeof(buf));
	read(mousefd,buf,20);
	printf("从鼠标读到：[%s].\n",buf);
	return ;
}


int main()
{

	int ret = -1;
	char buf[100];
	int flag = -1;
	mousefd = open("/dev/input/mouse0",O_RDONLY);
	if(mousefd < 0)
	{
		perror("open");
		_exit(-1);
	}

	//设置鼠标文件的fd可以接受异步
	flag = fcntl(mousefd,F_GETFL);
	flag |= O_ASYNC;
	fcntl(mousefd,F_SETFL,flag);//汗~我为什么不直接open+O_ASYNC,实践证明不行，汗~~~

	//设置异步IO的接受进程为本进程
	fcntl(mousefd,F_SETOWN,getpid());

	//注册当前进程的SIFIO处理函数
	signal(SIGIO,func);


	//为了好看，我还是把0文件设置成非阻塞
	flag = fcntl(0,F_GETFL);
	flag |= O_NONBLOCK;
	fcntl(0,F_SETFL,flag);
	while(1)
	{
		memset(buf,0,sizeof(buf));
		ret = read(0,buf,20);
		if(ret > 0)
		{
			printf("键盘输入了：[%s].\n",buf);
		}
		else
		{
			printf("test...\n");
		}
		sleep(1);
	}
	close(mousefd);
	return 0;
}













