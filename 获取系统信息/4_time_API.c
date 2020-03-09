//mktime一般用来设置时间
//asctime输出和ctime一样，具体使用查看man 3 asctime
//strftime

//直接用struct tm的指针可能出现野指针的问题，有空要解决一下



# include <time.h>
# include <stdio.h>
# include <string.h>

# include <sys/time.h>
int main()
{

	time_t tNow=0;
	time_t mkNow=0;
	struct tm tmNow;
	int ret=0;
	char buf[100];


	struct timeval tv;
	struct timezone tz;
	memset(buf,0,100);
	tNow = time(NULL);
	if(tNow < 0)
	{
		perror("time");	
		return -1;
	}

	memset(&tmNow,0,sizeof(struct tm));
	gmtime_r(&tNow,&tmNow);
	//printf("%d\n",p_tmNow->tm_year);
	mkNow = mktime(&tmNow);
	printf("mktimr:%ld\n",mkNow);


	printf("asctime:%s\n",asctime(&tmNow));


	//man 3 strftime

	ret = strftime(buf,sizeof(buf),"%Y年%m月%d日，%H时%M分%S秒",&tmNow);
	printf("strftime: ret = %d\n当前时间:%s\n",ret,buf);


	//gettimeofday
	gettimeofday(&tv,&tz);
	printf("seconds:%ld,microseconds:%ld\n",tv.tv_sec,tv.tv_usec);
	printf("timezone(for minutes/west is +):%d\n",tz.tz_minuteswest);
	return 0;
}







