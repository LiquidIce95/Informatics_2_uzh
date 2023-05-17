// for any string there exists a solution since a single character
// is a palindrome
// 
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

bool is_palin(char* word, int size){
    int k = 0;
    while(k < size-k && word[k] == word[size-k]){
        k++;
    }

    if (k < size-k){
        return false;
    }
    else{
        return true;
    }

}


int main(){

    //testing is palindrome
    printf("%s", "test 1: #####\n");
    bool expected = false;
    bool result = 0;
    char* word = malloc(sizeof(char)*4);

    


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