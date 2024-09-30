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

// vareity of arrays for testing
const testIntArrayData testEmptyArray = {
    "Empty Array",
    0,
    {}
};

// arrays with only positive elements
const testIntArrayData testSinglePositiveElementArray = {
    "Single Positive Element Array",
    1,
    {1}
};
const testIntArrayData testAscendingPositiveElementsArray = {
    "Ascending Positive Elements Array",
    10,
    {0, 1, 2, 3, 4, 5, 6, 7, 8, 9}
};
const testIntArrayData testDescendingPositiveElementsArray = {
    "Descending Positive Elements Array",
    10,
    {9, 8, 7, 6, 5, 4, 3, 2, 1, 0}
};
const testIntArrayData testAscendingDuplicatePositiveElementsArray = {
    "Ascending Duplicate Positive Elements Array",
    15,
    {1, 2, 2, 3, 3, 3, 4, 4, 4, 4, 5, 5, 5, 5, 5}
};
const testIntArrayData testDescendingDuplicatePositiveElementsArray = {
    "Descending Duplicate Positive Elements Array",
    15,
    {5, 5, 5, 5, 5, 4, 4, 4, 4, 3, 3, 3, 2, 2, 1}
};
const testIntArrayData testUnsortedPositiveElements = {
    "Unsorted Positive Elements Array",
    20,
    {1, 4, 5, 2, 7, 8, 2, 5, 1, 10, 9, 6, 1, 2, 7, 3, 3, 6, 2, 10}
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
    {-5, -5, -5, -5, -5, -4, -4, -4, -4, -3, -3, -3, -2, -2, -1}
};
const testIntArrayData testDescendingDuplicateNegativeElementsArray = {
    "Descending Duplicate Negative Elements Array",
    15,
    {-1, -2, -2, -3, -3, -3, -4, -4, -4, -4, -5, -5, -5, -5, -5}
};
const testIntArrayData testUnsortedNegativeElements = {
    "Unsorted Negative Elements Array",
    20,
    {-1, -4, -5, -2, -7, -8, -2, -5, -1, -10, -9, -6, -1, -2, -7, -3, -3, -6, -2, -10}
};

// arrays with positive and negative elements
const testIntArrayData testSingleElementArray = {
    "Single Element Array",
    1,
    {0}
};
const testIntArrayData testAscendingElementsArray = {
    "Ascending Elements Array",
    19,
    {-9, -8, -7, -6, -5, -4, -3, -2, -1, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9}
};
const testIntArrayData testDescendingElementsArray = {
    "Descending Elements Array",
    19,
    {9, 8, 7, 6, 5, 4, 3, 2, 1, 0, -1, -2, -3, -4, -5, -6, -7, -8, -9}
};
const testIntArrayData testAscendingDuplicateElementsArray = {
    "Ascending Duplicate Elements Array",
    31,
    {-5, -5, -5, -5, -5, -4, -4, -4, -4, -3, -3, -3, -2, -2, -1, 0, 1, 2, 2, 3, 3, 3, 4, 4, 4, 4, 5, 5, 5, 5, 5}
};
const testIntArrayData testDescendingDuplicateElementsArray = {
    "Descending Duplicate Elements Array",
    31,
    {5, 5, 5, 5, 5, 4, 4, 4, 4, 3, 3, 3, 2, 2, 1, 0, -1, -2, -2, -3, -3, -3, -4, -4, -4, -4, -5, -5, -5, -5, -5}
};
const testIntArrayData testUnsortedElements = {
    "Unsorted Elements Array",
    42,
    {0, -4, 3, -2, -8, 5, 9, -7, -1, -10, 4, -5, 10, 1, 2, 7, 8, -3, -9, 6, -6, -3, 9, -4, -7, -8, -10, 6, 10, -1, -9, -2, 7, 4, 3, 2, 0, 5, 1, 8, -5, -6}
};

#endif  // include guard