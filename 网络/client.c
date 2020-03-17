/*

/usr/include/netinet/in.h
typedef uint32_t in_addr_t;
struct in_addr
{
	in_addr_t s_addr;
};
typedef uint16_t in_port_t;
struct sockaddr_in
{
	_SOCKADDR_COMMON(sin_);
	in_port_t sin_port;
	struct in_addr sin_addr;
	...	
}

*/

# include <stdio.h>
# include <sys/types.h>
# include <sys/socket.h>
# include <arpa/inet.h>
# include <string.h>
# include <unistd.h>

# define SERVER_IP "192.168.144.1"
# define SERVER_PORT 6000 
int main()
{
	int sockfd = -1;
	int ret = -1;
	struct sockaddr_in server_sockaddr = {0};
	char sendbuf[100];
	//1、socket
	sockfd = socket(AF_INET,SOCK_STREAM,0);
	if(sockfd < 0)
	{
		perror("socket");
		return -1;
	}

	//2、connect
	server_sockaddr.sin_family = AF_INET;
	server_sockaddr.sin_addr.s_addr = inet_addr(SERVER_IP);
	server_sockaddr.sin_port = htons(SERVER_PORT);
	ret = connect(sockfd,(const struct sockaddr*)&server_sockaddr,sizeof(server_sockaddr));
	if(ret < 0)
	{
		perror("connect");
		return -1;
	}
	printf("客户端OK.sockfd=%d.\n",sockfd);

	//3、通信
	/*
	memset(sendbuf,0,sizeof(sendbuf));
	strcpy(sendbuf,"zhuran");
	ret = send(sockfd,sendbuf,strlen(sendbuf),0);
	if(ret < 0)
	{
		perror("send");
		return -1;
	}
	printf("发送成功，共发送了%d个字节。\n",ret);
	*/

	while(1)
	{
		memset(sendbuf,0,sizeof(sendbuf));
		printf("输入要发送的内容(输入end结束)：");
		scanf("%s",sendbuf);

		ret = send(sockfd,sendbuf,strlen(sendbuf),0);
		if(ret < 0)
		{
			perror("send");
			return -1;
		}
		if(strcmp(sendbuf,"end") == 0)
		{
			printf("退出客户端。\n");
			break;
		}
		
		printf("发送成功，共发送了%d个字节。\n",ret);
	}
	return 0;
}








