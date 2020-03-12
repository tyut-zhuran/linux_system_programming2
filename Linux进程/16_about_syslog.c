# include <stdio.h>
# include <syslog.h>
# include <sys/types.h>
# include <unistd.h>

int main()
{
	printf("pid=%d\n",getpid());
		
	openlog("zhuran_for_test",LOG_CONS|LOG_PID,LOG_USER);
	syslog(LOG_INFO,"this is a test info.");
	closelog();


	return 0;
}