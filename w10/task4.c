#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// hashing class/struct with integers as elements to be stored 
// using open addressing : double hashing only
// with deletion
struct HashingTable{
    int (*hashfun)(int ele, int size, int probnum);
    int (*insertion)(struct HashingTable* table, int ele);
    int (*search)(struct HashingTable* table, int ele);
    void (*delete)(struct HashingTable* table, int key);
    void (*print)(struct HashingTable*);
    int* array;
    int size;

};

struct HashingTable* init(int (*hashfun)(int ele,int size,int probnum),int (*insertion)(struct HashingTable* table, int ele),
    int (*search)(struct HashingTable* table,int ele),void (*print)(struct HashingTable* table), 
    int (*delete)(struct HashingTable*), int size){

    struct HashingTable* table = malloc(sizeof(struct HashingTable));

    table->hashfun = hashfun;
    table->insertion = insertion;
    table->search = search;
    table->delete = delete;
    table->print = print;
    table->array = malloc(sizeof(int)*size);
    table->size = size;

    // use 0 as garbage value/ empty value
    for(int k = 0; k < size; k++){
        table->array[k] = 0;
    }

    return table;
    
} 

// given from exercise
int hashfun1(int ele, int size, int probnum){


    return ((ele % size +1) + probnum*(size - 1 -(ele %(size-1))))%size;

}

// inserts and returns the hashed index, open addressing : linear probing
int insertion(struct HashingTable* table, int ele){
    int probnum = 0;
    int init_index = table->hashfun(ele,table->size,0);
    int index = init_index;
    int size = table->size;

   while(table->array[index] != 0 ){
        index = (index++)%size;
        if(index == init_index){
            // table is full
            return -1;
        }
   }

    table->array[index] = ele;

    return index;
}

// returns the index of the element in the table, otherwise -1
int search(struct HashingTable* table, int ele){
    int probnum = 0;
    int init_index = table->hashfun(ele,table->size,0);
    int index = init_index;
    int size = table->size;

   while(table->array[index] != ele ){
        index = (index++)%size;
        if(index == init_index){
            // table is full
            return -1;
        }
   }


    return index;
}   


// prints the table vertically
void print(struct HashingTable* table){
    int siz = table->size;

    for(int k = 0; k < siz; k++){
        printf("%d",table->array[k]);
        printf("%s","\n");
    }
    
    printf("%s","\n");

}

void delete(struct HashingTable* table, int key){

    return ;
}


int main(){

    struct HashingTable* table = init(hashfun1,insertion,search,print,delete,10);

    table->insertion(table,10);
    table->insertion(table,4);
    table->insertion(table,2);
    table->insertion(table,11);


    // Unittests for deletion
    printf("%s", "test 1: #####\n");
    int expected =0;
    int result = 0;

    printf("%s","expected: "); printf("%d",expected); printf("%s","\n");
    printf("%s", "result: "); printf("%d",result); printf("%s","\n");

    
    if(result == expected){
        printf("\033[32m SUCCESS \033[0m\n");
    }
    else{
        printf("\033[31m FAIL \033[0m\n");
    }




    return 0;
}