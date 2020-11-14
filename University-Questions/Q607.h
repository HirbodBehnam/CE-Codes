#ifndef QUERA_Q607_H
#define QUERA_Q607_H

#endif //QUERA_Q607_H

#include <stdio.h>
#include <string.h>

int main() {
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c); // read dimensions
    int matrixA[a][b], matrixB[b][c];
    // read matrix A
    for (int i = 0; i < a; i++)
        for (int j = 0; j < b; j++)
            scanf("%d", &matrixA[i][j]);

    // read matrix B
    for (int i = 0; i < b; i++)
        for (int j = 0; j < c; j++)
            scanf("%d", &matrixB[i][j]);

    // multiply them and print at the same time
    for (int x1 = 0; x1 < a; x1++) {
        for (int x2 = 0; x2 < c; x2++) {
            unsigned long long index = 0;
            for (int i = 0; i < b; i++)
                index += matrixA[x1][i] * matrixB[i][x2];
            printf("%llu ", index); // print row
        }
        printf("\n"); // go to next column
    }
    return 0;
}