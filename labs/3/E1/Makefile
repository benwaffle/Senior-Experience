FLAGS = -fno-stack-protector -mpreferred-stack-boundary=2 -z execstack -g -static
FILES = heap.c


all:
	gcc $(FLAGS) $(FILES) -o heap 
clear:
	rm heap
