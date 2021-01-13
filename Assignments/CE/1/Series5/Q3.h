#ifndef QUERA_Q3_H
#define QUERA_Q3_H

#endif //QUERA_Q3_H

#include <stdbool.h>
#include <stdio.h>

int n, m, to_change_color, color;

/**
 * Checks if a position in playground is valid
 * @param x x
 * @param y y
 * @return True if valid, otherwise false
 */
bool valid_position(const int x, const int y) {
    return (x >= 0 && x < n) && (y >= 0 && y < m);
}

/**
 * Backtrack all the ways
 * It's kinda flood fill
 * @param playground The playground
 * @param checked If checked[x][y] it's true, it means that we should not do fill on this index
 * In two testcases, the color is equal to to_change_color so it will get fucked without this value
 * @param x Current x position
 * @param y Current y position
 */
void backtrack(int playground[n][m], bool checked[n][m], const int x, const int y) {
    // check position
    if (!valid_position(x, y))
        return;
    // check this tile's color
    if (playground[x][y] != to_change_color || checked[x][y])
        return;
    playground[x][y] = color;
    checked[x][y] = true;
    // try other tiles
    for (int i = -1; i <= 1; i++)
        for (int j = -1; j <= 1; j++)
            backtrack(playground, checked, x + i, y + j);
}

int main() {
    scanf("%d %d", &n, &m);
    int first_x, first_y;
    scanf("%d %d %d", &first_x, &first_y, &color);
    int playground[n][m];
    bool checked[n][m];
    // read the playground
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            scanf("%d", &playground[i][j]);
            checked[i][j] = false;
        }
    // get the color
    to_change_color = playground[first_x - 1][first_y - 1];
    // change the colors
    backtrack(playground, checked, first_x - 1, first_y - 1);
    // print
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
            printf("%d ", playground[i][j]);
        putchar('\n');
    }
    return 0;
}