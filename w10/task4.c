#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


struct Ele{
    int key;
    int status; // 0 occupied, -1: Empty
};

// hashing class/struct with integers as elements to be stored 
// using open addressing : double hashing only
// with deletion
struct HashingTable{
    int (*hashfun)(int ele, int size, int probnum);
    int (*insertion)(struct HashingTable* table, int ele);
    int (*search)(struct HashingTable* table, int ele);
    void (*delete)(struct HashingTable* table, int key);
    void (*print)(struct HashingTable*);
    struct Ele* array;
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
    table->array = malloc(sizeof(struct Ele)*size);
    table->size = size;

    // use 0 as garbage value/ empty value
    for(int k = 0; k < size; k++){
        table->array[k].key = -1;
        table->array[k].status = -1;
    }

    return table;
    
} 

// given from exercise
int hashfun1(int ele, int size, int probnum){

    return ele%size;

}

// inserts and returns the hashed index, open addressing : linear probing
int insertion(struct HashingTable* table, int ele){
    int probnum = 0;
    int init_index = table->hashfun(ele,table->size,0);
    int index = init_index;
    int size = table->size;

   while(table->array[index].status == 0 ){
        index = (++index)%size;
        if(index == init_index){
            // table is full
            return -1;
        }
   }

    table->array[index].key = ele;
    table->array[index].status = 0;

    return index;
}

// returns the index of the element in the table, otherwise -1
int search(struct HashingTable* table, int ele){
    int probnum = 0;
    int init_index = table->hashfun(ele,table->size,0);
    int index = init_index;
    int size = table->size;

   while(table->array[index].key != ele ){
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
        printf("%d",table->array[k].key);
        printf("%s","\n");
    }
    
    printf("%s","\n");

}

// the goal is to leave the hash table after deletion in the same state as if key k has never been inserted
// naive approach would be to rehash the entire cluster (consecutive elements which are occupied) , since every element has either
// gotten its index by first time hash or probing which is consitent with the example 
// every element after the deleted one must thus be rehashed again
// note my personal solution would be to implement search such that we can simply delete the element instead of rehashing the cluster
void delete(struct HashingTable* table, int key){

    key = search(table,key);

    table->array[key].status = -1;
    table->array[key].key = -1;

    int k = (key+1)%table->size;

    while(table->array[k].status == 0){
        int temp = table->array[k].key;
        table->array[k].status = -1;
        table->array[k].key = -1;
        
        table->insertion(table,temp);
        k = (k+1)%table->size;

    }

    return ;
}


int main(){

    struct HashingTable* table = init(hashfun1,insertion,search,print,delete,5);


    table->array[1].status = 0;
    table->array[1].key = 11;
    table->array[2].status = 0;
    table->array[2].key = 22;
    table->array[3].status = 0;
    table->array[3].key = 31;
    table->array[4].status = 0;
    table->array[4].key = 2;

    table->print(table);

    table->delete(table,11);

    table->print(table);


    return 0;
}