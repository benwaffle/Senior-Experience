#include <stdio.h>

int main() {
	int i = 5;
	char userinput[] = "\x10\x01\x48\x08_%08x.%08x.%08x.%08x.%08x|%s|";
	int j = 4;
	printf(userinput);
}
