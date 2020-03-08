/*

若文件已经打开，可以用fstat获取文件信息（效率高，直接从内存获取）
如文件未打开，用stat


对于符号链接，stat和fstat可以获取符号链接指向文件的属性，而lstat获取的是
符号链接文件本身的属性


*/


# include <sys/types.h>
# include <sys/stat.h>
# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <error.h>
int main()
{
	int ret = -1;
	struct stat buf;
	memset(&buf,0,sizeof(buf));



	ret = stat("test.txt",&buf);
	if(ret < 0)
	{
		perror("stat错误！\n");
		_exit(-1);
	}
	printf("inode = %ld\n",buf.st_ino);
	printf("size = %d\n",buf.st_size);

	return 0;
}








