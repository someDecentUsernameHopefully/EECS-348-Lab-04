#include <stdio.h>
#include "scorePossibilities.h"
int main() {
    int score = 1000;
    while (score > 1) {
        printf("Enter 0 or 1 to STOP\nEnter the NFL score:\t");
        scanf("%d", &score);
        scorePossibilities(score);
    }

    return 1;
}
