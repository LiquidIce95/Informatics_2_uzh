// for any string there exists a solution since a single character
// is a palindrome
// 
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

bool is_palin(char* word){
    int size = strlen(word);
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

char* init_str(char word[]){
    int len = strlen(word);

    char* res = malloc(sizeof(char)*len);

    for(int k = 0; k < len; k++){
        res[k] = word[k];
    }

    return res;
}

int main(){

    //testing is palindrome
    printf("%s", "test 1: #####\n");
    char* word = init_str("boo");
    bool expected = false;
    bool result = is_palin(word);

    printf("%s","expected: "); printf("%d",expected); printf("%s","\n");
    printf("%s", "result: "); printf("%d",result); printf("%s","\n");

    
    if(result == expected){
        printf("\033[32m SUCCESS \033[0m\n");
    }
    else{
        printf("\033[31m FAIL \033[0m\n");
    }

    printf("%s", "test 2: #####\n");

    free(word);
    word = init_str("abaaba");
    expected = true;
    result = is_palin(word);

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