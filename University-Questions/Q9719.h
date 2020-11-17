#ifndef QUERA_Q9719_H
#define QUERA_Q9719_H

#endif //QUERA_Q9719_H

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

/**
 * Converts a number from base 10 to a number to another base
 * @param number The input number
 * @param to_base Target base
 * @return String of the number
 */
char *base_convert(long number, int to_base) {
    char letters[] = "0123456789ABCDEFGHIJK";
    char result[64];
    memset(result, 0, sizeof(result));
    int counter = 0;
    while (number >= to_base) {
        result[counter] = letters[number % to_base];
        number /= to_base;
        counter++;
    }
    result[counter] = letters[number]; // the last digit
    // the string must be reversed
    unsigned long len = strlen(result);
    char *result_reversed = calloc(len + 1, sizeof(char)); // create a string to reverse the result
    for (counter = 0; counter < len; counter++)
        result_reversed[counter] = result[len - 1 - counter];
    return result_reversed;
}

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 1; i < 300; i++) {
        char *converted = base_convert(i * i, n);
        bool mirror = true;
        unsigned long len = strlen(converted);
        for (int counter = 0; counter < len / 2; counter++)
            if (converted[counter] != converted[len - counter - 1]) {
                mirror = false;
                break;
            }

        if (mirror) {
            char *c = base_convert(i, n);
            printf("%s %s\n", c, converted);
            free(c);
        }
        free(converted);
    }
}