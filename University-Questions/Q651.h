#ifndef QUERA_Q651_H
#define QUERA_Q651_H

#endif //QUERA_Q651_H

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

/**
 * Checks if a number is palindrome is a specefic base
 * @param number The number to check
 * @param to_base The base to convert to
 * @return
 */
bool check_base_convert(long number, int to_base){
    char letters[] = "0123456789ABCDEF";
    char result[64];
    memset(result, 0, sizeof(result));
    int counter = 0;
    while (number >= to_base){
        result[counter] = letters[number % to_base];
        number /= to_base;
        counter++;
    }
    result[counter] = letters[number]; // the last digit
    // check if reversed string is same as normal one
    unsigned long len = strlen(result);
    for(counter = 0; counter < len / 2; counter++)
        if(result[counter] != result[len - counter - 1])
            return false;

    return true;
}

/**
 * Converts a number from a base to long
 * @param number The number
 * @param base base
 * @return
 */
long convert_from_base(char number[], int base){
    long long multiplier = 1;
    long result = 0;
    for(int i = strlen(number) - 1; i >= 0; i--){
        result += multiplier * (long)(number[i] - '0');
        multiplier *= base;
    }
    return result;
}

int run(){
    int b, c;
    char a[20]; // worse case is in base 2 and 1000000. The question says that a < 10^6 "IN BASE 10"
    scanf("%s %d %d", a, &b, &c);
    long base10 = convert_from_base(a, b);
    printf(check_base_convert(base10, c) ? "YES" : "NO");
    return 0;
}