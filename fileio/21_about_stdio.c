//C语言库函数中的文件读写

# include <stdio.h>
# include <stdlib.h>



int main()
{

	FILE* fp = NULL;
	size_t len;
	fp = fopen("test.txt","w+");
	if(NULL == fp)
	{
		perror("fopen");
		exit(-1);
	}

	printf("fp = %p\n",fp);

	len = fwrite("abcde",1,5,fp);//每个元素1个字节，共写5个元素
	printf("fd=%d\n",len);
	fclose(fp);
	return 0;
}