#ifndef QUERA_Q1_H
#define QUERA_Q1_H

#endif //QUERA_Q1_H

// 101 chars to include the null terminator
#define MAX_INPUT 101

#define NO 0
#define YES 1

#include <ctype.h>
#include <stdio.h>

int main() {
    char input[MAX_INPUT];
    /**
     * What is this?
     * If this variable is YES it means that next char that we are going to print must be uppercase
     * otherwise next char must be lowercase
     * The initial value of this variable must be YES in order to print the first char of input in uppercase
     * When we reach a space we make this variable YES and when we reach a char we make this value NO
     */
    char reading_white_space = YES;
    gets(input);
    int index = 0;
    while (input[index] != '\0') { // read all of text
        if (input[index] == ' ') { // do not print the space
            reading_white_space = YES;
        } else {
            if (reading_white_space)
                putchar(toupper(input[index]));
            else
                putchar(tolower(input[index]));
            reading_white_space = NO;
        }
        index++;
    }
    return 0;
}