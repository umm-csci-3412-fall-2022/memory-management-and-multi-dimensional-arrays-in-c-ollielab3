#include "mergesort.h"
#include <stdlib.h>

void mergesort(int size, int values[]) {
  // This obviously doesn't actually do any *sorting*, so there's
  // certainly work still to be done.
  //
  // Remember that a key goal here is to learn to use
  // `malloc/calloc` and `free`, so make sure you explicitly
  // allocate any new arrays that you need, even if you
  // might not strictly need to.
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
