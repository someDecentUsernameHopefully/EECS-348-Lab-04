#include <stdio.h>
#include "scorePossibilities.h"

// Man, I wish I had access to objects here... would make my life much easier.

void scorePossibilities(int score) {
	int startingScores[5] = {0, 0, 0, 0, 0};
	int usedScores[0][5] = {};
	scorePossibilitiesRecursive(score, startingScores, &usedScores);
}

void scorePossibilitiesRecursive(int score, int previousScoreTypes[], int usedScores[][5]) {
	recursiveHelperFunction(score, previousScoreTypes, 8, 0, usedScores);
	recursiveHelperFunction(score, previousScoreTypes, 7, 1, usedScores);
	recursiveHelperFunction(score, previousScoreTypes, 6, 2, usedScores);
	recursiveHelperFunction(score, previousScoreTypes, 3, 3, usedScores);
	recursiveHelperFunction(score, previousScoreTypes, 2, 4, usedScores);
}

void recursiveHelperFunction(int score, int scoreTypes[], int scoreCost, int typeIndex, int usedScores[][5]) {
	// I could copy and paste this into scorePossibilitiesRecursive 5 times,
	// but I remember an old saying: don't repeat yourself.

	if (score >= scoreCost) {
		int newScore = score - scoreCost;

		// Read scoreTypes into new variable
		// It seems like altering the values of an array passed into this affects the array itself.
		int newScoreTypes[5];
		for (int i = 0; i < 5; i++) {
			newScoreTypes[i] = scoreTypes[i];
		}

		newScoreTypes[typeIndex]++;
		if (newScore == 0) {

			printResults(newScoreTypes);
		}
		else if (newScore >= 2) {
			// Any less than 2, and there is no possibility for any more valid scoring; thus terminates the recursion.
			scorePossibilitiesRecursive(newScore, newScoreTypes, &usedScores);
		}
	}
}

void printResults(int scoreTypes[]) {
	printf("%d TD + 2 pt., %d TD + FG, %d TD, %d 3 pt. FG, %d safety",
		scoreTypes[0],
		scoreTypes[1],
		scoreTypes[2],
		scoreTypes[3],
		scoreTypes[4]);
	printf("\n");
}