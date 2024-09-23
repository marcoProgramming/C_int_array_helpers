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
// prototypes for testing printIntArray()
const void testPrintIntArray0_EmptyArray(void);
const void testPrintIntArray1(void);
const void testPrintIntArray2(void);
const void testPrintIntArray3(void);
const void testPrintIntArray4(void);

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
// prototypes for testing copyIntArray()
const void testCopyUnequalArray_DestinationSmaller(void);
const void testCopyUnequalArray_DestinationLarger(void);
const void testCopyIntArray0_EmptyArray(void);       // test empty array
const void testCopyIntArray1(void);
const void testCopyIntArray2(void);
const void testCopyIntArray3(void);
const void testCopyIntArray4(void);
const void runTestsOnCopyIntArray(void);



/*
    Purpose:    Test printing and copying arrays
    Assumes:    Arrays are not empty
*/
#if (BUILD_TESTS_FOR_INT_ARRAY_HELPERS == 1)
#warning Building tests and main for int_array_helpers
void main(void) {
    runTestsOnPrintIntArray();
    printf("\n\n\n");
    runTestsOnCopyIntArray();
}
#endif


/*
    Purpose:    Test printIntArray() with various size arrays to catch error conditions and confirm pass conditions
    Errors:     testPrintIntArray0_EmptyArray() the array is empty
    
*/
void runTestsOnPrintIntArray(void) {
    printf("===================================\n");
    printf("=== START Testing printIntArray ===\n");
    printf("===================================\n");
    testPrintIntArray0_EmptyArray();
    testPrintIntArray1();
    testPrintIntArray2();
    testPrintIntArray3();
    testPrintIntArray4();
    printf("=================================\n");
    printf("=== END Testing printIntArray ===\n");
    printf("=================================\n");
}
const void testPrintIntArray0_EmptyArray(void) {
    int printStatus = 0;
    
    // print test header
    printf("TEST: %s\n", __func__);
    
    // print array
    printf("  Array 0: ");
    printStatus = printIntArray(array0, array0Size);
    
    // test copyStatus that array was empty
    assert((printStatus == PRINT_INT_ARRAY_ERROR_EMPTY_ARRAY) && "Print array0 error with return status");
    
    // print if test was passed
    printf("  Test PASSED: Print array0 failed due to empty array\n");
    printf("\n");
}
const void testPrintIntArray1(void) {
    int printStatus = 0;
    
    // print test header
    printf("TEST: %s\n", __func__);
    
    // print array
    printf("  Array 1: ");
    printStatus = printIntArray(array1, array1Size);
    
    // test copyStatus that array was empty
    assert((printStatus == PRINT_INT_ARRAY_OKAY) && "Print array1 error with return status");
    
    // print if test was passed
    printf("  Test PASSED: Print array1 exited with okay status\n");
    printf("\n");
}
const void testPrintIntArray2(void) {
    int printStatus = 0;
    
    // print test header
    printf("TEST: %s\n", __func__);
    
    // print array
    printf("  Array 2: ");
    printStatus = printIntArray(array2, array2Size);
    
    // test copyStatus that array was empty
    assert((printStatus == PRINT_INT_ARRAY_OKAY) && "Print array2 error with return status");
    
    // print if test was passed
    printf("  Test PASSED: Print array2 exited with okay status\n");
    printf("\n");
}
const void testPrintIntArray3(void) {
    int printStatus = 0;
    
    // print test header
    printf("TEST: %s\n", __func__);
    
    // print array
    printf("  Array 3: ");
    printStatus = printIntArray(array3, array3Size);
    
    // test copyStatus that array was empty
    assert((printStatus == PRINT_INT_ARRAY_OKAY) && "Print array3 error with return status");
    
    // print if test was passed
    printf("  Test PASSED: Print array3 exited with okay status\n");
    printf("\n");
}
const void testPrintIntArray4(void) {
    int printStatus = 0;
    
    // print test header
    printf("TEST: %s\n", __func__);
    
    // print array
    printf("  Array 4: ");
    printStatus = printIntArray(array4, array4Size);
    
    // test copyStatus that array was empty
    assert((printStatus == PRINT_INT_ARRAY_OKAY) && "Print array4 error with return status");
    
    // print if test was passed
    printf("  Test PASSED: Print array4 exited with okay status\n");
    printf("\n");
}


/*
    Purpose:    Test copyIntArray() with various size arrays to catch error conditions and confirm pass conditions
    Errors:     testCopyUnequalArray_DestinationSmaller() the destination array is smaller than the source array
                testCopyUnequalArray_DestinationLarger() the destination array is larger than the source array
                testCopyIntArray0_EmptyArray() the source and/or desintation array is empty
*/
void runTestsOnCopyIntArray(void) {
    printf("==================================\n");
    printf("=== START Testing copyIntArray ===\n");
    printf("==================================\n");
    testCopyUnequalArray_DestinationSmaller();
    testCopyUnequalArray_DestinationLarger();
    testCopyIntArray0_EmptyArray();
    testCopyIntArray1();
    testCopyIntArray2();
    testCopyIntArray3();
    testCopyIntArray4();    
    printf("================================\n");
    printf("=== END Testing copyIntArray ===\n");
    printf("================================\n");
}
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
const void testCopyIntArray1(void) {
    int array1Copy[array1Size]; // array to have data copied to
    int copyStatus = 0;         // indicates error (negative value) or not (0 value)
    
    // print test header
    printf("TEST: %s\n", __func__);
    
    // print unmodified array
    printf("  Array 1: ");
    printIntArray(array1, array1Size);
    
    // copy array
    copyStatus = copyIntArray(array1, array1Size, array1Copy, array1Size);    
    
    // test each element to see if copied correctly
    for (int i = 0; i < array1Size; i++) {
        assert((array1[i] == array1Copy[i]) && "Copy array1 error mismatched element\n");
    }
    // test copyStatus to see if there was other issue
    assert((copyStatus == COPY_INT_ARRAY_OKAY) && "Copy array1 error with return status");
    
    // print copied array only if copied okay
    if (copyStatus == COPY_INT_ARRAY_OKAY) {
        printf("  Copy  1: ");
        printIntArray(array1Copy, array1Size);
    }
    printf("  Test PASSED: Copy array1\n");
    printf("\n");
}
const void testCopyIntArray2(void) {
    int array2Copy[array2Size]; // array to have data copied to
    int copyStatus = 0;         // indicates error (negative value) or not (0 value)
    
    // print test header
    printf("TEST: %s\n", __func__);
    
    // print unmodified array
    printf("  Array 2: ");
    printIntArray(array2, array2Size);
    
    // copy array
    copyStatus = copyIntArray(array2, array2Size, array2Copy, array2Size);    
    
    // test each element to see if copied correctly
    for (int i = 0; i < array2Size; i++) {
        assert((array2[i] == array2Copy[i]) && "Copy array2 error mismatched element\n");
    }
    // test copyStatus to see if there was other issue
    assert((copyStatus == COPY_INT_ARRAY_OKAY) && "Copy array2 error with return status");
    
    // print copied array only if copied okay
    if (copyStatus == COPY_INT_ARRAY_OKAY) {
        printf("  Copy  2: ");
        printIntArray(array2Copy, array2Size);
    }
    printf("  Test PASSED: Copy array2\n");
    printf("\n");
}
const void testCopyIntArray3(void) {
    int array3Copy[array3Size]; // array to have data copied to
    int copyStatus = 0;         // indicates error (negative value) or not (0 value)
    
    // print test header
    printf("TEST: %s\n", __func__);
    
    // print unmodified array
    printf("  Array 3: ");
    printIntArray(array3, array3Size);
    
    // copy array
    copyStatus = copyIntArray(array3, array3Size, array3Copy, array3Size);
    
    // test each element to see if copied correctly
    for (int i = 0; i < array3Size; i++) {
        assert((array3[i] == array3Copy[i]) && "Copy array3 error mismatched element\n");
    }
    // test copyStatus to see if there was other issue
    assert((copyStatus == COPY_INT_ARRAY_OKAY) && "Copy array3 error with return status");
    
    // print copied array only if copied okay
    if (copyStatus == COPY_INT_ARRAY_OKAY) {
        printf("  Copy  3: ");
        printIntArray(array3Copy, array3Size);
    }
    printf("  Test PASSED: Copy array3\n");
    printf("\n");
}
const void testCopyIntArray4(void) {
    int array4Copy[array4Size]; // array to have data copied to
    int copyStatus = 0;         // indicates error (negative value) or not (0 value)
    
    // print test header
    printf("TEST: %s\n", __func__);
    
    // print unmodified array
    printf("  Array 4: ");
    printIntArray(array4, array4Size);
    
    // copy array
    copyStatus = copyIntArray(array4, array4Size, array4Copy, array4Size);
    
    // test each element to see if copied correctly
    for (int i = 0; i < array4Size; i++) {
        assert((array4[i] == array4Copy[i]) && "Copy array4 error mismatched element\n");
    }
    // test copyStatus to see if there was other issue
    assert((copyStatus == COPY_INT_ARRAY_OKAY) && "Copy array4 error with return status");
    
    // print copied array only if copied okay
    if (copyStatus == COPY_INT_ARRAY_OKAY) {
        printf("  Copy  4: ");
        printIntArray(array4Copy, array4Size);
    }
    printf("  Test PASSED: Copy array4\n");
    printf("\n");
}
