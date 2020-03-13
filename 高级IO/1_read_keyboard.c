# include <stdio.h>
# include <unistd.h>
# include <string.h>


int main()
{
	char buf[100];


	memset(buf,0,sizeof(buf));

	read(0,buf,5);//0文件描述符会在进程开始时自动打开作为标准输入

	printf("键盘输入了：%s.\n",buf);

	return 0;
}



