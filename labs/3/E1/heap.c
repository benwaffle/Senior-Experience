#include <sys/types.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int
main(int argc, char *argv[])
{
#define BUFSIZE 16
	char *buf = malloc(BUFSIZE);
	int *magic = malloc(sizeof (int));

	if (argv[1] == NULL) {
		fprintf(stderr, "Usage: %s input\n", argv[0]);
		exit(1);
	}

	memset(magic, 0, sizeof magic);
	strcpy(buf, argv[1]);

	if (*magic == 664)
		printf("You win!\n");
	else
		printf("You lose...\n");

	return (0);
}
