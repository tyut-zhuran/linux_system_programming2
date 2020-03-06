# include <stdio.h>
# include <stdlib.h>




int main()
{
	FILE* fp = NULL;
	fp = fopen("test.txt","r");
	char buf[100] = {0};
	size_t len = 0;
	if(fp == NULL)
	{
		perror("fopen");
		exit(-1);
	}
	printf("fd=%p\n",fp);
	len = fread(buf,sizeof(buf[0]),sizeof(buf)/sizeof(buf[0]),fp);
	printf("sizeof(buf[0])=%d\n",sizeof(buf[0]));
	printf("sizeof(buf)=%d\n",sizeof(buf));
	printf("len=%d\n",len);
	printf("%s\n",buf);
	fclose(fp);
	return 0;
}


