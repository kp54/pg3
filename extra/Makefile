main: main.o
	gcc -o main main.o -lcrypto

main.o: main.c
	gcc -c -o main.o main.c

.PHONY:clean
clean:
	rm -f *.o
	rm -f main

.PHONY:all
all:clean main;
