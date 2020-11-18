#ifndef QUERA_Q604_H
#define QUERA_Q604_H

#endif //QUERA_Q604_H

#include <stdio.h>

/**
 * https://en.wikipedia.org/wiki/Josephus_problem#The_general_case
 * @param n The number of people
 * @param k Number of shifts
 * @return The safe place
 */
int josephus(int n, int k) {
    if (n == 1)
        return 1;
    return (josephus(n - 1, k) + k - 1) % n + 1;
}

int main() {
    int n;
    scanf("%d", &n);
    printf("%d", josephus(n, 2));
    return 0;
}