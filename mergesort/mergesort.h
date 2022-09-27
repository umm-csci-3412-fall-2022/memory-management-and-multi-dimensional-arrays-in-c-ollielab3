#ifndef MERGESORT_H_GUARD
#define MERGESORT_H_GUARD

#include <stdbool.h>

#define UNIT_TESTING

void mergesort(int size, int values[]);
void mergesortRange(int, int[],int, int);
void mergeRanges(int, int[], int, int, int);
#endif
