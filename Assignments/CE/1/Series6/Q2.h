#ifndef QUERA_Q2_H
#define QUERA_Q2_H

#endif //QUERA_Q2_H

#define MAX_LENGTH 3323 // ceiling of log2(10^1000) + 1

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

/**
 * Reverses an array
 * @param ary The array to reverse
 * @param n The number of elements in array
 */
void reverse_array(char *ary, int n) {
    int begin = 0;
    int end = n - 1;
    while (begin < end) {
        char temp = *(ary + begin);
        *(ary + begin) = *(ary + end);
        *(ary + end) = temp;
        end--;
        begin++;
    }
}

int main() {
    // read the base
    int base_number;
    scanf("%d\n", &base_number);
    char c;
    // read first number
    char *number1 = malloc(MAX_LENGTH * sizeof(char));
    int number1_length = 0;
    while (isdigit(c = getchar())) {
        *(number1 + number1_length) = (char) (c - '0');
        number1_length++;
    }
    // read second number
    char *number2 = malloc(MAX_LENGTH * sizeof(char));
    int number2_length = 0;
    while (isdigit(c = getchar())) {
        *(number2 + number2_length) = (char) (c - '0');
        number2_length++;
    }
    // reverse numbers
    reverse_array(number1, number1_length);
    reverse_array(number2, number2_length);
    // sum
    char *result = malloc(MAX_LENGTH * sizeof(char));
    int result_length = 0;
    int max = number1_length > number2_length ? number1_length : number2_length;
    bool carry = false;
    for (; result_length < max; result_length++) {
        char this_char;
        // add first number
        if (result_length >= number1_length)
            this_char = 0;
        else
            this_char = *(number1 + result_length);
        // add second number if needed
        if (result_length < number2_length)
            this_char += *(number2 + result_length);
        // add carry if needed
        if (carry)
            this_char++;
        // check if we need carry again
        if (this_char >= base_number) {
            carry = true;
            this_char -= base_number;
        } else {
            carry = false;
        }
        *(result + result_length) = this_char + '0';
    }
    // check carry
    if (carry) {
        *(result + result_length) = '1';
        result_length++;
    }
    *(result + result_length) = '\0';
    // reverse again
    reverse_array(result, result_length);
    printf("%s", result);
    return 0;
}