FLAGS = -fno-stack-protector -mpreferred-stack-boundary=2 -z execstack -g -static
FILES = unreachable.c


all:
	gcc $(FLAGS) $(FILES) -o unreachable 
clear:
	rm unreachable
