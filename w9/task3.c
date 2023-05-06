#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// given TreeNode struct
struct TreeNode{
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
    struct TreeNode* par;
};


struct TreeNode* init_tn(int val, struct TreeNode* left, struct TreeNode* right,  struct TreeNode* par){
    struct TreeNode* new_node = malloc(sizeof(struct TreeNode));
    new_node->val = val;
    new_node->left = left;
    new_node->right = right;
    new_node->par = par;

    return new_node;
}
// assuming root != NULL
// signature given from exercise
struct TreeNode* search(struct TreeNode* root, int val){
    struct TreeNode** curr = &root;


    while(*curr != NULL && val != (*curr)->val){
        if(val < (*curr)->val){
            (*curr) = (*curr)->left;
        }
        else{
            (*curr) = (*curr)->right;
        }
    }

    return *curr;

}
// return correct leaf parent pointer for insertion
// assuming root != NULL
struct TreeNode** search2(struct TreeNode* root, int val){
    struct TreeNode** curr = &root;


    while(*curr != NULL){
        if(val <= (*curr)->val && (*curr)->left != NULL){
            (*curr) = (*curr)->left;
        }
        else if (val > (*curr)->val && (*curr)->right != NULL){
            (*curr) = (*curr)->right;
        }
        else if (val <= (*curr)->val){
            // in this case we reached the leaf since the next node we want to travel to is NULL
            // because the other cases did not got triggered we know that this will be the correct pointer
            return &((*curr)->left);
        }
        else if (val > (*curr)->val){
            return &((*curr)->right);
        }
    }

    // this should not be triggered
    return NULL;

}
// returns parent of the node with value val
// assuming root != NULL
struct TreeNode** search3(struct TreeNode* root, int val){
    struct TreeNode** curr = &root;


    while(*curr != NULL){
        if(val <= (*curr)->val && (*curr)->left != NULL){
            (*curr) = (*curr)->left;
        }
        else if (val > (*curr)->val && (*curr)->right != NULL){
            (*curr) = (*curr)->right;
        }
        else{
            return curr;
        }

    }

    // this should not be triggered
    return NULL;

}
// signature given from exercise
// dont know what we need root for if we have parent
struct TreeNode* insert(struct TreeNode* root,struct TreeNode* parent, int val){
    if(val <= parent->val){
        parent->left = init_tn(val,NULL,NULL,parent);
        return parent->left;

    }
    else{
        parent->right = init_tn(val,NULL,NULL,parent);
        return parent->right;
    }

    
}

// insertion without knowing the parent of the new node
struct TreeNode* insert2(struct TreeNode* root,int val){
    return insert(root,*search3(root,val),val);
}

// rotates a binary tree root on the node with value val
// returns a new root pointer
struct TreeNode* rightRotate(struct TreeNode* root, int val){
    // first lets find that root
    struct TreeNode* t = search(root,val);

    if(t == NULL){
        return NULL;
    }

    // look at diagram from exercise sheet 9 to understand the variables  to _rot is t
    struct TreeNode* S = t->left;
    struct TreeNode* beta = S->right;
    struct TreeNode* par = t->par;

    if(S == NULL){
        return NULL;
    }


    if(par != NULL && par->left == t){
        par->left = S;
    }
    else if(par != NULL){
        par->right = S;
    }

    S->right = t;
    t->left = beta;
    S->par = par;

    if(par == NULL){
        // this is the new root 
        return S;
    }
    // otherwise return root since 
    return root;


}
// to_rot is now S according to diagram
struct TreeNode* leftRotate(struct TreeNode* root, int val){
    struct TreeNode* s = search(root,val);

    if(s == NULL){
        return NULL;
    }

    struct TreeNode* t = s->right;
    struct TreeNode* beta = t->left;
    struct TreeNode* par = s->par;

    // check if we rotate root itself
    if(t == NULL){
        return NULL;
    }

    if(par != NULL && par->left == s){
        par->left = t;
    }
    else if(par != NULL){
        par->right = t;
    }

    s->right = beta;
    t->left = s;

    if(par == NULL){
        return t;

    }
    return root;


}

int main(){


    // UNITTESTS

    printf("%s","UNITTESTS FOR : search**********************\n");
    struct TreeNode* root = init_tn(10,NULL,NULL,NULL);

    root->left = init_tn(8,NULL,NULL,NULL);
    root->left->par = root;
    root->right = init_tn(17,NULL,NULL,NULL);
    root->right->par = root;

    root->left->right = init_tn(9,NULL,NULL,NULL);
    root->left->right->par = root->left;
    
    int result = search(root,9)->val;
    int expected = root->left->right->val;


    // unitests for search
    printf("%s", "test 1: #####\n");
    printf("%s","expected: "); printf("%d",expected); printf("%s","\n");
    printf("%s", "result: "); printf("%d",result); printf("%s","\n");

    
    if(result == expected){
        printf("\033[32m SUCCESS \033[0m\n");
    }
    else{
        printf("\033[31m FAIL \033[0m\n");
    }


    printf("%s", "test 2: #####\n");

    result = search(root,10)->val;
    expected = root->val;
    printf("%s","expected: "); printf("%d",expected); printf("%s","\n");
    printf("%s", "result: "); printf("%d",result); printf("%s","\n");


    if(result == expected){
        printf("\033[32m SUCCESS \033[0m\n");
    }
    else{
        printf("\033[31m FAIL \033[0m\n");
    }


    struct TreeNode* expected2 = NULL;
    struct TreeNode* result2 = search(root,-4);

    printf("%s", "test 3: #####\n");

    printf("%s","expected: "); printf("%s","NULL"); printf("%s","\n");
    printf("%s", "result: "); printf("%s","cannot print"); printf("%s","\n");


    if(result2 == expected2){
        printf("\033[32m SUCCESS \033[0m\n");
    }
    else{
        printf("\033[31m FAIL \033[0m\n");
    }


    // Unittests for search2
    printf("%s","UNITTESTS FOR : search2**********************\n");
    printf("%s", "test 1: #####\n");

    struct TreeNode** result3 = search2(root,10);
    struct TreeNode** expected3 = &(root->left->right->right);
    printf("%s","expected: "); printf("%s","no print"); printf("%s","\n");
    printf("%s", "result: "); printf("%s","no print"); printf("%s","\n");


    if(result3 == expected3){
        printf("\033[32m SUCCESS \033[0m\n");
    }
    else{
        printf("\033[31m FAIL \033[0m\n");
    }

    printf("%s", "test 2: #####\n");

    result3 = search2(root,1);
    expected3 = &(root->left->left);
    printf("%s","expected: "); printf("%s","no print"); printf("%s","\n");
    printf("%s", "result: "); printf("%s","no print"); printf("%s","\n");


    if(result3 == expected3){
        printf("\033[32m SUCCESS \033[0m\n");
    }
    else{
        printf("\033[31m FAIL \033[0m\n");
    }


    // unitests for insert2
    printf("%s","UNITTESTS FOR : insertion2**********************\n");

    printf("%s", "test 1: #####\n");

    result = insert2(root,20)->val;
    expected = root->right->right->val;
    printf("%s","expected: "); printf("%d",result); printf("%s","\n");
    printf("%s", "result: "); printf("%d",expected); printf("%s","\n");


    if(result == expected){
        printf("\033[32m SUCCESS \033[0m\n");
    }
    else{
        printf("\033[31m FAIL \033[0m\n");
    }

    printf("%s", "test 2: #####\n");

    result = insert2(root,4)->val;
    expected = root->left->left->val;
    printf("%s","expected: "); printf("%d",result); printf("%s","\n");
    printf("%s", "result: "); printf("%d",expected); printf("%s","\n");


    if(result == expected){
        printf("\033[32m SUCCESS \033[0m\n");
    }
    else{
        printf("\033[31m FAIL \033[0m\n");
    }

    printf("%s", "rotations unit tests**********************3\n");
    printf("%s", "test 1: #####\n");

    // rotation unittest
    root = rightRotate(root,10);


    if(root->val == 8 && root->left->val == 4 && root->right->val == 10 && root->right->left->val == 9
    && root->right->right->val == 17 && root->right->right->right->val == 20){
        printf("\033[32m SUCCESS \033[0m\n");
    }
    else{
        printf("\033[31m FAIL \033[0m\n");
    }

    root = leftRotate(root,8);

    printf("%s", "test 2: #####\n");

    if(root->val == 10 && root->left->val == 8 && root->left->left->val == 4 && root->left->right->val == 9
    && root->right->val == 17 && root->right->right->val == 20){
        printf("\033[32m SUCCESS \033[0m\n");
    }
    else{
        printf("\033[31m FAIL \033[0m\n");
    }

    // now testing some rotation on a non root node
    printf("%s", "test 3: #####\n");

    root = leftRotate(root,17);

    if(root->val == 10 && root->left->val == 8 && root->left->left->val == 4 && root->left->right->val == 9
    && root->right->val == 20 && root->right->left->val == 17){
        printf("\033[32m SUCCESS \033[0m\n");
    }
    else{
        printf("\033[31m FAIL \033[0m\n");
    }






    return 0;
}