main: main.o menu.o file_in.o linked_list.o linked_list2.o node.h
	gcc -o main main.o menu.o file_in.o linked_list.o linked_list2.o

main.o: main.c node.h
	gcc -c -o main.o main.c

menu.o: menu.c
	gcc -c -o menu.o menu.c

file_in.o: file_in.c
	gcc -c -o file_in.o file_in.c

linked_list.o: linked_list.c node.h
	gcc -c -o linked_list.o linked_list.c

linked_list2.o: linked_list2.c node.h
	gcc -c -o linked_list2.o linked_list2.c

.PHONY:clean
clean:
	rm -f main
	rm -f *.o

.PHONY:all
all: clean main;
