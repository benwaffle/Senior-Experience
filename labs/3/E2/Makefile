FLAGS = -fno-stack-protector -mpreferred-stack-boundary=2 -z execstack -g -static
FILES = global.c


all:
	gcc $(FLAGS) $(FILES) -o global 
clear:
	rm global
