#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define MAXLINE 64

#define TRY(func, name, cmpz) { \
	if ((func) cmpz 0) { \
		perror(name); \
		return -1; \
	} \
}

int readbuf(int sock, char *dest)
{
	char len = 0, buf[MAXLINE];
	TRY(recv(sock, &len, sizeof(len), 0), "recv(len)", <=)
	TRY(recv(sock, buf, len, 0), "recv(data)", <=)
	memcpy(dest, buf, MAXLINE);
	return 0;
}

int main()
{
	char buf[MAXLINE];
	int sock;
	TRY(sock = socket(PF_INET, SOCK_STREAM, 0), "socket()", <=)
	struct sockaddr_in ipport = {
		.sin_family = AF_INET,
		.sin_port = htons(8001),
		.sin_addr.s_addr = htonl(INADDR_ANY),
	};

	TRY(bind(sock, (struct sockaddr *)&ipport, sizeof(ipport)), "bind()", <)
	TRY(listen(sock, 10), "listen()", <)

	struct sockaddr_storage peer;
	socklen_t size = sizeof(peer);
	int conn_sock;
	TRY(conn_sock = accept(sock, (struct sockaddr *)&peer, &size), "accept()", <)

	while (readbuf(conn_sock, buf) != -1)
		printf("> %s\n", buf);
	close(conn_sock);
	close(sock);
	printf("you should not see this\n");
	printf("bye\n");
	return 0;
}

