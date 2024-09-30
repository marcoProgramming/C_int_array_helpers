#ifndef INT_TEST_ARRAYS_H  // include guard
#define INT_TEST_ARRAYS_H  1

/*
    File:       int_test_arrays.h
    Purpose:    Contain various int arrays for use in testing
*/

#define MAX_NUMBER_OF_ELEMENTS  10000
typedef struct {
    const char* testName;
    const int testArraySize;  
    const int testArray[MAX_NUMBER_OF_ELEMENTS];  
} testIntArrayData;

// arrays with positive and negative elements
//TODO
const testIntArrayData testEmptyArray = {
    "Empty Array",
    0,
    {}
};

// arrays with only positive elements
const testIntArrayData testSingleElementArray = {
    "Single Element Array",
    1,
    {1}
};
const testIntArrayData testAscendingElementsArray = {
    "Ascending Elements Array",
    10,
    {0, 1, 2, 3, 4, 5, 6, 7, 8, 9}
};
const testIntArrayData testDescendingElementsArray = {
    "Descending Elements Array",
    10,
    {9, 8, 7, 6, 5, 4, 3, 2, 1, 0}
};
const testIntArrayData testAscendingDuplicateElementsArray = {
    "Ascending Duplicate Elements Array",
    15,
    {1, 2, 2, 3, 3, 3, 4, 4, 4, 4, 5, 5, 5, 5, 5}
};
const testIntArrayData testDescendingDuplicateElementsArray = {
    "Descending Duplicate Elements Array",
    15,
    {5, 5, 5, 5, 5, 4, 4, 4, 4, 3, 3, 3, 2, 2, 1}
};
const testIntArrayData testUnsortedElements = {
    "Unsorted Elements Array",
    20,
    {1, 4, 5, 2, 7, 8, 2, 5, 1, 0, 9, 6, 1, 2, 7, 3, 3, 6, 2, 0}
};


// arrays with only negative elements
const testIntArrayData testSingleNegativeElementArray = {
    "Single Negative Element Array",
    1,
    {-1}
};
const testIntArrayData testAscendingNegativeElementsArray = {
    "Ascending Negative Elements Array",
    10,
    {-9, -8, -7, -6, -5, -4, -3, -2, -1, 0}
};
const testIntArrayData testDescendingNegativeElementsArray = {
    "Descending Negative Elements Array",
    10,
    {0, -1, -2, -3, -4, -5, -6, -7, -8, -9}
};
const testIntArrayData testAscendingDuplicateNegativeElementsArray = {
    "Ascending Duplicate Negative Elements Array",
    15,
    {-1, -2, -2, -3, -3, -3, -4, -4, -4, -4, -5, -5, -5, -5, -5}
};
const testIntArrayData testDescendingDuplicateNegativeElementsArray = {
    "Descending Duplicate Negative Elements Array",
    15,
    {-5, -5, -5, -5, -5, -4, -4, -4, -4, -3, -3, -3, -2, -2, -1}
};
const testIntArrayData testUnsortedNegativeElements = {
    "Unsorted Negative Elements Array",
    20,
    {-1, -4, -5, -2, -7, -8, -2, -5, -1, 0, -9, -6, -1, -2, -7, -3, -3, -6, -2, 0}
};
// arrays with positive and negative elements
//TODO

#endif  // include guard