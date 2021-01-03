#ifndef QUERA_Q9722_H
#define QUERA_Q9722_H

#endif //QUERA_Q9722_H

#include <math.h>
#include <stdlib.h>
#include <stdio.h>

/**
 * Returns 0 if the number is prime. Returns it's first factor if not
 * @param number The number to check
 * @return 0 if the number is prime otherwise it's first factor
 */
unsigned long long is_prime(unsigned long long x) {
    if (x == 1)
        return 1;
    if (x == 2 || x == 3 || x == 5 || x == 7)
        return 0;
    if (x % 2 == 0)
        return 2;
    if (x % 3 == 0)
        return 3;
    const unsigned long long To = (unsigned long long) sqrt((double) x);
    for (unsigned long long i = 5; i <= To; i += 4) {
        if (x % i == 0)
            return i;
        i += 2;
        if (x % i == 0)
            return i;
    }
    return 0;
}

/**
 * Backtrack right truncatable numbers
 * @param number The number to check
 * @param n Number of digits left
 */
void backtrack_numbers(unsigned long long number, int n) {
    // end the recursion
    if (n == 0) {
        printf("%llu\n", number);
        return;
    }
    n--;
    number *= 10;
    if (is_prime(number + 1) == 0)
        backtrack_numbers(number + 1, n);
    if (is_prime(number + 3) == 0)
        backtrack_numbers(number + 3, n);
    if (is_prime(number + 7) == 0)
        backtrack_numbers(number + 7, n);
    if (is_prime(number + 9) == 0)
        backtrack_numbers(number + 9, n);
}

int main() {
    int n;
    scanf("%d", &n);
    n--;
    backtrack_numbers(2, n);
    backtrack_numbers(3, n);
    backtrack_numbers(5, n);
    backtrack_numbers(7, n);
    return 0;
}