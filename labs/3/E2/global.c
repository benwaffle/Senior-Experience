#include <sys/types.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define BUFSIZE 16
static char buf[BUFSIZE];
static int magic; /* naming affects order if not static! */

int
main(int argc, char *argv[])
{
	if (argv[1] == NULL) {
		fprintf(stderr, "Usage: %s input\n", argv[0]);
		exit(1);
	}

	strcpy(buf, argv[1]);

	if (magic == 1337)
		printf("You win!\n");
	else
		printf("You lose...\n");

	return (0);
}
