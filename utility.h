#ifndef QUERA_UTILITY_H
#define QUERA_UTILITY_H

#endif //QUERA_UTILITY_H

#include <math.h>
#include <stdlib.h>
#include <string.h>

/**
 * Converts a number from base 10 to a number to another base
 * @param number The input number
 * @param to_base Target base
 * @return String of the number
 */
char* base_convert(long number, int to_base){
    char letters[] = "0123456789ABCDEF";
    char *result = malloc(64 * sizeof(char)); // the result is not bigger than 64 bytes
    int counter = 0;
    while (number >= to_base){
        result[counter] = letters[number % to_base];
        number /= to_base;
        counter++;
    }
    result[counter] = letters[number]; // the last digit
    // the string must be reversed
    unsigned long len = strlen(result);
    char *result_reversed = malloc((len + 1) * sizeof(char)); // create a string to reverse the result
    result_reversed[len] = '\0'; // null terminator must be the last char
    for(counter = 0; counter < len; counter++) {
        result_reversed[counter] = result[len - 1 - counter];
    }
    free(result); // now this is not needed
    return result_reversed;
}

/**
 * Returns 0 if the number is prime. Returns it's first factor if not
 * @param number The number to check
 * @return 0 if the number is prime otherwise it's first factor
 */
unsigned long long is_prime(unsigned long long x){
    if (x == 1)
        return 1;
    if (x == 2 || x == 3 || x == 5 || x == 7)
        return 0;
    if (x % 2 == 0)
        return 2;
    if (x % 3 == 0)
        return 3;
    const unsigned long long To = (unsigned long long) sqrt((double)x);
    for (unsigned long long i = 5; i <= To; i+=4)
    {
        if (x % i == 0)
            return i;
        i += 2;
        if (x % i == 0)
            return i;
    }
    return 0;
}

/**
 * Converts a number from a base to long
 * @param number The number
 * @param base base
 * @return
 */
long long convert_from_base(const char number[], int base){
    long long multiplier = 1;
    long long result = 0;
    for(int i = strlen(number) - 1; i >= 0; i--){
        result += multiplier * (number[i] - '0');
        multiplier *= base;
    }
    return result;
}