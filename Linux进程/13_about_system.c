//system函数=fork+exec

# include <stdio.h>
# include <stdlib.h>



int main()
{
	int ret = -1;
	ret = system("ls -a -l");
	printf("ret=%d\n",ret);
	return 0;
}



