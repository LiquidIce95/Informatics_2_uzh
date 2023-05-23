#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct {
    int (*foo)(int a, int b);
    class1* (*class1)(int a );
    int x;
    char* y;
} class1;

typedef struct {
    void (*z)();
    int z;
} class2;

typedef struct {
    class1 base1;
    class2 base2;
} poly;


int main(){


    // creating 'objects'
    class1* ob1 = malloc(sizeof(class1));
    ob1->x = 22;
    ob1->y = "balbal";

    poly* ob2 = malloc(sizeof(poly));

    

    return 0;
}