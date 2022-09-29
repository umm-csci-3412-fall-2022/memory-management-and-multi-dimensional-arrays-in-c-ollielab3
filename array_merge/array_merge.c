#include<stdlib.h>

#include "array_merge.h"

void mergesort(int size, int values[]);
void mergesortRange(int size, int values[], int low, int high);
void mergeRanges(int size, int values[], int low, int midpoint, int high);
int* array_merge(int num_arrays, int* sizes, int** values) {
	
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
	bigArray2[i2++] = bigArray[0];
	for (int u = 1; u<i; u++){
		if (bigArray[u]!=bigArray2[i2-1]) bigArray2[i2++] = bigArray[u];
	}
	bigArray2[0] = i2-1;
	free(bigArray);
	return bigArray2;
}

void mergesort(int size, int values[]) {
  mergesortRange(size, values, 0, size);
  return;
}

void mergesortRange(int size, int values[], int low, int high){
        int range = high-low;
        if (range > 1){
                int midpoint = (low + (high-low)/2);
                mergesortRange(size,values,low,midpoint);
                mergesortRange(size,values,midpoint,high);
                mergeRanges(size,values,low,midpoint,high);
        }
}

void mergeRanges(int size, int values[], int low, int midpoint, int high){
        const int range = high-low;
        int *destination;
        destination = (int*) calloc(range,sizeof(int));
        int copyIndex = 0;
        int firstIndex = low;
        int secondIndex = midpoint;
        while(firstIndex<midpoint && secondIndex<high){
                if(values[firstIndex]<values[secondIndex]){
                        destination[copyIndex] = values[firstIndex++];
                }else{
                        destination[copyIndex] = values[secondIndex++];
                }
                copyIndex++;
        }
        while (firstIndex<midpoint){
                destination[copyIndex++] = values[firstIndex++];
        }
        while (secondIndex<high){
                destination[copyIndex++] = values[secondIndex++];
        }
        int i;
        for(i = 0;i<range;i++){
                values[i+low] = destination[i];
        }
        free(destination);
}
