//errno程序发生错误时，errno被设置为一个特定的值，
//表明是什么类型的错误，由操作系统来维护。
//实质是一个int类型

//perror() == print error
//可以输出错误信息
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdio.h>
# include <error.h>
# include <unistd.h>



int main()
{
	int fd = open("not_exist.txt",O_RDWR);
	if(fd < 0)
	{
		perror("文件打开错误！open");
		_exit(-1);
	}
	close(fd);
	return 0;
}









