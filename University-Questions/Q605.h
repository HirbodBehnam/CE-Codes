#ifndef QUERA_Q605_H
#define QUERA_Q605_H

#endif //QUERA_Q605_H

#include <stdio.h>

/**
 * Finds the ways that a 2 * n pane can be filled with dominoes
 * @param n Number of columns, must be non-negative
 * @return The number of ways that this pane can be filled
 */
int kashi(int n) {
    // If the pane is 2 * 1 or 2 * 0 we have already filled a valid pane!
    if (n == 0 || n == 1)
        return 1;
    /*
     * We can either use
     * 1. One vertical domino to fill a 2 * 1 area
     * 2. Use two horizontal dominoes to fill a 2 * 2 square
     * If we choose 1, we will progress by one in the pane; If we choose number 2 we will progress 2 columns in pane
     * Note that because we have a check for n == 0 or n == 1, this return statement will never pass a negative value to itself
     */
    return kashi(n - 1) + kashi(n - 2);
}

int main() {
    int n;
    scanf("%d", &n);
    printf("%d", kashi(n));
    return 0;
}