#ifndef QUERA_Q16_H
#define QUERA_Q16_H

#endif //QUERA_Q16_H

#include <stdio.h>

int run() {
    int n;
    scanf("%d", &n);
    const int whitespace = n * 2 - 2; // whitespace between the stars
    // print from top to middle (middle row is also printed here)
    for (int i = 0; i < n; i++) {
        for (int white = 0; white < i; white++)
            putchar(' ');
        putchar('*');
        for (int white = 0;
             white < whitespace - 2 * i + 1; white++) // in each iteration, we must reduce 2 from whitespaces
            putchar(' ');
        putchar('*');
        putchar('\n');
    }
    // print the middle
    for (int white = 0; white <= whitespace / 2; white++) // in each iteration, we must reduce 2 from whitespaces
        putchar(' ');
    putchar('*');
    putchar('\n');
    // print the bottom; reverse loop of above
    for (int i = n - 1; i >= 0; i--) {
        for (int white = 0; white < i; white++)
            putchar(' ');
        putchar('*');
        for (int white = 0;
             white < whitespace - 2 * i + 1; white++) // in each iteration, we must reduce 2 from whitespaces
            putchar(' ');
        putchar('*');
        putchar('\n');
    }
    return 0;
}