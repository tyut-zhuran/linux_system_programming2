# include <stdio.h>
# include <sys/types.h>
# include <unistd.h>

int main()
{
	pid_t p1=-1,p2=-1;
	p1 = getpid();
	p2 = getppid();

	printf("pid=%d\n",p1);
	printf("ppid=%d\n",p2);
	return 0;
}
