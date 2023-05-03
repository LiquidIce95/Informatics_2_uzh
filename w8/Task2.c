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

struct TreeNode** find_predecessor(struct TreeNode* root){
    struct TreeNode** res = malloc(sizeof(struct TreeNode*)*2);
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

//swap the objects the pointers are pointing to
void swap(struct TreeNode* A, struct TreeNode* B){
    struct TreeNode temp = *A;
    *A = *B;
    *B = temp;

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

//assuming that the trees nodes are uniquely identified with their int value, or that it does not matter
void del_node(int value, struct TreeNode** root){
    struct TreeNode** root_p = &root;

    struct TreeNode*** root_par = find_node(value,NULL,root_p);

    //first we check if there is a predecessor node 
    struct TreeNode* to_del = *root_par[0];

    struct TreeNode** to_del_p = root_par[1];

    struct TreeNode** pre_par = find_predecessor(to_del);

    //check if predecessor exists
    bool l = false;
    if(pre_par[0] == NULL){
        //in this case look for sucessor
        pre_par = find_successor(to_del);
        l = true;
    }

    //now check if the successor or predecessor are valid 
    if(l == false && pre_par[1] != NULL){
        //swap predecessor and to_del , then delete to_del, then set par pointer to to_del to NULL
        swap(pre_par[1],to_del);
        free(to_del);
        pre_par[1]->right = NULL;
    }
    else if (l == true && pre_par[1] != NULL){
        swap(pre_par[1], to_del);
        free(to_del);
        pre_par[1]->left = NULL;
    } 
    else{
        //in this case we dont have a valid successor or predecessor, where we can swap and then delete, so we must use a differnet function instead
        //TODO implement this function
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


    struct TreeNode** pre = find_predecessor(root);
    struct TreeNode** succ = find_successor(root);

    printf("%s","\npre:\n");
    printf("%d",pre[0]->val);


    printf("%s","\nsucc:\n");
    printf("%d",succ[0]->val);

    printf("%s","\n");


    //TESTING swap function
    struct TreeNode* a = init_TreeNode(3,NULL,NULL);

    struct TreeNode* b = init_TreeNode(10,NULL,NULL);

    struct TreeNode* c = init_TreeNode(5,a,b);

    swap(a,b);
    printf("%s","swap test\n");
    printf("%d",a->val);
    printf("%s"," value of node a ");
    printf("%s","\n");
    printf("%d",b->val);
    printf("%s"," value of b\n");
    printf("%d",c->left->val);
    printf("%s"," value of root.left\n");


    //del_node(4,&root);

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