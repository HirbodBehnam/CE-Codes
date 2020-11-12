#ifndef QUERA_Q649_H
#define QUERA_Q649_H

#endif //QUERA_Q649_H

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

int run(){
    int a, b;
    char* result = malloc(sizeof(char) * 1000); // 1000 chars is probably ok
    memset(result, 0, sizeof(char) * 1000);
    scanf("%d", &a);
    scanf("%d", &b);
    a++; // do not check a
    for(; a < b; a++){
        if(is_prime(a) == 0){
            char number[4]; // 3 digits and null terminator
            sprintf(number, "%d", a);
            strcat(result, number);
            strcat(result, ",");
        }
    }

    if(strlen(result) != 0) // if string is not empty
        result[strlen(result) - 1] = '\0'; // remove last ,
    printf("%s", result);
}