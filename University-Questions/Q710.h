#ifndef QUERA_Q710_H
#define QUERA_Q710_H

#endif //QUERA_Q710_H

#define MAX_INPUT 5000

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

/**
 * Checks if a character is alphabet
 * @param c Character to check
 * @return True if char is alphabet
 */
bool is_alphabet(char c) {
    return c >= 'A' && c <= 'Z';
}

int main() {
    // create the stack and result
    char *output = malloc(MAX_INPUT * sizeof(char)), *stack = malloc(MAX_INPUT * sizeof(char));
    int output_length = 0, stack_size = 0;
    // read the input char by char
    char input;
    while ((input = getchar()) != EOF) {
        if (is_alphabet(input)) { // just add the char to input
            output[output_length] = input;
            output_length++;
        } else {
            switch (input) {
                case '(':
                    stack[stack_size] = '(';
                    stack_size++;
                    break;
                case ')':
                    // pop the stack until we see (; Thanks to these parenthesis questions
                    while(stack[stack_size - 1] != '('){
                        output[output_length] = stack[stack_size - 1];
                        stack_size--;
                        output_length++;
                    }
                    // remove the (
                    stack_size--;
                    break;
                case '*':
                case '/':
                    if(stack[stack_size - 1] == '*' || stack[stack_size - 1] == '/'){
                        output[output_length] = stack[stack_size - 1];
                        output_length++;
                        stack[stack_size - 1] = input; // do not change the stack size
                    }else{
                        // add it to stack
                        stack[stack_size] = input;
                        stack_size++;
                    }
                    break;
                case '+':
                case '-':
                    if(stack[stack_size - 1] == '*' || stack[stack_size - 1] == '/'){
                        output[output_length] = stack[stack_size - 1];
                        output_length++;
                        stack_size--;
                    }
                    if(stack[stack_size - 1] == '+' || stack[stack_size - 1] == '-'){
                        output[output_length] = stack[stack_size - 1];
                        output_length++;
                        stack_size--;
                    }
                    stack[stack_size] = input;
                    stack_size++;
                    break;
            }
        }
    }
    while (stack_size > 0) {
        output[output_length] = stack[stack_size - 1];
        stack_size--;
        output_length++;
    }
    output[output_length] = '\0'; // null terminator
    // print the result
    printf("%s", output);
    return 0;
}