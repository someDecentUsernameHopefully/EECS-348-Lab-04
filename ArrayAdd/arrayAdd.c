#include "arrayAdd.h"

int* ArrayAdd(int array1[], int array2[]) {
	int arrayLength = sizeof(array1) / sizeof(array1[0]);
	int toReturn[arrayLength];
	for (int i = 0; i < arrayLength; i++) {
		toReturn[i] = array1[i] + array2[i];
	}
	return toReturn;
}