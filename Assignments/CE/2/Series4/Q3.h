#ifndef QUERA_Q3_H
#define QUERA_Q3_H

#endif //QUERA_Q3_H

#define MINE '*'

#include <stdio.h>

/**
 * Checks if a dimension is valid mine board
 * @param i
 * @param j
 * @param max_x Max x in board
 * @param max_y Max y in board
 * @return 1 if good; Otherwise 0
 */
int valid_dimension(int i, int j, int max_x, int max_y) {
    return (i >= 0 && i < max_x) && (j >= 0 && j < max_y);
}

int main() {
    // create the board
    int m, n;
    scanf("%d %d", &m, &n);
    char board[m][n];
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            board[i][j] = 0; // initialize array
    int mines_count;
    scanf("%d", &mines_count);
    // read the mines
    for (int i = 0; i < mines_count; i++) {
        int x, y;
        scanf("%d %d", &x, &y);
        board[x - 1][y - 1] = MINE;
    }
    // fill the board
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (board[i][j] != MINE) { // get number of bombs around this tile
                int sum = 0;
                for (int x = i - 1; x <= i + 1; x++)
                    for (int y = j - 1; y <= j + 1; y++)
                        if (valid_dimension(x, y, m, n) && board[x][y] == MINE)
                            sum++;
                printf("%d ", sum);
            } else { // print the bomb
                printf("* ");
            }
        }
        printf("\n");
    }
    return 0;
}