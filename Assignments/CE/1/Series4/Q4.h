#ifndef QUERA_Q4_H
#define QUERA_Q4_H

#endif //QUERA_Q4_H

#include <stdio.h>

/**
 * Recursively draws with given (length/2) until n is 0
 * @param n The width of top / 2
 */
void draw_seven(int n) {
    if (n == 0)
        return;
    // draw top
    for (int i = 0; i < 2 * n; i++)
        putchar('*');
    putchar('\n');
    // draw other
    int whitespace = 2 * n - 2; // use a counter instead of fancy formulas
    for (int line = 0; line < 2 * n - 1; line++) {
        for (int i = 0; i < whitespace; i++) // print spaces before *
            putchar(' ');
        putchar('*');
        putchar('\n');
        whitespace--;
    }
    // call the function again
    draw_seven(n - 1);
}

int main() {
    int n;
    scanf("%d", &n);
    draw_seven(n);
    return 0;
}