#include <stdio.h>
#include <stdlib.h>

// maxsub function declaration

// maxsub function declaration
int* maxsub(int* arr, int start, int end) {
    // index 0: sum, index 1: left index, index 2: right index
    int* tuple = malloc(sizeof(int) * 3);

    int mid = (end -start) / 2;

    for (int k = 0; k < 3; k++) {
        tuple[k] = 0;
    }

    if ((end - start) == 0) {
        int ele = arr[start];

        if( ele > 0){
            tuple[0] = ele;
            tuple[1] = start;
            tuple[2] = end;

        } else{
            tuple[0] = 0;
            tuple[1] = -1;
            tuple[2] = -1;
        }
                

        return tuple;
    } else {
        int* ltuple = maxsub(arr, start, start + mid);
        int* rtuple = maxsub(arr, start + mid + 1, end);

        // Compare and merge results
        int overlap_sum = ltuple[0];

        for (int k = ltuple[2] + 1; k < rtuple[1]; k++) {
            overlap_sum += arr[k];
        }

        overlap_sum += rtuple[0];

        if (overlap_sum > ltuple[0] && overlap_sum > rtuple[0]) {
            tuple[0] = overlap_sum;
            tuple[1] = ltuple[1];
            tuple[2] = rtuple[2];
        } else if (ltuple[0] > rtuple[0]) {
            free(tuple);
            tuple = ltuple; 
        } else if (ltuple[0] < rtuple[0]){
            free(tuple);
            tuple = rtuple;


        } else {
            tuple[0] = 0;
            tuple[1] = -1;
            tuple[2] = -1;
        }


        return tuple;
    }
}


// Test function for maxsub
void test_maxsub(int arr[], int size, int expected_start, int expected_end) {

    int* res = malloc(sizeof(int)*3);

    for ( int k = 0; k < 3 ; k++){
        res[k] = 0;
    }

    res = maxsub(arr, 0, size-1);

    int start = res[1];
    int end = res[2];


    if (start == expected_start && end == expected_end) {
        printf("PASSED: maxsub of the given array starts at %d and ends at %d\n", start, end);
    } else {
        printf("FAILED: Expected start %d and end %d, but got start %d and end %d\n", expected_start, expected_end, start, end);
    }
}

int main() {
    // Test cases for maxsub function
    int arr1[] = {-2, -3, 4, -1, -2, 1, 5, -3};
    int arr2[] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    int arr3[] = {-1, -2, -3, -4, -5};
    int arr4[] = {1, 2, 3, 4, 5};
    int arr5[] = {1, -1, 2, -2, 3, -3, 4, -4, 5, -5};
    int arr6[] = {0, 0, 0, 0, 0, 0};
    int arr7[] = {-1, 2, 3, -4, 5, 6, -7, 8};
    int arr8[] = {-2, 1, -3, 4, -1, 2, 1, -8, 4};
    int arr9[] = {2,5,-0,30,-40,3,6};
    

    printf("Test nr. 1: ");
    test_maxsub(arr1, sizeof(arr1) / sizeof(arr1[0]), 2, 6);
    printf("\n");

    printf("Test nr. 2: ");
    test_maxsub(arr2, sizeof(arr2) / sizeof(arr2[0]), 3, 6);
    printf("\n");

    printf("Test nr. 3: ");
    test_maxsub(arr3, sizeof(arr3) / sizeof(arr3[0]), -1, -1);
    printf("\n");

    printf("Test nr. 4: ");
    test_maxsub(arr4, sizeof(arr4) / sizeof(arr4[0]), 0, 4);
    printf("\n");

    printf("Test nr. 5: ");
    test_maxsub(arr5, sizeof(arr5) / sizeof(arr5[0]), 8, 8);
    printf("\n");

    printf("Test nr. 6: ");
    test_maxsub(arr6, sizeof(arr6) / sizeof(arr6[0]), -1, -1);
    printf("\n");

    printf("Test nr. 7: ");
    test_maxsub(arr7, sizeof(arr7) / sizeof(arr7[0]), 1, 7);
    printf("\n");

    printf("Test nr. 8: ");
    test_maxsub(arr8, sizeof(arr8) / sizeof(arr8[0]), 3, 6);
    printf("\n");

    printf("Test nr. 9: ");
    test_maxsub(arr9, sizeof(arr9) / sizeof(arr9[0]), 3, 3);
    printf("\n");


    return 0;
}
