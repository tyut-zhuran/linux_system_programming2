# include <time.h>
# include <stdio.h>
# include <string.h>

int main()
{
	time_t tNow=0;
	
	struct tm tmNow;



	tNow = time(NULL);//time(&tNow)
	if(tNow<0)
	{
		perror("time");
		return -1;

	}

	printf("time:%ld\n",tNow);
	printf("ctime:%s\n",ctime(&tNow));

	//gmtime
	memset(&tmNow,0,sizeof(tmNow));
	gmtime_r(&tNow,&tmNow);
	printf("Year:%d,Mon:%d,Day:%d,Hour:%d\n",tmNow.tm_year,tmNow.tm_mon,tmNow.tm_mday,tmNow.tm_hour);

	//localtime
	memset(&tmNow,0,sizeof(tmNow));
	localtime_r(&tNow,&tmNow);
	printf("Year:%d,Mon:%d,Day:%d,Hour:%d\n",tmNow.tm_year,tmNow.tm_mon,tmNow.tm_mday,tmNow.tm_hour);
	return 0;


}

