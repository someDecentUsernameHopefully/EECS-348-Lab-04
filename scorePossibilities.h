#ifndef ScorePossibilities_H
#define ScorePossibilities_H
void scorePossibilities(int score);
void scorePossibilitiesRecursive(int score, int previousScoreTypes[], int usedScores[][5]);
void recursiveHelperFunction(int score, int scoreTypes[], int scoreCost, int typeIndex, int usedScores[][5]);
void printResults(int scoreTypes[]);

#endif