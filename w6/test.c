#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
void swap(int *p, int id1, int id2) {
    *(p + id1) += *(p + id2);
    *(p + id2) = *(p + id1) - *(p + id2);
    *(p + id1) -= *(p + id2);
}


int main(){

    int a[8] = {2, 0, 2, 3, 0, 5, 2, 6};
    // swap(a, 2, 3);
    swap(&a[1], 2, 3);

    for (int k = 0; k<8; k++){
        printf("%d",a[k]);
    }

    return 0;
}

