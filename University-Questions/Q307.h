#ifndef QUERA_Q307_H
#define QUERA_Q307_H

#endif //QUERA_Q307_H

#define MAX_INPUT 1000000 // just a huge number to never run out of buffer

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/**
 * Reverses a string
 * @param input The string to reverse
 * @param len Length of string
 */
void reverse(char *input, int len){
    int start = 0, last = len - 1;
    while (start < last){
        char temp = input[start];
        input[start] = input[last];
        input[last] = temp;
        start++;
        last--;
    }
}

/**
 * Shifts a string to right
 * @param input Input to shift
 * @param len Length of input
 * @param n Number of shifts
 */
void shift_right(char *input, int len, int n){
    char* temp = malloc(len * sizeof(char ));
    for(int i = 0; i < len; i++)
    {
        int index = (i - n) % len;
        if(index < 0) // fix negative values
            index += len;
        temp[i] = input[index];
    }
    memcpy(input, temp, len);
    free(temp);
}

/**
 * Shifts a string to left
 * @param input Input to shift
 * @param len Length of input
 * @param n Number of shifts
 */
void shift_left(char *input, int len, int n){
    char* temp = malloc(len * sizeof(char ));
    for(int i = 0; i < len; i++)
    {
        int index = (i + n) % len;
        if(index < 0) // fix negative values
            index += len;
        temp[i] = input[index];
    }
    memcpy(input, temp, len);
    free(temp);
}

int main(){
    char *string = malloc(MAX_INPUT * sizeof(char));
    int str_len;
    {
        // read a temp value
        char *init_string = NULL;
        size_t max = MAX_INPUT;
        str_len = getline(&init_string, &max, stdin);
        strcpy(string, init_string);
        free(init_string);
        // remove newline
        str_len--;
        string[str_len] = 0;
    }
    while (1){
        char command[10];
        scanf("%s", command); // read the command
        if(strcmp(command, "SHIFT-R") == 0){
            int n;
            scanf("%d", &n);
            shift_right(string, str_len, n);
        }else if(strcmp(command, "SHIFT-L") == 0){
            int n;
            scanf("%d", &n);
            shift_left(string, str_len, n);
        }else if(strcmp(command, "EXTEND") == 0){
            int n;
            scanf("%d", &n);
            while (n > 0){
                string[str_len] = '*';
                str_len++;
                n--;
            }
            string[str_len] = 0;
        }else if(strcmp(command, "SHRINK") == 0){
            int n;
            scanf("%d", &n);
            if(n > str_len){ // empty the string
                str_len = 0;
                string[0] = 0;
            }else{
                str_len -= n;
                string[str_len] = 0; // just put null terminator
            }
        }else if(strcmp(command, "REVERSE") == 0){
            reverse(string, str_len);
        }else if(strcmp(command, "PUT") == 0){
            int i;
            char c;
            scanf("%d %c", &i, &c);
            string[i - 1] = c;
        }else if(strcmp(command, "PRINT") == 0){
            printf("%s\n", string);
        }else if(strcmp(command, "EXIT") == 0){
            return 0;
        }
    }
}