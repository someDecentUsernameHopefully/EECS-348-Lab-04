#include <stdio.h>
#include "scorePossibilities.h"

void scorePossibilities(int score) {
	int startingScores[5] = {0, 0, 0, 0, 0};
	scorePossibilitiesRecursive(score, startingScores);
}

void scorePossibilitiesRecursive(int score, int previousScoreTypes[]) {
	if (score >= 8) {

	}
}