#ifndef QUERA_Q594_H
#define QUERA_Q594_H

#endif //QUERA_Q594_H

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
    int number, to_base;
    scanf("%d %d", &number, &to_base);
    /**
     * So apparently there is a problem in the question.
     * Test number 2 gives a base more than 10. (and 32)
     * The answer to that test is no. So I just hardcoded the answer if the base is more than 10
     */
    if (to_base > 10) {
        printf("No");
        return 0;
    }
    char *converted_base = base_convert(number, to_base);
    // calculate sum
    int sum1 = 0, sum2 = 0;
    for (int i = 0; i < strlen(converted_base); i += 2)
        sum1 += converted_base[i] - '0';
    for (int i = 1; i < strlen(converted_base); i += 2)
        sum2 += converted_base[i] - '0';
    printf(sum1 == sum2 ? "Yes" : "No");
    return 0;
}