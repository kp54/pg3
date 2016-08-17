main: main.o file_in.o
	gcc -o main main.o file_in.o

main.o: main.c
	gcc -c -o main.o main.c

file_in.o: file_in.c
	gcc -c -o file_in.o file_in.c

.PHONY:clean
clean:
	rm -f main
	rm -f *.o

.PHONY:all
all: clean main;
