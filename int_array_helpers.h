#ifndef INT_ARRAY_HELPERS_H  // include guard
#define INT_ARRAY_HELPERS_H  1

/*
    File:       int_array_helpers.h
    Purpose:    Contain various simple utility functions for Int arrays
*/

// === Included Standard C files === //
#include <stdio.h>
#include <assert.h>

// === Included User Defined files === //
#include "int_test_arrays.h"

// === Compile Options === //
#define BUILD_MAIN_TO_TEST_INT_ARRAY_HELPERS 1

// === Function Declarations & Associated Return Status === //
// Prints the contents of an integer array
#define PRINT_INT_ARRAY_OKAY                0    
#define PRINT_INT_ARRAY_ERROR_EMPTY_ARRAY   -1
int printIntArray(const int *arrayToPrint, int size);
void runTestsOnPrintIntArray(void);



// Copies an int array to a different int array of same size
#define COPY_INT_ARRAY_OKAY                 0
#define COPY_INT_ARRAY_ERROR_EMPTY_ARRAY    -1
#define COPY_INT_ARRAY_ERROR_UNEQUAL_ARRAYS -2
int copyIntArray(const int *sourceArray, int sourceSize, int *destinationArray, int destinationSize);
//TODO void runTestsOnCopyIntArray(void);



#endif  // Include guard