#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct  TreeNode{
    int val;
    struct TreeNode* left;
    struct TreeNode* right;


};


struct TreeNode* init_TreeNode(int val, struct TreeNode* left, struct TreeNode* right){
    struct TreeNode* node = malloc(sizeof(struct TreeNode));
    node->val = val;
    node->right = right;
    node->left = left;
    return node;
}


//returns the correct leaf possition
struct TreeNode* find_leaf(struct TreeNode* root,int value){

    struct TreeNode* lch = root->left;
    struct TreeNode* rch = root->right;

    if ( lch != NULL && value <= root->val ){
        return find_leaf(lch,value);
    }

    else if (rch != NULL && root->val < value){
        return find_leaf(rch,value);
    }
    else {
        return root;
    }

}
//returns a node if the vlaue is equal and its parent node left or right pointer, need this for setting it to NULL later


void insert(struct TreeNode* root, int value){

    root = find_leaf(root,value);

    struct TreeNode* v = init_TreeNode(value,NULL,NULL);
    

    if (value <= root->val ){
        root->left = v; 
    }

    else {
        root->right = v;
    }

}

struct TreeNode** find_successor(struct TreeNode* root){
    struct TreeNode* par = NULL;
    struct TreeNode** res = malloc(sizeof(struct TreeNode*)*2);


    if(root->right==NULL){
        res[0] = NULL;
        res[1] = NULL;

        return res;

    }

    else {
        root = root->right;
    }


    while(root->left != NULL){
        par = root;
        root = root->left;
    }


    res[0] = root;
    res[1] = par;

    return res;
}

struct TreeNode** find_predeseccor(struct TreeNode* root){
    struct TreeNode** res = malloc(sizeof(struct TreeNode)*2);
    struct TreeNode* par = NULL;

    if(root->left == NULL){
        res[0] = NULL;
        res[1] = NULL;
        return res;

    }
    else{
        root = root->left;
    }

    while(root->right != NULL){
        par = root;
        root = root->right;
    }

    res[0] = root;
    res[1] = par;

    return res;
}

void swap(struct TreeNode* A, struct TreeNode* B){
    struct TreeNode* temp = A;
    A = B;
    B = temp;

}



//for this we implement BFS search
void pre_order(struct TreeNode* root){
    printf("%d",root->val);

    struct TreeNode* left = root->left;
    struct TreeNode* right = root->right;

    if(left != NULL){
        pre_order(left);
    }

    if(right != NULL){
        pre_order(right);
    }


}

//for this we implement BFS search
void post_order(struct TreeNode* root){

    struct TreeNode* left = root->left;
    struct TreeNode* right = root->right;

    if(left != NULL){
        post_order(left);
    }

    if(right != NULL){
        post_order(right);
    }

    printf("%d",root->val);

}

//for this we implement BFS search
void in_order(struct TreeNode* root){

    struct TreeNode* left = root->left;
    struct TreeNode* right = root->right;

    if(left != NULL){
        in_order(left);
    }

    printf("%d",root->val);

    if(right != NULL){
        in_order(right);
    }

}

void traverse(struct TreeNode* root){
    printf("%s","\npre_order:\n");

    pre_order(root);

    printf("%s","\nin_order\n");

    in_order(root);

    printf("%s","\npost_order\n");
    
    post_order(root);


}

void print_edge(struct TreeNode* A, struct TreeNode* B, int level){
    printf("%s","\n");
    printf("%s","Node ");
    printf("%d",A->val);
    printf("%s"," -- ");
    printf("%s","Node ");
    printf("%d",B->val);
    printf("%s"," : ");
    printf("%d",level);
    

}

void print_tree2(struct TreeNode* root,int lvl){
    if(root->left != NULL){
        print_edge(root,root->left,lvl);
        print_tree2(root->left,lvl+1);
    }

    if(root->right != NULL){
        print_edge(root,root->right,lvl);
        print_tree2(root->right,lvl+1);
    }
    
}

void print_tree(struct TreeNode* root){
    print_tree2(root,1);

}

//finds the node with the value 'val' and returns that node and its parent pointer 
//which is pointing to it or returns NULL, if that node is not in the tree
//both are pointed by another pointer node_par[0] is the pointer to the pointer of the root pointer of the tree
//node_par[0] and node_par[1] must be initialized with NULL
struct TreeNode*** find_node(int value, struct TreeNode** parent_ptr, struct TreeNode** child_ptr) {
    if ((*child_ptr) == NULL) {
        return NULL;
    }
    if ((*child_ptr)->val == value) {
        struct TreeNode*** node_par = malloc(sizeof(struct TreeNode**) * 2);
        node_par[1] = parent_ptr;
        node_par[0] = child_ptr;
        return node_par;
    } else if ((*child_ptr)->val < value) {
        return find_node(value, child_ptr, &((*child_ptr)->right));
    } else {
        return find_node(value, child_ptr, &((*child_ptr)->left));
    }
}


int main(){

    struct TreeNode* root = init_TreeNode(4,NULL,NULL);


    insert(root,2);

    insert(root,3);
   
    insert(root,8);
    insert(root,6);    

    insert(root,7);
    insert(root,9);
    insert(root,12);
    insert(root,1);
    print_tree(root);


    traverse(root);


    struct TreeNode** pre = find_predeseccor(root);
    struct TreeNode** succ = find_successor(root);

    printf("%s","\npre:\n");
    printf("%d",pre[0]->val);


    printf("%s","\nsucc:\n");
    printf("%d",succ[0]->val);

    printf("%s","\n");

    //delete(root,4);

    //delete(root,12);

    //delete(root,2);

    print_tree(root);


    traverse(root);


    //testing find_node
    struct TreeNode*** res = malloc(sizeof(struct TreeNode**)*2);

    res[0] = NULL;
    res[1] = &root;


    res = find_node(9,res[0],res[1]);

    printf("%s","\n");
    printf("%d",(*res[0])->val);
    printf("%s","\n");
    printf("%d",(*res[1])->val);

    return 0;
}