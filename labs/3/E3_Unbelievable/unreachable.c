#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int unbelievable (unsigned long d)
{

	if (d == 0xdeadbeef) {
		printf("I don't believe it!\n");
		exit(1);
	}

	printf("I believe it   \n");
	return 0;
}

void print_argument(char* arg)
{
	char buf[256];

	/* Oops! Vulnerable Code */
	strcpy(buf, arg);
	printf("argument: %s\n", buf);
}

int main(int argc, char* argv[]) 
{
	
	if (argc < 2) {
		printf("Give argument...\n");
	}

	print_argument(argv[1]);

	return 0;
}
