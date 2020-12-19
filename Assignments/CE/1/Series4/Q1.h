#ifndef QUERA_Q1_H
#define QUERA_Q1_H

#endif //QUERA_Q1_H

#include <stdio.h>

/**
 * For n < 500
 * @param n
 * @return
 */
unsigned long long T1(unsigned long long n) {
    if (n == 0)
        return 0;
    if (n == 1)
        return 1;
    return T1(n / 2) + T1(n / 3) + n * n;
}

/**
 * For n >= 500
 * @param n
 * @return
 */
unsigned long long T2(unsigned long long n) {
    if (n == 0)
        return 0;
    if (n == 1)
        return 1;
    return T2(n / 3) + T2(n / 2) + 2 * n * n;
}

int main() {
    unsigned long long n;
    scanf("%llu", &n);
    printf("%llu", n >= 500 ? T2(n) : T1(n));
    return 0;
}