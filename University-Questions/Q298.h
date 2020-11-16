#ifndef QUERA_8_H
#define QUERA_8_H

#endif //QUERA_8_H

#include <stdbool.h>
#include <stdio.h>

/**
 * When printing first factor we must not add * to the beginning of output
 */
bool first_factor = true;

/**
 * If power is not 0, prints a string in format of [*]base[^power]
 * If power is 1, the power part will not be printed ([*]base)
 * If first_factor is true, the * will not be printed (base[^power])
 * @param base The prime factor
 * @param power Power of the factor
 */
void print_factor(unsigned long long base, int power) {
    if (power == 0)
        return;
    // print * if this is not first factor
    if (!first_factor)
        printf("*");
    // print the factor
    if (power != 1)
        printf("%llu^%d", base, power);
    else
        printf("%llu", base);
    first_factor = false;
}

/**
 * Gets number an to_divide as input and divides the number to to_divide until number is not divisible anymore to to_divide
 * Also because the number is passed as pointer, the number will be updated.
 * At last, calls print_factor to print the factors
 * @param number
 * @param to_divide
 */
void divide(unsigned long long *number, unsigned long long to_divide){
    int counter = 0;
    while ((*number) % to_divide == 0){
        *number /= to_divide;
        counter++;
    }
    print_factor(to_divide, counter);
}

int main(){
    unsigned long long n;
    scanf("%llu", &n);
    // eliminate 2 factors
    divide(&n, 2);
    // eliminate 3 factors
    divide(&n, 3);
    // other factors
    unsigned long long to_check = 5;
    while(n != 1){
        divide(&n, to_check);
        to_check+=2;
        divide(&n, to_check);
        to_check+=4;
    }
    return 0;
}