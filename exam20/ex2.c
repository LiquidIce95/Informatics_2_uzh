#include <stdio.h>

struct node {

    int key;
    // next node
    struct node* p;
    // previous node
    struct node* n;   
};

// swap nodes a and b, swap the objects not only the keys
void swap(struct node* a, struct node* b,struct node* head, struct node* tail){
    // we change the pointers 
    // left neighbour of a
    struct node* lna;
    // right neigbour a
    struct node* rna;

    struct node* lnb;
    struct node* rnb;

    // iterator
    struct node* iter = head;


    while(iter != tail){
        if(iter->n == a){
            // iter is lna
            lna = iter;

        }
        if(iter->p == a){
            rna = iter;
        }

        if(iter->n == b){
            lnb = iter;
        }
        if(iter->p == b){
            rnb = iter;
        
        }

        iter = iter->n;
    }

    // invariant : rna,lna,rnb,lnb are pointing correctly

    if(lna != NULL){
        lna->n = b;
    }
    if(rna != NULL){
        rna->p = b;
    }

    if(lnb != NULL){
        lnb->n = a;
    }
    
    if(rnb != NULL){
        rnb->p = a;
    }

    b->p = lna;
    b->n = rnb;

    a->p = lnb;
    a->n = rnb;

    
}



int main(){
    return 0;
}