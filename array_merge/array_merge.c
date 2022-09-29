#include<stdlib.h>

#include "array_merge.h"
#include "../mergesort/mergesort.h"


int* array_merge(int num_arrays, int* sizes, int** values) {
	
	// This is obviously broken. It has the right type, though, eh?
	int totalLength = 0;
	for(int i = 0; i< num_arrays; i++){
		totalLength += sizes[i];
	}
	int *bigArray = (int*) calloc(totalLength, sizeof(int));
	if (totalLength == 0){
		return bigArray;
	}
	int i = 0;
	for (int u = 0; u<num_arrays; u++){
		for(int f = 0;f<sizes[u];f++){
			bigArray[i++] = values[u][f];
		}
	}
	mergesort(i,bigArray);
	int *bigArray2 = (int*) calloc(totalLength, sizeof(int));
	int i2 = 1;
	for (int u = 0; u<i; u++){
		if (bigArray[u]!=bigArray2[i2-1]) bigArray2[i2++] = bigArray[u];
	}
	bigArray[0] = i2-1;
	free(bigArray);
	return bigArray2;
}
