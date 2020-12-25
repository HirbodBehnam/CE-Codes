#ifndef QUERA_Q1_H
#define QUERA_Q1_H

#endif //QUERA_Q1_H

#include <stdio.h>

/**
 * Recursively decomposes a number and writes prime factors into stdout
 * The algorithm is this:
 * If the number is 1, then we cannot decompose it into prime numbers so terminate the recursion
 * If not, check if 'number' can be decided by 'i';
 * If so, print 'i' (because i is one of the factors of number) and then divide 'number' to 'i' until it doesn't have the factor of 'i' in it anymore
 * Then whatever the case is, recursively call itself with (i+1)
 * So what's up with dividing? To completely eliminate the prime number and reducing the number to one
 * For example think of 60 = 2^2 * 3 * 5
 * Without dividing more than once, we will eventually fill the stack because we cannot get rid of the first '2' in number
 * @param i Current index to check the number
 * @param number The number to get the prime factors of it
 */
void decompose(unsigned long long i, unsigned long long number) {
    if (number == 1)
        return;
    if (number % i == 0) {
        printf("%llu ", i);
        while (number % i == 0) // completely remove the prime factor from number
            number /= i;
    }
    decompose(i + 1, number);
}

int main() {
    unsigned long long n;
    scanf("%llu", &n);
    decompose(2, n); // we start from 2 the fist prime number
    return 0;
}