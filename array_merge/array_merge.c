#include "array_merge.h"

int* array_merge(int num_arrays, int* sizes, int** values) {
	
	// This is obviously broken. It has the right type, though, eh?
	int totalLength = 0;
	for(int i = 0; i< num_arrays; i++){
		totalLength += sizes[i];
	}
	if (totalLength == 0){

	}else if (totalLength == 1){
		
	}else{
		
	}
	return sizes;
}
