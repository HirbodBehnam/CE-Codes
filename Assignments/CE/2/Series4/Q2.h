#ifndef QUERA_Q2_H
#define QUERA_Q2_H

#endif //QUERA_Q2_H

#define DIMENSION 8

#include <stdio.h>

/**
 * Checks if a dimension is valid in chess board
 * @param i
 * @param j
 * @return 1 if good; Otherwise 0
 */
int valid_dimension(int i, int j) {
    return (i >= 0 && i < DIMENSION) && (j >= 0 && j < DIMENSION);
}

/**
 * Checks all
 * @param board
 * @return
 */
int check(const int board[DIMENSION][DIMENSION]) {
    for (int i = 0; i < DIMENSION; i++) {
        for (int j = 0; j < DIMENSION; j++) {
            if (board[i][j] == 1) {
                int temp_i, temp_j;
                // we have to check 8 tiles
                // 1
                temp_i = i - 1;
                temp_j = j - 2;
                if (valid_dimension(temp_i, temp_j) && board[temp_i][temp_j] == 1)
                    return 0;
                // 2
                temp_i = i - 2;
                temp_j = j - 1;
                if (valid_dimension(temp_i, temp_j) && board[temp_i][temp_j] == 1)
                    return 0;
                // 3
                temp_i = i - 2;
                temp_j = j + 1;
                if (valid_dimension(temp_i, temp_j) && board[temp_i][temp_j] == 1)
                    return 0;
                // 4
                temp_i = i - 1;
                temp_j = j + 2;
                if (valid_dimension(temp_i, temp_j) && board[temp_i][temp_j] == 1)
                    return 0;
                // 5
                temp_i = i + 1;
                temp_j = j + 2;
                if (valid_dimension(temp_i, temp_j) && board[temp_i][temp_j] == 1)
                    return 0;
                // 6
                temp_i = i + 2;
                temp_j = j + 1;
                if (valid_dimension(temp_i, temp_j) && board[temp_i][temp_j] == 1)
                    return 0;
                // 7
                temp_i = i + 2;
                temp_j = j - 1;
                if (valid_dimension(temp_i, temp_j) && board[temp_i][temp_j] == 1)
                    return 0;
                // 8
                temp_i = i + 1;
                temp_j = j - 2;
                if (valid_dimension(temp_i, temp_j) && board[temp_i][temp_j] == 1)
                    return 0;
            }
        }
    }
    return 1; // all safe
}

int main() {
    // read the board
    int board[DIMENSION][DIMENSION]; // no need to initialize
    for (int i = 0; i < DIMENSION; i++)
        for (int j = 0; j < DIMENSION; j++)
            scanf("%d", &board[i][j]);

    printf("%d", check(board));
    return 0;
}