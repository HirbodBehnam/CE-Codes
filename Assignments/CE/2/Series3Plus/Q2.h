#ifndef QUERA_Q2_H
#define QUERA_Q2_H

#endif //QUERA_Q2_H

#include <stdio.h>

/**
 * Use backtrack (kinda bruteforce) to calculate the all possible ways to calculate order of books
 * This algorithm is really slow but I guess it works...
 * @param before The number that we have chosen before; Next number must be equal or less than this value
 * @param remaining Remaining total books
 * @return
 */
unsigned long long backtrack(long long before, long long remaining) {
    /**
     * We cannot do anything from here because we have used more books than what we had
     * So zero ways to fill from here
     */
    if (remaining < 0)
        return 0;
    /**
     * If either:
     * 1. We last book in groups is one we only have one way to place the remaining books and that's to only all of them in group of single books
     * 2. We have used all of our books! So we have created a group scheme
     */
    if (before == 1 || remaining == 0)
        return 1;
    // otherwise try other possible ways
    unsigned long long sum = 0;
    for (long long i = before; i > 0; i--)
        sum += backtrack(i, remaining - i); // place this number into group and try to complete the group
    return sum;
}

int main() {
    long long n;
    scanf("%lld", &n);
    printf("%llu", backtrack(n, n));
    return 0;
}