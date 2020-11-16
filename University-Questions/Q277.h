#ifndef QUERA_Q277_H
#define QUERA_Q277_H

#endif //QUERA_Q277_H

#include <stdio.h>

/**
 * A recursive algorithm to bruteforce all possible ways that the number can be created
 * It starts from 1, once adds a zero to it, and once adds 1 to end of it.
 * I don't know if passing n as a pointer is a good idea to reduce the stack size or not
 * @param number The number to check
 * @param n The number that "number" must be less than it
 */
int check(unsigned long long number, const unsigned long long *n) {
    if (number > *n) // if the number is bigger than n, then return 0 (no possible ways)
        return 0;
    // check if number{0} is smaller than n | check if number{1} is smaller than a | we already know that number is smaller than a, so add one to possible ways
    return check(number * 10, n) + check(number * 10 + 1, n) + 1;
}

int main() {
    unsigned long long n;
    scanf("%llu", &n);
    printf("%d", check(1, &n));
    return 0;
}