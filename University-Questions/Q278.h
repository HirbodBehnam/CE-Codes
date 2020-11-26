#ifndef QUERA_Q278_H
#define QUERA_Q278_H

#endif //QUERA_Q278_H

#include <stdio.h>

/**
 * I didn't write this. My friend told me the algorithm from https://algorithmist.com/wiki/UVa_10918_-_Tri_Tiling
 */

int g(int n);

int f(int n) {
    if (n == 0)
        return 1;
    if (n == 1)
        return 0;
    return f(n - 2) + 2 * g(n - 1);
}

int g(int n) {
    if (n < 2)
        return n;
    return f(n - 1) + g(n - 2);
}

int main() {
    int n;
    scanf("%d", &n);
    if (n % 2 == 1)
        printf("0");
    else
        printf("%d", f(n) * 2);
    return 0;
}