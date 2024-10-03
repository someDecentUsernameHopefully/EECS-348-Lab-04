#include <stdio.h>
#include "scorePossibilities.h"

void scorePossibilities(int score) {
	int startingScores[5] = {0, 0, 0, 0, 0};
	if (score >= 2) {
		printf("Possible configurations of scoring plays if a team's score is %d:\n\n", score);
		scorePossibilitiesRecursive(score, startingScores, 0);
	}
	else if (score < 0) {
		printf("It's impossible for a team's score to be negative, silly!\n");
	}
}

void scorePossibilitiesRecursive(int score, int previousScoreTypes[], int indexToUse) {
	int scoreConfig[5] = { 8, 7, 6, 3, 2 };
	int scoreSoFar = 0;
	for (int i = 0; i < indexToUse; i++) {
		scoreSoFar += scoreConfig[i] * previousScoreTypes[i];
	}
	for (int s = scoreSoFar; s <= score; s += scoreConfig[indexToUse]) {
		if (s == score) {
			printResults(previousScoreTypes);
		}
		else {
			// All cases where s < score
			// Read previousScoreType's values into temp array
			int tempScoreTypes[5];
			for (int i = 0; i < 5; i++) {
				tempScoreTypes[i] = previousScoreTypes[i];
			}
			if (indexToUse <= 3) {
				scorePossibilitiesRecursive(score, tempScoreTypes, indexToUse + 1);
			}
			previousScoreTypes[indexToUse]++;
		}
	}
}

void printResults(int scoreTypes[]) {
	printf("%d TD + 2 pt., %d TD + FG, %d TD, %d 3 pt. FG, %d safety\n",
		scoreTypes[0],
		scoreTypes[1],
		scoreTypes[2],
		scoreTypes[3],
		scoreTypes[4]);
}