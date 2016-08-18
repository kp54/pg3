main: main.o linked_list.o
	gcc -o main main.o linked_list.o

main.o: main.c node.h
	gcc -c -o main.o main.c

linked_list.o: linked_list.c node.h
	gcc -c -o linked_list.o linked_list.c

.PHONY:clean
clean:
	rm -f main
	rm -f *.o

.PHONY:all
all: clean main;
