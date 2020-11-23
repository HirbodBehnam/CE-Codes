#ifndef QUERA_Q279_H
#define QUERA_Q279_H

#endif //QUERA_Q279_H

#include <stdio.h>

/**
 * Integer power
 * https://stackoverflow.com/a/101613/4213397
 * @param base The base of power
 * @param exp The exponent
 * @return The result
 */
long long ipow(long long base, int exp) {
    long long result = 1;
    for (;;) {
        if (exp & 1)
            result *= base;
        exp >>= 1;
        if (!exp)
            break;
        base *= base;
    }

    return result;
}

int main() {
    int a, y, n;
    scanf("%d %d %d", &a, &y, &n);
    // Just see https://www.gstatic.com/education/formulas/images_long_sheet/en/binomial_theorem.svg
    printf("%llu", ipow(a + y, n));
}