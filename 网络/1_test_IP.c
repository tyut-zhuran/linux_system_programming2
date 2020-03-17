/*

/usr/include/netinet/in.h
typedef uint32_t in_addr_t;
struct in_addr
{
	in_addr_t s_addr;
};



*/

# include <stdio.h>
# include <sys/socket.h>
# include <netinet/in.h>
# include <arpa/inet.h>
# define IPADDR "192.168.1.102"


void test_inet_addr()
{
	in_addr_t addr = 0;
	addr = inet_addr(IPADDR);
	printf("addr=0x%x.\n",addr);//6601a8c0
}
void test_inet_pton()
{
	struct in_addr addr = {0};
	int ret = -1;
	ret = inet_pton(AF_INET,IPADDR,&addr);
	if(ret != 1)
	{
		printf("test_inet_pton error!\n");
		return ;
	}
	printf("addr.saddr=0x%x.\n",addr.s_addr);
}

void test_inet_ntop()
{
	struct in_addr addr = {0};
	addr.s_addr = 0x6601a8c0;
	char ip_buf[50] = {0};

	if( NULL == inet_ntop(AF_INET,&addr,ip_buf,sizeof(ip_buf)))
	{
		printf("inet_ntop error!\n");
		return;
	}
	printf("ip_buf=%s.\n",ip_buf);
}


int main()
{
	test_inet_addr();
	test_inet_pton();
	test_inet_ntop();
	return 0;
}



