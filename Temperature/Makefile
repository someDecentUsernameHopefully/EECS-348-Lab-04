all: main.o conversions.o responses.o scanReset.o
	gcc -o driver main.o conversions.o responses.o scanReset.o -Wall

main.o: main.c
	gcc -c main.c -Wall

conversions.o: conversions.h conversions.c
	gcc -c conversions.h conversions.c -Wall

responses.o: responses.h responses.c
	gcc -c responses.h responses.c -Wall

scanReset.o: scanReset.h scanReset.c
	gcc -c scanReset.h scanReset.c -Wall

clean:
	rm -f *.o
	rm -f *.gch