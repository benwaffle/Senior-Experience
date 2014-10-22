FLAGS = -fno-stack-protector -mpreferred-stack-boundary=2 -z execstack -g -static
FILES = hello.c


all:
	gcc $(FLAGS) $(FILES) -o hello
clear:
	rm hello
