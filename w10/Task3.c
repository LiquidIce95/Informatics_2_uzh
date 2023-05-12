#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// hashing class/struct with integers as elements to be stored 
// using open addressing : double hashing only
// no deletion
struct HashingTable{
    int (*hashfun)(int ele, int size, int probnum);
    int (*insertion)(struct HashingTable* table, int ele);
    int (*search)(struct HashingTable* table, int ele);
    void (*print)(struct HashingTable*);
    int* array;
    int size;

};

struct HashingTable* init(int (*hashfun)(int ele,int size,int probnum),int (*insertion)(struct HashingTable* table, int ele),
    int (*search)(struct HashingTable* table,int ele),void (*print)(struct HashingTable* table), int size){

    struct HashingTable* table = malloc(sizeof(struct HashingTable));

    table->hashfun = hashfun;
    table->insertion = insertion;
    table->search = search;
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

// inserts and returns the hashed index
int insertion(struct HashingTable* table, int ele){
    int probnum = 0;
    int index = table->hashfun(ele,table->size,probnum);

    while(table->array[index] != 0 && index < table->size){
        probnum++;
        index = table->hashfun(ele,table->size,probnum);        
    }

    if(index >= table->size){
        printf("%s", "Hash table overflow");
        return -1;
    }

    return index;
}

// returns the index of the element in the table, otherwise -1
int search(struct HashingTable* table, int ele){
    int probnum = -1;
    int size = table->size;
    int index = -1;

    while(index < size && table->array[index] != ele){
        index = table->hashfun(ele,size,++probnum);
    }

    if(table->array[index] != ele){
        return -1;
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

int main(){

    
    // unitests for insertion
    struct HashingTable* table = init(hashfun1,insertion,search,print,30);


    printf("%s", "UNIT TESTS FOR INSETION\n");

    printf("%s", "test 1: #####\n");
    int expected = hashfun1(100,table->size, 0);
    int result = table->insertion(table,100);

    printf("%s","expected: "); printf("%d",expected); printf("%s","\n");
    printf("%s", "result: "); printf("%d",result); printf("%s","\n");

    
    if(result == expected){
        printf("\033[32m SUCCESS \033[0m\n");
    }
    else{
        printf("\033[31m FAIL \033[0m\n");
    }

    printf("%s", "test 2: #####\n");
    expected = hashfun1(30,table->size, 0);
    result = table->insertion(table,30);

    printf("%s","expected: "); printf("%d",expected); printf("%s","\n");
    printf("%s", "result: "); printf("%d",result); printf("%s","\n");

    
    if(result == expected){
        printf("\033[32m SUCCESS \033[0m\n");
    }
    else{
        printf("\033[31m FAIL \033[0m\n");
    }

    printf("%s", "test 3: #####\n");
    expected = hashfun1(2,table->size, 0);
    result = table->insertion(table,2);

    printf("%s","expected: "); printf("%d",expected); printf("%s","\n");
    printf("%s", "result: "); printf("%d",result); printf("%s","\n");

    
    if(result == expected){
        printf("\033[32m SUCCESS \033[0m\n");
    }
    else{
        printf("\033[31m FAIL \033[0m\n");
    }


    // Unit tests for search 
    printf("%s", "UNIT TESTS FOR SEARCH******************\n");

    //TODO: search does not terminate...
    printf("%s", "test 1: #####\n");
    expected = 11;
    result = table->search(table,100);

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