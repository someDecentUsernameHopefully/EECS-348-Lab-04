#include <stdio.h>
#include "scorePossibilities.h"
int main() {
    int score = 1000;
    while (score != 1 && score != 0) {
        printf("Enter 0 or 1 to STOP\nEnter the NFL score:\t");
        scanf("%d", &score);
        printf("\n");
        scorePossibilities(score);
    }

    return 1;
}
