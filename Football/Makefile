all: main.o scorePossibilities.o scanReset.o
	gcc -o driver main.o scorePossibilities.o scanReset.o -Wall

main.o: main.c
	gcc -c main.c -Wall

scorePossibilities.o: scorePossibilities.h scorePossibilities.c
	gcc -c scorePossibilities.h scorePossibilities.c -Wall

scanReset.o: scanReset.c scanReset.h
	gcc -c scanReset.c scanReset.h -Wall

clean:
	rm -f *.o
	rm -f *.gch