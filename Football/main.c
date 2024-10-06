#include <stdio.h>
#include "scorePossibilities.h"
#include "scanReset.h"

int main() {
    int score = -1;
    while (score != 1 && score != 0) {
        int valid;

        printf("Enter 0 or 1 to STOP\nEnter the NFL score:\t");
        valid = scanf("%d", &score);
        if (valid) {
            printf("\n");
            scorePossibilities(score);
        }
        else {
            // Case where a non-integer value was entered.
            printf("This program only works with integers.\n");
            scanReset();
        }
    }

    return 1;
}
