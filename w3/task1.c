#include <stdio.h>
#include <time.h> // measuring run time
#include <assert.h>

int A[100000000];

int linear_search(int A[], int n, int t) {
    // write you code

    for (int k = 0; k < n; k++){
        if ( A[k] == t){
            return 1;
        }
    }

    return 0; // not found
}

int binary_search(int A[], int n, int t) {
    // write your code

    // left , right and middle
    int r = n-1;
    int l = 0;
    int m = 0;



    while(l <= r){

        m = l + (r-l)/2;

        if ( A[m]== t){
            return 1;
        }
        else if (A[m]<t){
            l = m+1;
        }
        else{
            r = m-1;
        }

        
    }
    
    return 0; // not found
}

int main() {
    int A[] = {};
    int n = 0;
    int t = 5;
    printf("%s\n", binary_search(A, n, t) ? "true" : "false");

    // Test case 2: Array with a single element
    int B[] = {5};
    int m = 1;
    int s = 5;
    printf("%s\n", binary_search(B, m, s) ? "true" : "false");

    // Test case 3: Array with even number of elements
    int C[] = {1, 3, 5, 7};
    int o = 4;
    int q = 5;
    printf("%s\n", binary_search(C, o, q) ? "true" : "false");

    // Test case 4: Array with odd number of elements
    int D[] = {2, 4, 6, 8, 10};
    int p = 5;
    int u = 9;
    printf("%s\n", binary_search(D, p, u) ? "true" : "false");

    // Test case 5: Target integer not in array
    int E[] = {1, 3, 5, 7, 9};
    int v = 5;
    int w = 2;
    printf("%s\n", binary_search(E, v, w) ? "true" : "false");


    clock_t start, end;
    printf("Enter an integer for n: ");
    scanf("%d", &n); 
    printf("Generate an array with %d distinct integers from 1 to %d.\n", n, n);
    for(int i = 0; i < n; i++) A[i] = i + 1;
    printf("Enter an integer for t: \n");
    scanf("%d", &t); 
    start = clock();
    linear_search(A, n, t); // your implementation
    end = clock();
    double run_time = ((double)(end - start))/(CLOCKS_PER_SEC/1000);
    printf("Linear search takes : %f millseconds\n", run_time); 

    start = clock();
    binary_search(A, n, t); // your implementation
    end = clock();
    run_time = ((double)(end - start))/(CLOCKS_PER_SEC/1000);
    printf("Binary search takes : %f millseconds\n", run_time); 
}