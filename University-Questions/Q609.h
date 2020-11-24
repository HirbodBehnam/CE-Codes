#ifndef QUERA_Q609_H
#define QUERA_Q609_H

#endif //QUERA_Q609_H

enum movement{left, down, right, up};

/**
 * After adding an element to sum, we assign this value to it to mark it as visited
 * This helps to "shrink" the matrix to know when to turn
 * We also "probably" know that none of the elements are -1. So we can happily assign -1 to visited indexes
 */
#define VISITED -1

#include <stdio.h>

/**
 * Checks if x is a perfect square root with binary search
 * @param x The number to check
 * @return The sqrt of x if x is perfect square. Otherwise 0
 */
unsigned long long perfect_sqrt(unsigned long long x) {
    unsigned long long low = 0, high = x;
    // prevent integer overflow on pow2
    if (high > 18446744065119617025LLU)
        return 4294967296LLU;
    if (high > 4294967296LLU * 2 - 1)
        high = 4294967296LLU * 2 - 1;
    // use binary search
    while (low <= high) {
        const unsigned long long mid = (low + high) / 2;
        const unsigned long long pow2 = mid * mid;
        if (pow2 == x)
            return mid;

        if (pow2 < x) // target must be higher
            low = mid + 1;
        else // target must be lower
            high = mid - 1;
    }
    return 0; // not prefect square root
}

int main() {
    int n;
    scanf("%d", &n);
    int matrix[n][n];
    unsigned long long sum = 0;
    int points = 0;
    // read the matrix
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &matrix[i][j]);

    int counter = 0, i = 0, j = 0;
    // in status we declare with direction we are moving
    enum movement status = left;
    while (counter != n * n) {
        sum += matrix[i][j];
        if (sum == 0 || perfect_sqrt(sum) != 0) // add one to points if the sum is 0 (because perfect_sqrt returns zero when the number is not perfect square) or the number is not perfect square
            points++;
        matrix[i][j] = VISITED; // mark the tile as visited
        switch (status) {
            case left:
                // reached the edge or reached a visited tile
                if ((j + 1) == n || matrix[i][j + 1] == VISITED) {
                    status = down; // status++;
                    i++; // move to downer tile
                } else { // otherwise just move one left
                    j++;
                }
                break;
            case down:
                if ((i + 1) == n || matrix[i + 1][j] == VISITED) {
                    status = right; // status++;
                    j--; // move to right tile
                } else { // otherwise just move one down
                    i++;
                }
                break;
            case right:
                if (j == 0 || matrix[i][j - 1] == VISITED) {
                    status = up; // status++;
                    i--; // move to upper tile
                } else { // otherwise just move one right
                    j--;
                }
                break;
            case up:
                if (i == 0 || matrix[i - 1][j] == VISITED) {
                    status = left; // status = 0;
                    j++; // move to left tile
                } else { // otherwise just move one up
                    i--;
                }
                break;
        }
        counter++;
    }
    printf("%d", points);
    return 0;
}