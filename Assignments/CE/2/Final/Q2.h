#ifndef QUERA_Q2_H
#define QUERA_Q2_H

#endif //QUERA_Q2_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * Represents a prime factor
 */
typedef struct f {
    /**
     * The base of power. Always prime
     */
    unsigned long long base;
    /**
     * The power
     */
    unsigned int power;
} factor;

int main() {
    unsigned long long number;
    scanf("%llu", &number);
    // create factors list
    factor *factors = malloc(0); // this list is sorted from small factors to large
    int factors_length = 0; // how much prime factors does this number have
    // get the factors
    unsigned long long counter = 2;
    while (number > 1) {
        if (number % counter == 0) {
            // create factor
            factor f;
            f.base = counter;
            f.power = 0;
            // add to power
            while (number % counter == 0) {
                number /= counter;
                f.power++;
            }
            // add to list
            factors_length++;
            factors = realloc(factors, factors_length * sizeof(factor));
            factors[factors_length - 1] = f;
        }
        counter++;
    }
    // print
    for (int i = factors_length - 1; i >= 0; i--)
        printf("%llu^%u\n", factors[i].base, factors[i].power);
    return 0;
}