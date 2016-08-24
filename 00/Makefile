main: main.o menu.o file_in.o linked_list.o linked_list2.o tree.o file_out.o node.h node2.h
	gcc -o main main.o menu.o file_in.o linked_list.o linked_list2.o tree.o file_out.o

main.o: main.c node.h node2.h
	gcc -c -o main.o main.c

menu.o: menu.c
	gcc -c -o menu.o menu.c

file_in.o: file_in.c
	gcc -c -o file_in.o file_in.c

linked_list.o: linked_list.c node.h
	gcc -c -o linked_list.o linked_list.c

linked_list2.o: linked_list2.c node.h
	gcc -c -o linked_list2.o linked_list2.c

tree.o: tree.c node2.h
	gcc -c -o tree.o tree.c

file_out.o: file_out.c node.h node2.h
	gcc -c -o file_out.o file_out.c

.PHONY:clean
clean:
	rm -f main
	rm -f *.o

.PHONY:all
all: clean main;
