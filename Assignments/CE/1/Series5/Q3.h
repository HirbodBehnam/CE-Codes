#ifndef QUERA_Q3_H
#define QUERA_Q3_H

#endif //QUERA_Q3_H

#include <stdbool.h>
#include <stdio.h>

int n, m, to_change_color, color;

/**
 * Backtrack all the ways
 * It looks like that validating the dimension doesn't matter and I always get 18 from 20?
 * And also still commenting out those useless line (described in comments) doesn't matter
 * @param playground The playground
 * @param x Current x position
 * @param y Current y position
 */
void backtrack(int playground[n][m], const int x, const int y) {
    // check this tile's color
    if (playground[x][y] != to_change_color)
        return;
    playground[x][y] = color;
    // try other tiles
    backtrack(playground, x + 1, y + 1);
    backtrack(playground, x + 1, y);
    backtrack(playground, x + 1, y - 1); // this doesnt matter
    backtrack(playground, x, y - 1); // also this doesnt matter
    backtrack(playground, x - 1, y - 1);
    backtrack(playground, x - 1, y);
    backtrack(playground, x - 1, y + 1);
    backtrack(playground, x, y + 1); // also this :|
}

int main() {
    scanf("%d %d", &n, &m);
    int first_x, first_y;
    scanf("%d %d %d", &first_x, &first_y, &color);
    int playground[n][m];
    // read the playground
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            scanf("%d", &playground[i][j]);
    // get the color
    to_change_color = playground[first_x - 1][first_y - 1];
    // change the colors
    backtrack(playground, first_x - 1, first_y - 1);
    // print
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
            printf("%d ", playground[i][j]);
        putchar('\n');
    }
    return 0;
}