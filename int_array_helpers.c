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
    if (size < 1) {
        printf("ERROR: Empty array\n");
        return PRINT_INT_ARRAY_ERROR_EMPTY_ARRAY;
    }
    
    // print each element in the array
    for (int i = 0; i < size; i++){
        printf("%d", arrayToPrint[i]);        
        // separate elements with comma and space
        if (i < (size - 1)) {
            printf(", ");
        }
        // after last element, add a new line
        else {
            printf("\n");
        }
    }
    
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
    printf("  Test PASSED: exited with empty array status\n");
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
    testSingleElementArray,
    testAscendingElementsArray,
    testDescendingElementsArray,
    testAscendingDuplicateElementsArray,
    testDescendingDuplicateElementsArray,
    testUnsortedElements,
    testSingleNegativeElementArray,
    testAscendingNegativeElementsArray,
    testDescendingNegativeElementsArray,
    testAscendingDuplicateNegativeElementsArray,
    testDescendingDuplicateNegativeElementsArray,
    testUnsortedNegativeElements
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

    // print copied array only if copied okay
    if (copyStatus == COPY_INT_ARRAY_OKAY) {
        printf("  Copy:  ");
        printIntArray(copyOfArray, arrayToTest.testArraySize);
    }
    printf("  Test PASSED: exited with okay status\n");
    printf("\n");    
}
const testIntArrayData normalTestCasesForCopyIntArray[] = {
    testSingleElementArray,
    testAscendingElementsArray,
    testDescendingElementsArray,
    testAscendingDuplicateElementsArray,
    testDescendingDuplicateElementsArray,
    testUnsortedElements,
    testSingleNegativeElementArray,
    testAscendingNegativeElementsArray,
    testDescendingNegativeElementsArray,
    testAscendingDuplicateNegativeElementsArray,
    testDescendingDuplicateNegativeElementsArray,
    testUnsortedNegativeElements
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
    //TODO testCopyUnequalArray_DestinationSmaller();
    //TODO testCopyUnequalArray_DestinationLarger();
    //TODO testCopyIntArray0_EmptyArray();
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



/*
const void testCopyUnequalArray_DestinationSmaller(void) {
    int array1Copy[array1Size - 1]; // array to have data copied to
    int copyStatus = 0;         // indicates error (negative value) or not (0 value)
    
    // print test header
    printf("TEST: %s\n", __func__);
    
    // print unmodified array
    printf("  Array 1: ");
    printIntArray(array1, array1Size);
    
    // copy array
    copyStatus = copyIntArray(array1, array1Size, array1Copy, (array1Size - 1));    
    
    // test copyStatus to see if there was other issue
    assert((copyStatus == COPY_INT_ARRAY_ERROR_UNEQUAL_ARRAYS) && "Copy array1 error with return status");
    
    // print copied array only if copied okay
    if (copyStatus == COPY_INT_ARRAY_OKAY) {
        printf("  Copy  1: ");
        printIntArray(array1Copy, array1Size);
    }
    printf("  Test PASSED: Copy array1 failed due to unequal array sizes\n");
    printf("\n");
}
const void testCopyUnequalArray_DestinationLarger(void) {
    int array1Copy[array1Size + 1]; // array to have data copied to
    int copyStatus = 0;         // indicates error (negative value) or not (0 value)
    
    // print test header
    printf("TEST: %s\n", __func__);
    
    // print unmodified array
    printf("  Array 1: ");
    printIntArray(array1, array1Size);
    
    // copy array
    copyStatus = copyIntArray(array1, array1Size, array1Copy, (array1Size + 1));    
    
    // test copyStatus to see if there was other issue
    assert((copyStatus == COPY_INT_ARRAY_ERROR_UNEQUAL_ARRAYS) && "Copy array1 error with return status");
    
    // print copied array only if copied okay
    if (copyStatus == COPY_INT_ARRAY_OKAY) {
        printf("  Copy  1: ");
        printIntArray(array1Copy, array1Size);
    }
    printf("  Test PASSED: Copy array1 failed due to unequal array sizes\n");
    printf("\n");    
}
const void testCopyIntArray0_EmptyArray(void) {
    int array0Copy[array0Size]; // array to have data copied to
    int copyStatus = 0;         // indicates error (negative value) or not (0 value)
    
    // print test header
    printf("TEST: %s\n", __func__);
    
    // print unmodified array
    printf("  Array 0: ");
    printIntArray(array0, array0Size);
    
    // copy array
    copyStatus = copyIntArray(array0, array0Size, array0Copy, array0Size);    
    
    // test copyStatus to see if there was other issue
    assert((copyStatus == COPY_INT_ARRAY_ERROR_EMPTY_ARRAY) && "Copy array0 error with return status");
    
    // print copied array only if copied okay
    if (copyStatus == COPY_INT_ARRAY_OKAY) {
        printf("  Copy  0: ");
        printIntArray(array0Copy, array0Size);
    }
    printf("  Test PASSED: Copy array0 failed due to empty array\n");
    printf("\n");
}
*/
