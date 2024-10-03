all: main.o scorePossibilities.o
	gcc -o driver main.o arrayAdd.o scorePossibilities.o -Wall

main.o: main.c
	gcc -c main.c -Wall

scorePossibilities.o: scorePossibilities.h scorePossibilities.c
	gcc -c scorePossibilities.h scorePossibilities.c -Wall

clean:
	rm -f *.o