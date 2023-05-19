// for any string there exists a solution since a single character
// is a palindrome
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

//checks if a string is a palindrome
// assuming end < strlen(word)
bool is_palin(char* word, int start, int end){
    int k = start;
    while(k < end-k-1 && word[k] == word[end-k-1]){
        k++;
    }

    if (k < end-k){
        return false;
    }
    else{
        return true;
    }

}



// initializes a char array
char* init_str(char word[]){
    int len = strlen(word);

    char* res = malloc(sizeof(char)*len);

    for(int k = 0; k < len; k++){
        res[k] = word[k];
    }

    return res;
}

//wrapper for the actual function
int findMinCut_rec(char* word){
    // this is the most cuts it could possibly have
    int* cuts = malloc(sizeof(int)*strlen(word));
    return 0;
}


int findMinCutsDP(){
    return 0;
}

int main(){

    //testing is palindrome
    printf("%s", "test 1: #####\n");
    char* word = init_str("boo");
    bool expected = false;
    bool result = is_palin(word,0,strlen(word));

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
    result = is_palin(word,0,strlen(word));

    printf("%s","expected: "); printf("%d",expected); printf("%s","\n");
    printf("%s", "result: "); printf("%d",result); printf("%s","\n");

    
    if(result == expected){
        printf("\033[32m SUCCESS \033[0m\n");
    }
    else{
        printf("\033[31m FAIL \033[0m\n");
    }

    // testing recursive find min cuts *******************************************
    // Test 1: Single character string
    printf("Test 1: Single character string\n");
    word = "a";
    expected = 0;
    result = findMinCutsRecursive(word, 0, strlen(word) - 1);
    printf("Expected: %d\n", expected);
    printf("Result: %d\n", result);
    if(result == expected){
        printf("\033[32m SUCCESS \033[0m\n");
    } else {
        printf("\033[31m FAIL \033[0m\n");
    }

    // Test 2: Two character palindrome string
    printf("Test 2: Two character palindrome string\n");
    word = "aa";
    expected = 0;
    result = findMinCutsRecursive(word, 0, strlen(word) - 1);
    printf("Expected: %d\n", expected);
    printf("Result: %d\n", result);
    if(result == expected){
        printf("\033[32m SUCCESS \033[0m\n");
    } else {
        printf("\033[31m FAIL \033[0m\n");
    }

    // Test 3: Two character non-palindrome string
    printf("Test 3: Two character non-palindrome string\n");
    word = "ab";
    expected = 1;
    result = findMinCutsRecursive(word, 0, strlen(word) - 1);
    printf("Expected: %d\n", expected);
    printf("Result: %d\n", result);
    if(result == expected){
        printf("\033[32m SUCCESS \033[0m\n");
    } else {
        printf("\033[31m FAIL \033[0m\n");
    }

    // Test 4: Three character palindrome string
    printf("Test 4: Three character palindrome string\n");
    word = "aba";
    expected = 0;
    result = findMinCutsRecursive(word, 0, strlen(word) - 1);
    printf("Expected: %d\n", expected);
    printf("Result: %d\n", result);
    if(result == expected){
        printf("\033[32m SUCCESS \033[0m\n");
    } else {
        printf("\033[31m FAIL \033[0m\n");
    }

    // Test 5: Three character non-palindrome string
    printf("Test 5: Three character non-palindrome string\n");
    word = "abc";
    expected = 2;
    result = findMinCutsRecursive(word, 0, strlen(word) - 1);
    printf("Expected: %d\n", expected);
    printf("Result: %d\n", result);
    if(result == expected){
        printf("\033[32m SUCCESS \033[0m\n");
    } else {
        printf("\033[31m FAIL \033[0m\n");
    }

    // Test 6: String with all same characters
    printf("Test 6: String with all same characters\n");
    word = "aaaaa";
    expected = 0;
    result = findMinCutsRecursive(word, 0, strlen(word) - 1);
    printf("Expected: %d\n", expected);
    printf("Result: %d\n", result);
    if(result == expected){
        printf("\033[32m SUCCESS \033[0m\n");
    } else {
        printf("\033[31m FAIL \033[0m\n");
    }

    // Test 7: String with no palindromic substring
    printf("Test 7: String with no palindromic substring\n");
    word = "abcdef";
    expected = 5;
    result = findMinCutsRecursive(word, 0, strlen(word) - 1);
    printf("Expected: %d\n", expected);
    printf("Result: %d\n", result);
    if(result == expected){
        printf("\033[32m SUCCESS \033[0m\n");
    } else {
        printf("\033[31m FAIL \033[0m\n");
    }

    // Test 8: String with palindromic substring at the beginning
    printf("Test 8: String with palindromic substring at the beginning\n");
    word = "abaccdef";
    expected = 5;
    result = findMinCutsRecursive(word, 0, strlen(word) - 1);
    printf("Expected: %d\n", expected);
    printf("Result: %d\n", result);
    if(result == expected){
        printf("\033[32m SUCCESS \033[0m\n");
    } else {
        printf("\033[31m FAIL \033[0m\n");
    }

    // Test 9: String with palindromic substring at the end
    printf("Test 9: String with palindromic substring at the end\n");
    word = "abcdefgabba";
    expected = 6;
    result = findMinCutsRecursive(word, 0, strlen(word) - 1);
    printf("Expected: %d\n", expected);
    printf("Result: %d\n", result);
    if(result == expected){
        printf("\033[32m SUCCESS \033[0m\n");
    } else {
        printf("\033[31m FAIL \033[0m\n");
    }

    // testing find min cuts *******************************************
    // Test 1: Single character string
    printf("Test 1: Single character string\n");
    word = "a";
    expected = 0;
    result = findMinCutsDP(word, 0, strlen(word) - 1);
    printf("Expected: %d\n", expected);
    printf("Result: %d\n", result);
    if(result == expected){
        printf("\033[32m SUCCESS \033[0m\n");
    } else {
        printf("\033[31m FAIL \033[0m\n");
    }

    // Test 2: Two character palindrome string
    printf("Test 2: Two character palindrome string\n");
    word = "aa";
    expected = 0;
    result = findMinCutsDP(word, 0, strlen(word) - 1);
    printf("Expected: %d\n", expected);
    printf("Result: %d\n", result);
    if(result == expected){
        printf("\033[32m SUCCESS \033[0m\n");
    } else {
        printf("\033[31m FAIL \033[0m\n");
    }

    // Test 3: Two character non-palindrome string
    printf("Test 3: Two character non-palindrome string\n");
    word = "ab";
    expected = 1;
    result = findMinCutsDP(word, 0, strlen(word) - 1);
    printf("Expected: %d\n", expected);
    printf("Result: %d\n", result);
    if(result == expected){
        printf("\033[32m SUCCESS \033[0m\n");
    } else {
        printf("\033[31m FAIL \033[0m\n");
    }

    // Test 4: Three character palindrome string
    printf("Test 4: Three character palindrome string\n");
    word = "aba";
    expected = 0;
    result = findMinCutsDP(word, 0, strlen(word) - 1);
    printf("Expected: %d\n", expected);
    printf("Result: %d\n", result);
    if(result == expected){
        printf("\033[32m SUCCESS \033[0m\n");
    } else {
        printf("\033[31m FAIL \033[0m\n");
    }

    // Test 5: Three character non-palindrome string
    printf("Test 5: Three character non-palindrome string\n");
    word = "abc";
    expected = 2;
    result = findMinCutsDP(word, 0, strlen(word) - 1);
    printf("Expected: %d\n", expected);
    printf("Result: %d\n", result);
    if(result == expected){
        printf("\033[32m SUCCESS \033[0m\n");
    } else {
        printf("\033[31m FAIL \033[0m\n");
    }

    // Test 6: String with all same characters
    printf("Test 6: String with all same characters\n");
    word = "aaaaa";
    expected = 0;
    result = findMinCutsDP(word, 0, strlen(word) - 1);
    printf("Expected: %d\n", expected);
    printf("Result: %d\n", result);
    if(result == expected){
        printf("\033[32m SUCCESS \033[0m\n");
    } else {
        printf("\033[31m FAIL \033[0m\n");
    }

    // Test 7: String with no palindromic substring
    printf("Test 7: String with no palindromic substring\n");
    word = "abcdef";
    expected = 5;
    result = findMinCutsDP(word, 0, strlen(word) - 1);
    printf("Expected: %d\n", expected);
    printf("Result: %d\n", result);
    if(result == expected){
        printf("\033[32m SUCCESS \033[0m\n");
    } else {
        printf("\033[31m FAIL \033[0m\n");
    }

    // Test 8: String with palindromic substring at the beginning
    printf("Test 8: String with palindromic substring at the beginning\n");
    word = "abaccdef";
    expected = 5;
    result = findMinCutsDP(word, 0, strlen(word) - 1);
    printf("Expected: %d\n", expected);
    printf("Result: %d\n", result);
    if(result == expected){
        printf("\033[32m SUCCESS \033[0m\n");
    } else {
        printf("\033[31m FAIL \033[0m\n");
    }

    // Test 9: String with palindromic substring at the end
    printf("Test 9: String with palindromic substring at the end\n");
    word = "abcdefgabba";
    expected = 6;
    result = findMinCutsDP(word, 0, strlen(word) - 1);
    printf("Expected: %d\n", expected);
    printf("Result: %d\n", result);
    if(result == expected){
        printf("\033[32m SUCCESS \033[0m\n");
    } else {
        printf("\033[31m FAIL \033[0m\n");
    }

    return 0;
}