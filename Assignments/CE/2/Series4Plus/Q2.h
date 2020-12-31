#ifndef QUERA_Q2_H
#define QUERA_Q2_H

#endif //QUERA_Q2_H

#define EMPTY 0
#define QUEEN 1

#include <stdio.h>

int n;
int solutions = 0;

/**
 * Checks if a queen can be placed in this column
 * @param board
 * @param i_place
 * @param j_place
 * @return
 */
int valid(const char board[n][n], const int i_place, const int j_place) {
    // check row
    for (int i = 0; i < n; i++)
        if (board[i_place][i] == QUEEN)
            return 0; // another queen in this row
    // check column
    for (int i = 0; i < n; i++)
        if (board[i][j_place] == QUEEN)
            return 0; // another queen in this column

    int temp_i, temp_j;
    // check cross top-left to of place
    temp_i = i_place;
    temp_j = j_place;
    while (temp_i >= 0 && temp_j >= 0) {
        if (board[temp_i][temp_j] == QUEEN)
            return 0;
        temp_i--;
        temp_j--;
    }
    // check cross top-right to of place
    temp_i = i_place;
    temp_j = j_place;
    while (temp_i >= 0 && temp_j < n) {
        if (board[temp_i][temp_j] == QUEEN)
            return 0;
        temp_i--;
        temp_j++;
    }
    // check cross bottom-right to of place
    temp_i = i_place;
    temp_j = j_place;
    while (temp_i < n && temp_j >= 0) {
        if (board[temp_i][temp_j] == QUEEN)
            return 0;
        temp_i++;
        temp_j--;
    }
    // check cross bottom-left to of place
    temp_i = i_place;
    temp_j = j_place;
    while (temp_i < n && temp_j < n) {
        if (board[temp_i][temp_j] == QUEEN)
            return 0;
        temp_i++;
        temp_j++;
    }
    return 1; // valid
}

/**
 * Bruteforce places of queens in board
 * @param board The board
 * @param row Which row we should place a queen
 */
void backtrack(char board[n][n], int row) {
    if (row == n) { // we have created a board!
        solutions++;
        return;
    }
    for (int column = 0; column < n; column++) {
        if (valid(board, row, column)) {
            board[row][column] = QUEEN;
            backtrack(board, row + 1);
        }
        board[row][column] = EMPTY; // remove the queen from board
    }
}

int main() {
    scanf("%d", &n);
    char board[n][n];
    // empty the board
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            board[i][j] = EMPTY;
    // backtrack
    backtrack(board, 0);
    printf("%d", solutions);
    return 0;
}