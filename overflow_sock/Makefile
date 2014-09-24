CFLAGS=-std=c11 -ggdb -Wall -fno-stack-protector

all: server client

server:
	$(CC) $(CFLAGS) -o server server.c

client:
	$(CC) $(CFLAGS) -o client client.c

clean:
	rm server client
