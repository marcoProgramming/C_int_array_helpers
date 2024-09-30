/*
    File:       int_array_helpers.c
    Purpose:    Contain various simple utility functions for Int arrays
*/

// === Included User Defined files === //
#include "int_array_helpers.h"

// === Function Definitions === //
/*
    Purpose:    Prints an int array
    Assumes:    Array is not empty
    Inputs:     int* arrayToPrint:  the array that will be printed
                int size:           number of elements in the array to print
    Returns:    int value indicating if the print succeeded or not
                0:  indicates the print completed
                -1: indicates the array is empty
*/
int printIntArray(const int *arrayToPrint, int size)
{
    // Check for empty array and return error condition if found
    if (size < 1) return PRINT_INT_ARRAY_ERROR_EMPTY_ARRAY;
    
    // print each element in the array
    for (int i = 0; i < size; i++){
        printf("%d", arrayToPrint[i]);        
        // separate elements with comma and space
        if (i < (size - 1)) {
            printf(", ");
            // move to new line every 20 elements
            if (((i + 1) % 20) == 0) {
                printf("\n         ");                
            }
        }
    }
    // after last element, add a new line
    printf("\n");
    
    return PRINT_INT_ARRAY_OKAY;
}
/*
    Purpose:    Test printIntArray() with various size arrays to catch error conditions and confirm pass conditions
    Errors:     testPrintEmptyArray() the array is empty  
*/
const void testPrintEmptyIntArray(void) {
    int printStatus = 0;
    
    // print test header
    printf("TEST: %s:\n", testEmptyArray.testName);
    
    // print array
    printf("  Array: ");
    printStatus = printIntArray(testEmptyArray.testArray, testEmptyArray.testArraySize);
    
    // test copyStatus that array was empty
    assert((printStatus == PRINT_INT_ARRAY_ERROR_EMPTY_ARRAY) && " ERROR with return status");
    
    // print if test was passed
    printf("\n  Test PASSED: exited with empty array status\n");
    printf("\n");
}
const void testPrintIntArray(const testIntArrayData arrayToTest) {    
    int printStatus = 0;
    
    // print test header
    printf("TEST: %s:\n", arrayToTest.testName);
    
    // print array
    printf("  Array: ");
    printStatus = printIntArray(arrayToTest.testArray, arrayToTest.testArraySize);
    
    // test copyStatus that array was empty
    assert((printStatus == PRINT_INT_ARRAY_OKAY) && "ERROR with return status");
    
    // print if test was passed
    printf("  Test PASSED: exited with okay status\n");
    printf("\n");
    
}
const testIntArrayData normalTestCasesForPrintIntArray[] = {
    testSinglePositiveElementArray,
    testAscendingPositiveElementsArray,
    testDescendingPositiveElementsArray,
    testAscendingDuplicatePositiveElementsArray,
    testDescendingDuplicatePositiveElementsArray,
    testUnsortedPositiveElements,
    testSingleNegativeElementArray,
    testAscendingNegativeElementsArray,
    testDescendingNegativeElementsArray,
    testAscendingDuplicateNegativeElementsArray,
    testDescendingDuplicateNegativeElementsArray,
    testUnsortedNegativeElements,
    testSingleElementArray,
    testAscendingElementsArray,
    testDescendingElementsArray,
    testAscendingDuplicateElementsArray,
    testDescendingDuplicateElementsArray,
    testUnsortedElements
};
const void testPassingConditionsForPrintIntArray(void) {
    int numberOfNormalTestCases = sizeof(normalTestCasesForPrintIntArray) / sizeof(normalTestCasesForPrintIntArray[0]);
    for (int i = 0; i < numberOfNormalTestCases; i++) {
        testPrintIntArray(normalTestCasesForPrintIntArray[i]);
    }
}
/*
    Purpose:    Test printIntArray() with various size arrays to catch error conditions and confirm pass conditions    
*/
void runTestsOnPrintIntArray(void) {
    printf("===================================\n");
    printf("=== START Testing printIntArray ===\n");
    printf("===================================\n");
    testPrintEmptyIntArray();
    testPassingConditionsForPrintIntArray();
    printf("=================================\n");
    printf("=== END Testing printIntArray ===\n");
    printf("=================================\n");
}



/*
    Purpose:    Copies an int array to a different int array of same size
    Assumes:    Source array and destination array are of the same size
                Array is not empty
    Inputs:     int* sourceArray:       the array that will be copied
                int sourceSize:         number of elements in the source array
                int* destinationArray:  the array that will receive the copied data
                int destinationSize:    number of elements in the destination array
    Returns:    int value indicating if the copy succeeded or not
                0:  indicates the copy completed
                -1: indicates the arrays are not of the same size
                -2: indicates the arrays are empty
*/
int copyIntArray(const int *sourceArray, int sourceSize, int *destinationArray, int destinationSize) {
    // Check for arrays of unequal size and return error condition if found
    if (sourceSize != destinationSize) return COPY_INT_ARRAY_ERROR_UNEQUAL_ARRAYS;
    // Check for empty array and return error condition if found
    if (sourceSize < 1) return COPY_INT_ARRAY_ERROR_EMPTY_ARRAY;
    
    // Copy each element from source to destinaton
    for (int i = 0; i < sourceSize; i++) {
        destinationArray[i] = sourceArray[i];
    }
    
    return COPY_INT_ARRAY_OKAY;
}
/*
    Purpose:    Test copyIntArray() with various size arrays to catch error conditions and confirm pass conditions
    Errors:     testCopyUnequalArray_DestinationSmaller() the destination array is smaller than the source array
                testCopyUnequalArray_DestinationLarger() the destination array is larger than the source array
                testCopyIntArray0_EmptyArray() the source and/or desintation array is empty
*/
const void testCopyEmptyIntArray(void) {
    int copyOfArray[testEmptyArray.testArraySize]; // array to have data copied to
    int copyStatus = 0;
    
    // print test header
    printf("TEST: %s:\n", testEmptyArray.testName);
    
    // print unmodified array
    printf("  Array: ");
    (void)printIntArray(testEmptyArray.testArray, testEmptyArray.testArraySize);
    
    // copy array
    copyStatus = copyIntArray(testEmptyArray.testArray, testEmptyArray.testArraySize, copyOfArray, testEmptyArray.testArraySize);
    
    // test copyStatus that array was empty
    assert((copyStatus == COPY_INT_ARRAY_ERROR_EMPTY_ARRAY) && " ERROR with return status");
    
    // print if test was passed
    printf("\n  Copy : ");
    printf("\n  Test PASSED: exited with empty array status\n");
    printf("\n");
}
const void testCopyUnequalIntArray_DestinationSmaller(void) {
    int smallerCopyOfArray[testUnsortedElements.testArraySize - 1]; // array to have data copied to
    int copyStatus = 0;                                             // indicates error (negative value) or not (0 value)
    
    // print test header
    printf("TEST: %s\n", __func__);
    
    // print unmodified array
    printf("  Array: ");
    printIntArray(testUnsortedElements.testArray, testUnsortedElements.testArraySize);
    
    // copy array
    copyStatus = copyIntArray(testUnsortedElements.testArray, testUnsortedElements.testArraySize, smallerCopyOfArray, (testUnsortedElements.testArraySize - 1));    
    
    // test copyStatus to see if there was other issue
    assert((copyStatus == COPY_INT_ARRAY_ERROR_UNEQUAL_ARRAYS) && "ERROR with return status");
    
    // print test passed info
    printf("  Copy : ");
    printf("\n  Test PASSED: exited with unequal array status\n");
    printf("\n");
}
const void testCopyUnequalIntArray_DestinationLarger(void) {
    int largerCopyOfArray[testUnsortedElements.testArraySize + 1]; // array to have data copied to
    int copyStatus = 0;                                             // indicates error (negative value) or not (0 value)
    
    // print test header
    printf("TEST: %s\n", __func__);
    
    // print unmodified array
    printf("  Array: ");
    printIntArray(testUnsortedElements.testArray, testUnsortedElements.testArraySize);
    
    // copy array
    copyStatus = copyIntArray(testUnsortedElements.testArray, testUnsortedElements.testArraySize, largerCopyOfArray, (testUnsortedElements.testArraySize + 1));    
    
    // test copyStatus to see if there was other issue
    assert((copyStatus == COPY_INT_ARRAY_ERROR_UNEQUAL_ARRAYS) && "ERROR with return status");
    
    // print test passed info
    printf("  Copy : ");
    printf("\n  Test PASSED: exited with unequal array status\n");
    printf("\n");
}
const void testCopyIntArray(const testIntArrayData arrayToTest) {    
    int copyOfArray[arrayToTest.testArraySize]; // array to have data copied to
    int copyStatus = 0;         // indicates error (negative value) or not (0 value)
    
    // print test header
    printf("TEST: %s:\n", arrayToTest.testName);
    
    // print unmodified array
    printf("  Array: ");
    (void)printIntArray(arrayToTest.testArray, arrayToTest.testArraySize);
    
    // copy array
    copyStatus = copyIntArray(arrayToTest.testArray, arrayToTest.testArraySize, copyOfArray, arrayToTest.testArraySize);
    
    // test each element to see if copied correctly
    for (int i = 0; i < arrayToTest.testArraySize; i++) {
        assert((arrayToTest.testArray[i] == copyOfArray[i]) && "Copy array1 error mismatched element\n");
    }
    // test copyStatus to see if there was other issue
    assert((copyStatus == COPY_INT_ARRAY_OKAY) && "Copy array1 error with return status");

    // print test passed info
    printf("  Copy:  ");
    printIntArray(copyOfArray, arrayToTest.testArraySize);
    printf("  Test PASSED: exited with okay status\n");
    printf("\n");    
}
const testIntArrayData normalTestCasesForCopyIntArray[] = {
    testSinglePositiveElementArray,
    testAscendingPositiveElementsArray,
    testDescendingPositiveElementsArray,
    testAscendingDuplicatePositiveElementsArray,
    testDescendingDuplicatePositiveElementsArray,
    testUnsortedPositiveElements,
    testSingleNegativeElementArray,
    testAscendingNegativeElementsArray,
    testDescendingNegativeElementsArray,
    testAscendingDuplicateNegativeElementsArray,
    testDescendingDuplicateNegativeElementsArray,
    testUnsortedNegativeElements,
    testSingleElementArray,
    testAscendingElementsArray,
    testDescendingElementsArray,
    testAscendingDuplicateElementsArray,
    testDescendingDuplicateElementsArray,
    testUnsortedElements
};
const void testPassingConditionsForCopyIntArray(void) {
    int numberOfNormalTestCases = sizeof(normalTestCasesForCopyIntArray) / sizeof(normalTestCasesForCopyIntArray[0]);
    for (int i = 0; i < numberOfNormalTestCases; i++) {
        testCopyIntArray(normalTestCasesForCopyIntArray[i]);
    }
}
void runTestsOnCopyIntArray(void) {
    printf("==================================\n");
    printf("=== START Testing copyIntArray ===\n");
    printf("==================================\n");
    testCopyEmptyIntArray();
    testCopyUnequalIntArray_DestinationSmaller();
    testCopyUnequalIntArray_DestinationLarger();
    testPassingConditionsForCopyIntArray();  
    printf("================================\n");
    printf("=== END Testing copyIntArray ===\n");
    printf("================================\n");
}

/*
    Purpose:    Test printing and copying arrays
    Assumes:    Arrays are not empty
*/
#if (BUILD_MAIN_TO_TEST_INT_ARRAY_HELPERS == 1)
#warning Building tests and main for int_array_helpers
void main(void) {
    runTestsOnPrintIntArray();
    printf("\n\n\n");
    runTestsOnCopyIntArray();
}
#endif
