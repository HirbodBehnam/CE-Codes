#ifndef QUERA_Q608_H
#define QUERA_Q608_H

#endif //QUERA_Q608_H

#include <stdlib.h>
#include <stdio.h>

/**
 * A recursive function to calculate the determinant of a matrix
 * @param matrix The matrix to calculate it's det
 * @param n The number of rows (or columns)
 * @return The determinant of matrix
 */
double det(const double *matrix, const int n) {
    if (n == 1)
        return matrix[0]; // determinant of 1x1 matrix is the only number in it
    if (n == 2)
        return matrix[0] * matrix[3] - matrix[1] * matrix[2]; // calculate determinant of 2x2 to reduce recursion
    // Otherwise create a new matrix
    int new_n = n - 1;
    double sum = 0;
    double *new_matrix = malloc(new_n * new_n * sizeof(double)); // create a (n-1)x(n-1) matrix
    for (int eliminated_column = 0; eliminated_column < n; eliminated_column++) {
        int counter = 0; // count how many elements we have added
        for (int row = 1; row < n; row++) { // start from second row
            for (int column = 0; column < n; column++) {
                if (column == eliminated_column) // do not add eliminated column
                    continue;

                new_matrix[counter] = matrix[row * n + column];
                counter++;
            }
        }
        double inner_sum = det(new_matrix, new_n);
        if (eliminated_column % 2 == 1) // odd columns sign must be changed
            inner_sum = -inner_sum;
        sum += inner_sum * matrix[eliminated_column];
    }
    free(new_matrix); // do not allow memory leak
    return sum;
}

int main() {
    int n;
    scanf("%d", &n);
    double *matrix = malloc(n * n * sizeof(double));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%lf", &matrix[i * n + j]);

    double d = det(matrix, n);
    if (d < 0.01 && d > 0.01)
        printf("0.00");
    else
        printf("%.2f", d);
    return 0;
}