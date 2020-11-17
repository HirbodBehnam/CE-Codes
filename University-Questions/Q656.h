#ifndef QUERA_Q656_H
#define QUERA_Q656_H

#endif //QUERA_Q656_H

#include <stdio.h>

double det(const int n) {
    long matrix[n][n];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%ld", &matrix[i][j]);

    double upper[n][n], lower[n][n];
    for (int i = 0; i < n; i++) {
        // Upper Triangular
        for (int k = i; k < n; k++) {
            // Summation of L(i, j) * U(j, k)
            double sum = 0;
            for (int j = 0; j < i; j++)
                sum += (lower[i][j] * upper[j][k]);

            // Evaluating U(i, k)
            upper[i][k] = matrix[i][k] - sum;
        }

        // Lower Triangular
        for (int k = i; k < n; k++) {
            if (i == k)
                lower[i][i] = 1; // Diagonal as 1
            else {
                // Summation of L(k, j) * U(j, i)
                double sum = 0;
                for (int j = 0; j < i; j++)
                    sum += (lower[k][j] * upper[j][i]);

                // Evaluating L(k, i)
                if (upper[i][i] == 0)
                    return 0;
                lower[k][i] = (matrix[k][i] - sum) / upper[i][i];
            }
        }
    }
    double d = 1;
    for (int i = 0; i < n; i++)
        d *= upper[i][i];
    return d;
}

// This algorithm doesn't work fine
int main() {
    int n;
    scanf("%d", &n);
    if ((long) (det(n) * det(n)) % 2 == 0)
        printf("Farzad");
    else
        printf("Danial");
    return 0;
}