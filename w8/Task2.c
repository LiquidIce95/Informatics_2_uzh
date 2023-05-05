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


//swap the objects the pointers are pointing to
void swap(struct TreeNode** A, struct TreeNode** B){
    int temp = (*A)->val;
    (*A)->val = (*B)->val;
    (*B)->val = temp;

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
//return on [0] the actual predecessor and on [1] the pointer of its parent to itself
struct TreeNode*** predecessor(struct TreeNode* root){
    if(root->left == NULL){
        return NULL;
    }

    root = root->left;

    //however this is not a valid inorder predecessor yet
    if(root->right == NULL){
        return NULL;
    }

    struct TreeNode*** res = malloc(sizeof(struct TreeNode**)*2);


    //since we know at this point that we can at least go once to the right, this will ba a valid return
    while(root->right != NULL){

        res[1] = &(root->right);
        root = root->right;
    }


    res[0] = &root;

    return res;


}

//look at predecessor since its analogous
struct TreeNode*** successor(struct TreeNode* root){
    if(root->right == NULL){
        return NULL;
    }

    root = root->right;

    if(root->left == NULL){
        root = root->left;
    }


    struct TreeNode*** res = malloc(sizeof(struct TreeNode**)*2);

    while(root->left != NULL){
        res[1] = &(root->left);
        root = root->left;
    }


    res[0] = &root;

    return res;
}

//PRE: root_par[0] is the pointer to the node N which should be deleted and root_par[1] is the pointer of the parent, that is 
// pointing to N
void left_case(struct TreeNode*** root_par){
    // first we check if there is a in-order predecessor
    struct TreeNode*** prede = predecessor(*root_par[0]);

    //check if the prede is valid
    if(prede == NULL){
        //now we know that the left chidl of root_par[0] has no right child, which means if root_par[0] itself has
        //a right child, then we can give root_par[0]->right to root_par[0], effectively making the left child the new root
        if((*root_par[0])->right != NULL){
            (*root_par[0])->left->right = (*root_par[0])->right;
        }

        //now we set the parent 
        (*root_par[1]) = (*root_par[0])->left;

        free(*root_par[0]);

    }

    else {
        //swap root_par[0] and prede, then delete prede
        //TODO: somehow prede[0] does not get passed on to swap properly, but root_par[0] does even though they have the same datatype?
        swap(prede[0],root_par[0]);
        free(prede[0]);
        *prede[1] = NULL;

    }
    
}

//completely analogous to left case
void right_case(struct TreeNode*** root_par){
    struct TreeNode*** succe = successor(*root_par[0]);

    if(succe == NULL){
        if((*root_par[0])->left != NULL){
            (*root_par[0])->right->left = (*root_par[0])->left;
        }

        (*root_par[1]) = (*root_par[0])->right;

        free(*root_par[0]);
    }

    else{
        swap(succe[0],root_par[0]);
        free(succe[0]);
        *succe[1] = NULL;
    }

}

//asssuming that root is the root of the entire tree so parent pointer is null
//assuming there exists a inorder successor or predecessor
void del_node(int value, struct TreeNode** root){
    //first ewe need to find the node to be deleted and its parent pointer to it
    struct TreeNode*** root_parent = find_node(value,NULL,root);

    //if the node s a leaf, we can simply delete it and and set the parentpointer to null
    if((*root_parent[0])->left == NULL && (*root_parent[1])->right == NULL){
        free((*root_parent[0]));
        (*root_parent[1]) = NULL;

    }

    //now there are the following cases, if there is a left child there could or could not be a in-order predecessor we
    if((*root_parent[0])->left != NULL){
        left_case(root_parent);
    }
    //analogously if there is a right child there could or could not be a in-order successsor
    else {
        right_case(root_parent);
    }

    //after these cases we successfully deleted the node


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


    //TESTING swap function
    struct TreeNode* a = init_TreeNode(3,NULL,NULL);

    struct TreeNode* b = init_TreeNode(10,NULL,NULL);

    struct TreeNode* c = init_TreeNode(5,a,b);

    swap(&a,&b);
    printf("%s","swap test\n");
    printf("%d",a->val);
    printf("%s"," value of node a ");
    printf("%s","\n");
    printf("%d",b->val);
    printf("%s"," value of b\n");
    printf("%d",c->left->val);
    printf("%s"," value of root.left\n");

    printf("%s","\n testing deletion *******************\n");

    //deleting a key that does not exist
    del_node(4,&root);


    //deleting the root
    //del_node(2,&root);

    print_tree(root);


    traverse(root);


    printf("%s","\n testing end deletion ****************\n");


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