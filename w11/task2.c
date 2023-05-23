// for any string there exists a solution since a single character
// is a palindrome
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

//checks if a string is a palindrome
// assuming end < strlen(word) and checks from string[start] ... staring[end]
bool is_palin(char* word, int start, int end){

    if(start == end){
        return true;
    }
    int k = 0;
    while(start+k < end-k && word[start+k] == word[end-k]){
        k++;
    }

    // if the while loop terminates too early, this means its not a palindrome
    if (start+k < end-k){
        return false;
    }
    else{
        return true;
    }

}
// returns a substring, from s[i]...s[j-1]
char* substr(char* word,int i , int j){
    char* res = malloc(sizeof(char)*(j-1-i));

    for(int l = 0; l < j; ++l){
        res[l] = word[l];
    }

    return res;

}



// Recursive function to find the minimum number of cuts
// the best cuts are those who maximazie the palindromes which are on the edges (left and right) of any word, because
// in best case the word consists of two palindromes, so we check first of the entire word is a palindrome then we check if for n-1 the left and
// right edges of the word are palindromes (n is the length of the entire word)  if we find one we call the function recursively on the non palindrome part of the word
// invariant j< strlen(X) and j is the last index of word X
int findMinCutsRecursive(char* X, int i, int j) {
    if(is_palin(X,i,j)){
        return 0;
    }    
    int k = 1;
    while(i+k <= j && j-k >= i){

        if(is_palin(X,i,j-k)){
            return 1+findMinCutsRecursive(X,j-k+1,j);
        }
        else if (is_palin(X,i+k,j)){
            return 1+findMinCutsRecursive(X,i,i+k-1);
        }
        k++;

    }
    // this should never be triggered, since any character is a palindrome
    return 0;
}

// is basically an iterative version of the recursive solution
int findMinCutsDP(char* X, int i, int j){
    if(is_palin(X,i,j)){
        return 0;
    }

    int k = 1;
    int cuts = 0;

    while(i+k <= j && j-k >= i){
        if(is_palin(X,i,j-k)){
            cuts++;
            i = j-k+1;
            

        }
        else if(is_palin(X,i+k,j)){
            cuts++;
            j = i+k-1;
            
        }
        k++;
    }
    return cuts;
}

int main(){

    //testing is palindrome
    printf("%s", "test 1: #####\n");
    char* word = "boo";
    bool expected = false;
    bool result = is_palin(word,0,strlen(word)-1);

    printf("%s","expected: "); printf("%d",expected); printf("%s","\n");
    printf("%s", "result: "); printf("%d",result); printf("%s","\n");

    
    if(result == expected){
        printf("\033[32m SUCCESS \033[0m\n");
    }
    else{
        printf("\033[31m FAIL \033[0m\n");
    }

    printf("%s", "test 2: #####\n");

    word = "abaaba";
    expected = true;
    result = is_palin(word,0,strlen(word)-1);

    printf("%s","expected: "); printf("%d",expected); printf("%s","\n");
    printf("%s", "result: "); printf("%d",result); printf("%s","\n");

    
    if(result == expected){
        printf("\033[32m SUCCESS \033[0m\n");
    }
    else{
        printf("\033[31m FAIL \033[0m\n");
    }

    // testing substring function
    printf("%s", "substring test 1: #####\n");

    word = "abaaba";
    char* expected2 = "aba";
    char* result2 = substr(word,0,3);

    printf("%s","expected: "); printf("%s",expected2); printf("%s","\n");
    printf("%s", "result: "); printf("%s",result2); printf("%s","\n");

    
    if(result == expected){
        printf("\033[32m SUCCESS \033[0m\n");
    }
    else{
        printf("\033[31m FAIL \033[0m\n");
    }

    printf("\n Recursive palindrome algo tests @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
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

    printf("\n DP palindrome algo tests @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");

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