#ifndef QUERA_Q66860_H
#define QUERA_Q66860_H

#endif //QUERA_Q66860_H

#define MAX_POWER 64

#include <stdlib.h>
#include <stdio.h>

/**
 * Code heavily inspired by https://www.geeksforgeeks.org/minimum-tiles-of-sizes-in-powers-of-two-to-cover-whole-area/
 */

/**
 * Finds the minimum tiles needed to fill the area
 * @param tiles An array to store tiles needed to fill the area
 * @param n Width of area
 * @param m Height of area
 * @param depth The depth of recursion
 */
void minTiles(unsigned long long *tiles, unsigned long long n, unsigned long long m, int depth) {
    if (n == 0 || m == 0)
        return;

    if (n % 2 == 0 && m % 2 == 1)
        tiles[depth] = n;
    else if (n % 2 == 1 && m % 2 == 0)
        tiles[depth] = m;
    else if (n % 2 == 1 && m % 2 == 1)
        tiles[depth] = n + m - 1;

    minTiles(tiles, n / 2, m / 2, depth + 1);
}

int main() {
    unsigned long long n, m;
    unsigned long long *tiles = calloc(MAX_POWER + 1, sizeof(unsigned long long));
    scanf("%lld %lld", &n, &m);
    minTiles(tiles, n, m, 0);
    for (unsigned long long i = MAX_POWER;; i--) {
        if (tiles[i] != 0)
            printf("%llu %llu*%llu tiles\n", tiles[i], 1ULL << i, 1ULL << i);
        if (i == 0)
            break;
    }
    return 0;
}