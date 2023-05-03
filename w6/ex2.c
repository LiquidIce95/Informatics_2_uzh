#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#define N 5

void print(int *arr, int n){
    for ( int k = 0; k < n ; ++k){
        printf("%d",arr[k]);
    }

    printf("%s","\n");
};

int *reverse(int *arr, int n){
    // pre condition , arr has more than one element
    int l = 0;
    int r = n-1;

    while(l<r){
        int temp = arr[l];
        arr[l] = arr[r];
        arr[r] = temp;
        r--;
        l++;
    }

    int* p = arr;
    return p;
}


int *prepend(int *arr, int v){

    int* res = malloc((N+1)*sizeof(int));

    res[0] = v;

    for (int k = 1; k < N+1; ++k){
        res[k] = arr[k-1];
    }

    return res;

}

int main()
{
    int *arr;
    arr = malloc(N * sizeof(int));

    for (int i = 0; i < N; i++)
    {
        arr[i] = i;
    }

    printf("The original: ");
    print(arr, N);

    int *reversed = reverse(arr, N);

    // free(arr);

    printf("The reversed: ");
    print(reversed, N);

    int *prepended = prepend(reversed, 5);

    free(reversed);

    printf("The prepended: ");
    print(prepended, N + 1);
}

