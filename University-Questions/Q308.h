#ifndef QUERA_Q308_H
#define QUERA_Q308_H

#endif //QUERA_Q308_H

#define MAX_INPUT 100000

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * Checks if this char is valid to be checked in {@see is_palindrome} function
 * Valid chars are lowercase characters and numbers
 * @param c The char to check
 * @return True if the char is valid, otherwise false
 */
bool valid_char(char c){
    return (c >= 'a' && c <= 'z') || (c >= '0' && c <= '9');
}

/**
 * Returns a fixed char array. This char array can be checked with any palindrome checking algorithm
 * @param input The input to fix
 * @return Removes invalid chars from string
 */
char* fix_input(char* input){
    int index = 0, input_len = strlen(input);
    char* fixed = malloc(input_len * sizeof(char));
    for(int i = 0; i < input_len; i++){
        char c = tolower(input[i]);
        if(valid_char(c)){
            fixed[index] = c;
            index++;
        }
    }
    fixed[index] = '\0'; // null terminator
    return fixed;
}

/**
 * Checks if the string is palindrome or not
 * @param to_check The string to check
 * @return
 */
bool is_palindrome(char* to_check){
    int begin = 0, end = strlen(to_check) - 1;
    while (begin < end){
        if(to_check[begin] != to_check[end])
            return false;
        begin++;
        end--;
    }
    return true;
}

int main(){
    // read the input
    char* raw_input = NULL;
    size_t m = MAX_INPUT;
    getline(&raw_input, &m, stdin);
    // fix the input
    char* fixed_input = fix_input(raw_input);
    free(raw_input);
    // check palindrome
    printf("%s", is_palindrome(fixed_input) ? "YES" : "NO");
    return 0;
}