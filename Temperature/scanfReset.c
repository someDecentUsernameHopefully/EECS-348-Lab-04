#include <stdio.h>

void scanReset() {
	int c;
	while (c != "\n" && c != EOF) {
		c = getchar();
	}
}