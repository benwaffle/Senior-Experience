#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#define BUFSIZE 16

int main(int argc, char **argv) {
	FILE *tmpfd;

	static struct {
		char buf[BUFSIZE];
		char *tmpfile;
	} data;

	if (argc <= 1) {
		fprintf(stderr, "Usage: %s <garbage>\n", argv[0]);
		exit(-1);
	}

	printf("argv[1] is at %p and is %p\n", &argv[1], argv[1]);

	data.tmpfile = "/tmp/vulprog.tmp";
	printf("before: tmpfile = %s\n", data.tmpfile);
	printf("Enter one line of data to put in %s: ", data.tmpfile);
	gets(data.buf);
	printf("\ntmpfile = %s\n", data.tmpfile);

	tmpfd = fopen(data.tmpfile, "w");
	if (tmpfd == NULL) {
		fprintf(stderr, "error opening %s: %s\n", data.tmpfile, 
			strerror(errno));
		exit(-1);
	}

	fputs(data.buf, tmpfd);
	fclose(tmpfd);
}
