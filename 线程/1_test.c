# include <stdio.h>
# include <string.h>


int main()
{
	char buf[100];
	printf("输入字符串可以得到字符串的长度(end表示结束)：\n");
	while(scanf("%s",buf))
	{
		if(strncmp(buf,"end",3) == 0)
		{
			printf("退出程序!\n");
			break;
		}
		printf("共%d个字符。\n",strlen(buf));
		memset(buf,0,sizeof(buf));
	}
	return 0;
}

