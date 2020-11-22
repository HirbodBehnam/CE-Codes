#ifndef QUERA_Q296_H
#define QUERA_Q296_H

#endif //QUERA_Q296_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main() {
    int n;
    scanf("%d", &n);
    char result[n][n];
    memset(result, ' ', sizeof(result)); // fill the array with whitespace
    // fill the outlines and diameter
    for (int i = 0; i < n; i++) {
        result[i][0] = '#'; // right column
        result[i][n - 1] = '#'; // left column
        result[0][i] = '#'; // top row
        result[n - 1][i] = '#'; // bottom row
        result[i][i] = '#'; // first diameter
        result[n - i - 1][i] = '#'; // second diameter
    }
    // fill the right side of it
    for (int i = 0; i <= n / 2; i++) {
        for (int j = 0; j < i; j++) {
            result[i][n - j - 1] = '#'; // this fills it from top
            result[n - i - 1][n - j - 1] = '#'; // this fills it from bottom
        }
    }
    // print the result
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            putchar(result[i][j]);
        }
        putchar('\n');
    }
    return 0;
}