#include <stdio.h>
#include <stdlib.h>
#define N 20

struct node {
    int key;
    struct node *next;
};

struct node *convertArraytoLinkedList(int *arr, int n){
    struct node *root = malloc(sizeof(struct node));

    // assume array is not empty
    struct node *t;

    root->key = arr[0];

    t = root;
    
    for (int k = 1 ; k < n ; ++k){
        struct node *no = malloc(sizeof(struct node));

        no->key = arr[k];
        t->next = no;
        t = no;

        if(k == n-1){
            no->next = NULL;
        }

    }

    struct node * res = root;
    return res;


}

void print(struct node *curr){

    while ( curr != NULL){
        printf("%d",curr->key);
        printf("%s",",");
        curr = curr->next;
    }

}

struct node *reverseLinkedList(struct node *head){

    // list larger than two nodes

    struct node* prev = head;
    struct node* next = head;

    next = next->next;
    head->next = NULL;
    head = next;



    // now linked list looks like : null<-n1 n2->n3->...  

    while(head->next != NULL){

        // invariant, prev points to previous node, head and next to the current one and there is a "gap" between head and previous
        next = next->next;

        head->next = prev;

        prev = head;
        head = next;


    }

    head->next = prev;


    return head;

}

int main()
{
    /* Generating an array of N random integers */
    int *arr;
    arr = malloc(N * sizeof(int));

    for (int i = 0; i < N; i++)
    {
        *(arr + i) = i;
    }

    struct node *head = convertArraytoLinkedList(arr, N);

    printf("\nThe original: ");
    printf("%s","\n");
    print(head);

    struct node *newHead = reverseLinkedList(head);

    printf("\nThe reversed: ");
    print(newHead);

    return 1;
}

