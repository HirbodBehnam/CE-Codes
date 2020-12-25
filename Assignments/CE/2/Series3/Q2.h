#ifndef QUERA_Q2_H
#define QUERA_Q2_H

#endif //QUERA_Q2_H

#include <stdio.h>

/**
 * Use euclidean algorithm to calculate the GCD of two numbers
 * https://en.wikipedia.org/wiki/Euclidean_algorithm
 * @param a First number
 * @param b Second number
 * @return The gcd of both numbers
 */
unsigned long long gcd(unsigned long long a, unsigned long long b) {
    return b == 0 ? a : gcd(b, a % b);
}

int main() {
    unsigned long long a, b, g, lcm;
    scanf("%llu %llu", &a, &b);
    g = gcd(a, b); // calculate gcd
    lcm = a * b / g; // calculate lcm
    printf("%llu %llu", lcm, g);
    return 0;
}