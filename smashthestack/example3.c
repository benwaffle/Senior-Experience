void function(int a, int b, int c) {
	char buffer1[5];
	char buffer2[10];
	int *ret;

	ret = buffer1 + 16 + 8;
	(*ret) += 7;
}

int main() {
	int x;
	
	x = 0;
	function(1,2,3);
	x = 1;
	printf("%d\n", x);
}
