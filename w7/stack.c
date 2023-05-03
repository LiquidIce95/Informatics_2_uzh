#include <stdio.h>
#include <stdlib.h>

//stack and queue with arrays
//assumption: zero is gargabe value element
struct stack{
    int top;
    int* array;
    int size;

};
// invariant: top points to the top element
void push(struct stack* S,int ele){
    if ( S->top < S->size){
        S->top++;
        S->array[S->top] = ele;
    }
    else{
        printf("s","Stack is full");
    }
}

void pop(struct stack* S){
    S->array[S->top] = 0;
    if(S->top >=0 ){
        S->top--;
    } else{
        printf("%s","stack is empty");
    }
}

void print_arr(int* arr,int size){
    for (int k = 0; k < size; k++){
       printf("%d",arr[k]);

    }
    printf("%s","\n");


}
// we enquee at head and dequeeu at tail
struct Queue{
    int * arr;
    int size;
    int head;
    int tail;

};

// tail is index of last element in queue
void enque(struct Queue* Q, int size, int ele){
    
    if((Q->tail+1)% size != Q->head || Q->arr[Q->head] == 0){
        Q->tail += 1;
        Q->tail %= size;
        Q->arr[Q->tail] = ele;

    } else{
        printf("%s","queue is full");
    }
}

void deque(struct Queue* Q, int size){
    
    Q->arr[Q->head] = 0;
    Q->head += 1;
    Q->head %= size;

}

//Stack and queue with linked list (single)

struct node{
    int value;
    struct node* next;
};

// needs to be initialized with had = NULL
struct stack2{
    struct node* head;
};

// to get O(1) for push and pop we need to add and delete elements to head
void push2(struct stack2* S,int element){
    struct node* N = malloc(sizeof(struct node));
    N->value = element;
    N->next = S->head;
    S->head = N;
}

void pop2(struct stack2* S){
    struct node* temp = S->head->next;

    free(S->head);
    S->head = temp;

    
}

struct Queue2{
    struct node* head;
    struct node* tail;
};

void enqueue2(struct Queue2* Q, int element){
    struct node* n = malloc(sizeof(struct node));

    n->value = element;
    Q->tail->next = n;
    n->next = NULL;


}

void deque2(struct Queue2* Q, int element){
    
    struct Queue2* temp = Q->head->next;

    free(Q->head);
    Q->head = temp;


}



int main(){
    //some tets cases
    //init the Stack
    struct stack* S = malloc(sizeof(struct stack));

    int size = 5;
    S->array = malloc(sizeof(int)*size);
    S->size = size;
    S->top = -1;

    push(S,3);
    print_arr(S->array,S->size);
    push(S,5);
    print_arr(S->array,S->size);
    pop(S);
    print_arr(S->array,S->size);
    pop(S);
    print_arr(S->array,S->size);


    printf("%s","queue tests\n");
    //tests for queue
    struct Queue* Q = malloc(sizeof(struct Queue));
    int size2 = 5;
    Q->arr = malloc(sizeof(int)*size2);
    Q->head = 0;
    Q->tail = -1;
    Q->size = size2;

    enque(Q,size2,3);

    print_arr(Q->arr,size2);

    enque(Q,size2,4);

    print_arr(Q->arr,size2);

    deque(Q,size2);

    print_arr(Q->arr,size2);

    deque(Q,size2);

    print_arr(Q->arr,size2);

    enque(Q,size2,1);

    enque(Q,size2,4);

    enque(Q,size2,9);

    print_arr(Q->arr,size2);

    enque(Q,size2,11);

    print_arr(Q->arr,size2);





    return 0;
}