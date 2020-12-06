#ifndef QUERA_Q9722_H
#define QUERA_Q9722_H

#endif //QUERA_Q9722_H

#define PRIME 0
#define NOT_PRIME 1

#include <math.h>
#include <stdlib.h>
#include <stdio.h>

/**
 * Checks if a number is right truncatable
 * @param candidates Sieve result
 * @param candidate The number to check
 */
void check(const char *candidates, int candidate) {
    int backup = candidate;
    while (candidate != 0) {
        if (candidate == 1)
            return;
        if (candidate == 2 || candidate == 3)
            break;
        if (candidate % 2 == 0 || candidate % 3 == 0)
            return;
        if (candidates[candidate] == NOT_PRIME)
            return;
        candidate /= 10;
    }
    printf("%d\n", backup);
}

int main() {
    int n;
    scanf("%d", &n);
    char *candidates;
    int from = (int) pow(10.0, n - 1);
    // do sieve
    {
        candidates = calloc(sizeof(char), from * 10);
        int length = from * 10 + 1;
        const int To = (int) sqrt((double) length);
        int i;
        for (i = 5;; i += 4) // only check 6k +- 1
        {
            int j;
            if (candidates[i] == 0) {
                // check if eliminating candidates is needed
                if (i <= To) {
                    // eliminate other non-primes
                    j = 2;
                    do {
                        candidates[j * i] = NOT_PRIME;
                        j++;
                    } while (j * i < length);
                } else
                    break;

            }
            i += 2;
            if (candidates[i] == 0) {
                // check if eliminating candidates is needed
                if (i <= To) {
                    // eliminate other non-primes
                    j = 2;
                    do {
                        candidates[j * i] = NOT_PRIME;
                        j++;
                    } while (j * i < length);
                } else
                    break;
            }
        }
    }
    // check numbers
    // numbers which end in 2
    {
        int candidate = from * 2;
        while (candidate % 6 != 5) {
            if (candidates[candidate] == PRIME)
                check(candidates, candidate);
            candidate++;
        }
        for (; candidate < from * 3; candidate += 4) {
            if (candidates[candidate] == PRIME)
                check(candidates, candidate);
            candidate += 2;
            if (candidates[candidate] == PRIME)
                check(candidates, candidate);
        }
    }
    // numbers which end in 3
    {
        int candidate = from * 3;
        while (candidate % 6 != 5) {
            if (candidates[candidate] == PRIME)
                check(candidates, candidate);
            candidate++;
        }
        for (; candidate < from * 4; candidate += 4) {
            if (candidates[candidate] == PRIME)
                check(candidates, candidate);
            candidate += 2;
            if (candidates[candidate] == PRIME)
                check(candidates, candidate);
        }
    }
    // numbers which end in 5
    {
        int candidate = from * 5;
        while (candidate % 6 != 5) {
            if (candidates[candidate] == PRIME)
                check(candidates, candidate);
            candidate++;
        }
        for (; candidate < from * 6; candidate += 4) {
            if (candidates[candidate] == PRIME)
                check(candidates, candidate);
            candidate += 2;
            if (candidates[candidate] == PRIME)
                check(candidates, candidate);
        }
    }
    // numbers which end in 7
    {
        int candidate = from * 7;
        while (candidate % 6 != 5) {
            if (candidates[candidate] == PRIME)
                check(candidates, candidate);
            candidate++;
        }
        for (; candidate < from * 8; candidate += 4) {
            if (candidates[candidate] == PRIME)
                check(candidates, candidate);
            candidate += 2;
            if (candidates[candidate] == PRIME)
                check(candidates, candidate);
        }
    }
    return 0;
}