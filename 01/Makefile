main: main.o menu.o
	gcc -o main main.o menu.o

main.o: main.c
	gcc -c -o main.o main.c

menu.o: menu.c
	gcc -c -o menu.o menu.c

.PHONY:clean
clean:
	rm -f main
	rm -f *.o

.PHONY:all
all: clean main;
