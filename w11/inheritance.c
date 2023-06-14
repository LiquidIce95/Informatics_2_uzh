#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// first possibility of inheritance
typedef struct {
    int (*foo)(int a, int b);
    void* (*class1)(int a );
    int x;
    char* y;
} class1;

typedef struct {
    void (*z)();
    int z2;
} class2;

typedef struct {
    class1 base1;
    class2 base2;
} poly;


// second possibility more syntax but recursive definitions possible
struct node{
    struct node* next;
    int val;
};

struct node2{
    struct node root;
};

typedef struct {
    struct node* start;
} linkedlist;

int main(){


    // creating 'objects'
    class1* ob1 = malloc(sizeof(class1));
    ob1->x = 22;
    ob1->y = "balbal";

    poly* ob2 = malloc(sizeof(poly));

    linkedlist* li = malloc(sizeof(linkedlist));

    li->start = NULL;

    

    return 0;
}