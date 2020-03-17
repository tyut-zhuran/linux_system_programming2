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

# define MYIP "192.168.144.1"//本机IP
# define MYPORT 6000 //端口
# define BACKLOG 100//最大排队数
int main()
{
	int sockfd = -1;
	int ret = -1;
	int connect_fd = -1;
	struct sockaddr_in sockaddr = {0};
	char recvbuf[100] = {0};
	struct sockaddr_in client_sockaddr = {0};
	socklen_t len = 0;//这个没看懂干啥用的
	//1、socket
	sockfd = socket(AF_INET,SOCK_STREAM,0);
	if(sockfd < 0)
	{
		perror("socket");
		return -1;
	}

	printf("sockfd=%d.\n",sockfd);


	//2、bind
	sockaddr.sin_family = AF_INET;
	sockaddr.sin_port = htons(MYPORT);//将端口号由主机序列转为网络序列（因为两种序列大小端可能不同）
	sockaddr.sin_addr.s_addr = inet_addr(MYIP);

	ret = bind(sockfd,(const struct sockaddr*)&sockaddr,sizeof(sockaddr));
	if(ret < 0)
	{
		perror("bind");
		return -1;
	}
	printf("bind success!\n");

	//3、listen
	ret = listen(sockfd,BACKLOG);
	if(ret < 0)
	{
		perror("listen");
		return -1;
	}
	printf("listen...\n");

	//4、accept
	//会阻塞
	//其实返回的是一个fd
	connect_fd = accept(sockfd,(struct sockaddr*)&client_sockaddr,&len);
	if(connect_fd < 0)
	{
		perror("accept");
		return -1;
	}
	printf("服务端OK.connect_fd=%d.\n",connect_fd);


	//5、通信
	/*
	ret = recv(connect_fd,recvbuf,sizeof(recvbuf),0);
	if(ret < 0)
	{
		perror("recv");
		return -1;
	}
	printf("接收成功。共收到%d个字节。内容是%s.\n",ret,recvbuf);
	*/
	while(1)
	{
		memset(recvbuf,0,sizeof(recvbuf));
		ret = recv(connect_fd,recvbuf,sizeof(recvbuf),0);
		if(ret < 0)
		{
			perror("recv");
			return -1;
		}
		if(strncmp(recvbuf,"end",3) == 0)
		{
			printf("客户端已退出！\n");
			break;
		}
		printf("收到信息：%s\n",recvbuf);
		//printf("接收成功。共收到%d个字节。内容是%s.\n",ret,recvbuf);
	}
	return 0;
}












