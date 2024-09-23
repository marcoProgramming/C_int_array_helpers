# C Library int_array_helpers
This library provides simple tools for manipulating int arrays in C

## Public Functions

### Printing Int Arrays
int printIntArray(const int *arrayToPrint, int size) is used to print all elements of the array of the specified size
void runTestsOnPrintIntArray(void) runs tests on printIntArray

### Copy Int Arrays
int copyIntArray(const int *sourceArray, int sourceSize, int *destinationArray, int destinationSize) is used to copy all elements from source array to destination array
void runTestsOnCopyIntArray(void) runs tests on copyIntArray