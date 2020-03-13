# include <stdio.h>
# include <unistd.h>
# include <string.h>
# include <fcntl.h>

int main()
{
	char buf[100];
	int flag = -1 ;

	//将读取键盘操作设置为非阻塞
	flag = fcntl(0,F_GETFL);
	flag |= O_NONBLOCK;
	fcntl(0,F_SETFL,flag);

	for(int i=0;i<5;i++)
	{

		sleep(1);
		memset(buf,0,sizeof(buf));

		read(0,buf,5);

		printf("键盘输入了:[%s].\n",buf);
	
	}
	

	return 0;
}

