#include <stdio.h>

void scanReset() {
	// This code just flushes out anything in the scanf results so new inputs can be made.
	int c;
	while (c != '\n' && c != EOF) {
		c = getchar();
	}
}