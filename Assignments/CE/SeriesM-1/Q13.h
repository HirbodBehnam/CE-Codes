#ifndef QUERA_Q13_H
#define QUERA_Q13_H

#endif //QUERA_Q13_H

#include <stdlib.h>
#include <stdio.h>

int run() {
    int n;
    scanf("%d", &n);
    // print top row
    for (int i = 0; i < n / 2; i++)
        putchar(' ');
    putchar('*');
    putchar('\n');
    // print top
    for (int i = 1; i < n - 1; i++) {
        for (int j = 0; j < abs(n / 2 - i); j++)
            putchar(' ');
        putchar('*');
        for (int j = 0; j < n - 2 * abs(n / 2 - i) - 2; j++)
            putchar(' ');
        putchar('*');
        putchar('\n');
    }
    // print bottom row
    for (int i = 0; i < n / 2; i++)
        putchar(' ');
    if (n != 1)
        putchar('*');
    return 0;
}