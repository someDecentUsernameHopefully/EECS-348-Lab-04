all: main.o conversions.o responses.o
	gcc -o driver main.o conversions.o responses.o -Wall

main.o: main.c
	gcc -c main.c -Wall

conversions.o: conversions.h conversions.c
	gcc -c conversions.h conversions.c -Wall

responses.o: responses.h responses.c
	gcc -c responses.h responses.c -Wall

clean:
	rm -f *.o
	rm -f *.gch