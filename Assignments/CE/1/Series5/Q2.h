#ifndef QUERA_Q2_H
#define QUERA_Q2_H

#endif //QUERA_Q2_H

#include <stdbool.h>
#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    int matrix[n][n];
    // read the matrix
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &matrix[i][j]);

    // start going through it
    int i = 0, j = 0;
    bool going_down = false;
    while (i != n - 1 || j != n - 1) { // left side
        printf("%d ", matrix[i][j]);
        /**
         * What is this if?
         * If the dimensions are odd, we eventually reach top right row then we have to go one tile down and start going down
         * Without this if, the first if block will run and it will increase the j by one; But we have to increase i by one and go down
         */
        if (n % 2 == 1 && i == 0 && j == n - 1) {
            i++;
            going_down = true;
            continue;
        }
        if ((i == 0 && !going_down) || (i == n - 1 && going_down)) {
            j++;
            going_down = !going_down;
        } else if ((j == 0 && going_down) || (j == n - 1 && !going_down)) {
            i++;
            going_down = !going_down;
        } else {
            if (going_down) {
                i++;
                j--;
            } else {
                i--;
                j++;
            }
        }
    }
    printf("%d", matrix[i][j]);
    return 0;
}