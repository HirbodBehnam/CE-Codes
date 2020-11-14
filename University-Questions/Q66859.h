#ifndef QUERA_Q66859_H
#define QUERA_Q66859_H

#endif //QUERA_Q66859_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/**
 * Converts a number from base 10 to a number to another base
 * @param number The input number
 * @param to_base Target base
 * @return String of the number
 */
char *base_convert(long number, int to_base) {
    char letters[] = "0123456789ABCDEF";
    char result[64]; // the result is not bigger than 64 bytes
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
    char *result_reversed = malloc((len + 1) * sizeof(char)); // create a string to reverse the result
    result_reversed[len] = '\0'; // null terminator must be the last char
    for (counter = 0; counter < len; counter++)
        result_reversed[counter] = result[len - 1 - counter];
    return result_reversed;
}

int main() {
    long number;
    int base;
    scanf("%ld %d", &number, &base);
    printf("%s", base_convert(number, base));
    return 0;
}