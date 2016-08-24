.PHONY:none
none:;

a.out: file_out_a.o
	gcc -o a.out file_out_a.o

b.out: file_out_b.o linked_list.o linked_list2.o node.h
	gcc -o b.out file_out_b.o linked_list.o linked_list2.o

c.out: file_out_c.o linked_list.o linked_list2.o tree.o node.h node2.h
	gcc -o c.out file_out_c.o linked_list.o linked_list2.o tree.o

file_out_a.o: file_out_a.c
	gcc -c -o file_out_a.o file_out_a.c

file_out_b.o: file_out_b.c
	gcc -c -o file_out_b.o file_out_b.c

file_out_c.o: file_out_c.c
	gcc -c -o file_out_c.o file_out_c.c

linked_list.o: linked_list.c node.h
	gcc -c -o linked_list.o linked_list.c

linked_list2.o: linked_list2.c node.h
	gcc -c -o linked_list2.o linked_list2.c

tree.o: tree.c node2.h
	gcc -c -o tree.o tree.c

.PHONY:clean
clean:
	rm -f *.o
	rm -f *.out
