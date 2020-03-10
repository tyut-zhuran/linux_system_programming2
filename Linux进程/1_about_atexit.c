# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>


void func1()
{
	printf("func1\n");
}
void func2()
{
	printf("func2\n");
}
int main()
{
	printf("zhuran\n");
	

	//程序在正常终止(return/exit)是会执行这两个函数
	//并且先注册的后执行（栈结构）
	//但是_exit()函数不会执行
	atexit(func1);
	atexit(func2);
	printf("exit\n");
	//exit(0);
	//_exit(0);
	return 0;
}
