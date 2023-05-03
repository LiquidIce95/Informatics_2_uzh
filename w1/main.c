#include  "functions.h"
#include "stddef.h"
#include "stdlib.h"
#include <stdio.h>
#include "stdbool.h"


int** mat_mul(int** array,int m , int n,int** array2, int m2, int n2){

    // Multiplication not defined
    if(n != n2 ){
        return NULL;
    }

    int **res = (int**) malloc(m * sizeof(int*));

    // initialize
    for (int i = 0; i < m; i++){

        res[i] = (int*) malloc(n * sizeof(int));
        for( int j = 0; j < n2; j++){

            res[i][j]=i+j;

        }
    }

    int val = 0;
    // MM
    for (int i = 0; i < m; i++){
        for (int j = 0; j < n2; j++){
            for ( int j2=0 ; j2 <n;j2++){
                val+= array[i][j2]*array2[j2][j];
            }
            res[i][j] = val;
            val = 0;
        }

       
    }

    return res;


}


// Task 2
int** square_mat(int** matrix,int i,int n){
    return mat_mul(matrix,i,n,matrix,i,n);
}


void print_mat(int** matrix,int m, int n){

    for( int k = 0; k < m; k++){
        for(int j = 0; j < n; j++){
            printf("%d ",matrix[k][j]);
            printf(" ");
        }
        printf("\n");
    }

}

// Task3
// Assuming arr is sorted in ascending order
bool pair_sum_optimized(int c ,int* arr, int len){

    int* l = arr[0];
    int* r = arr[len-1];

    while( l <= r){
        if( *l + * r < c){
            l++;
        }
        else if ( *l + *r >c){
            r--;
        }
        else{
            return true;
        }
    }


}


int main(){

    int** A = (int**)malloc(3*sizeof(int*));
    for ( int k = 0; k < 3 ; k++){
        A[k] = (int*)malloc(3*sizeof(int));
    }

    A[0][0] = 0;
    A[0][1] = 0;
    A[0][2] = 0;
    A[1][0] = 0;
    A[1][1] = 0;
    A[1][2] = 0;
    A[2][0] = 0;
    A[2][1] = 0;
    A[2][2] = 0;


    int** res = square_mat(A,3,3);

    print_mat(res,3,3);


    A[0][0] = 1;
    A[0][1] = 2;
    A[0][2] = 3;
    A[1][0] = 1;
    A[1][1] = 2;
    A[1][2] = 3;
    A[2][0] = 4;
    A[2][1] = 5;
    A[2][2] = 6;

    res = square_mat(A,3,3);

    print_mat(res,3,3);
    
    return 0;
}