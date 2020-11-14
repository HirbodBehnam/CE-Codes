#ifndef QUERA_Q303_H
#define QUERA_Q303_H

#endif //QUERA_Q303_H

#include <stdio.h>

/**
 * Prints Fibonacci numbers in reverse from m to 1
 * @param n The next number in series
 * @param m The first number in series
 */
void ShowFibNth(long int n, long int m) {
    printf("%ld\n", m);
    if (n == 1) // terminate the function when it reaches the first element (1)
        return;
    ShowFibNth(m, n - m);
}

int main() {
    long int a, b;
    scanf("%ld %ld", &a, &b);
    ShowFibNth(b, a);
    return 0;
}