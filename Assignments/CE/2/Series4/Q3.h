#ifndef QUERA_Q3_H
#define QUERA_Q3_H

#endif //QUERA_Q3_H

#define MINE '*'

#include <stdio.h>

/**
 * Checks if a dimension is valid mine board
 * @param i
 * @param j
 * @return 1 if good; Otherwise 0
 */
int valid_dimension(int i, int j, int mine_x, int mine_y) {
    return (i >= 0 && i < mine_x) && (j >= 0 && j < mine_y);
}

int main() {
    // create the board
    int m, n;
    scanf("%d %d", &m, &n);
    char board[m][n];
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
            if (board[i][j] != '*') { // get number of bombs around this tile
                int sum = 0;
                if (valid_dimension(i - 1, j - 1, m, n) && board[i - 1][j - 1] == MINE)
                    sum++;
                if (valid_dimension(i - 1, j, m, n) && board[i - 1][j] == MINE)
                    sum++;
                if (valid_dimension(i - 1, j + 1, m, n) && board[i - 1][j + 1] == MINE)
                    sum++;
                if (valid_dimension(i, j + 1, m, n) && board[i][j + 1] == MINE)
                    sum++;
                if (valid_dimension(i + 1, j + 1, m, n) && board[i + 1][j + 1] == MINE)
                    sum++;
                if (valid_dimension(i + 1, j, m, n) && board[i + 1][j] == MINE)
                    sum++;
                if (valid_dimension(i + 1, j - 1, m, n) && board[i + 1][j - 1] == MINE)
                    sum++;
                if (valid_dimension(i, j - 1, m, n) && board[i][j - 1] == MINE)
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