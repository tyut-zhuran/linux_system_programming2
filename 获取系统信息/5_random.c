# include <stdlib.h>
# include <time.h>
# include <stdio.h>



int main()
{
	int temp=0;;
	srand(time(NULL));
	for(int i =0;i<10;i++)
	{
		temp = rand()%10;
		printf("%d  ",temp);
	}
	printf("\n");
	printf("RAND_MAX:%d\n",RAND_MAX);
	return 0;
}


