#ifndef QUERA_Q14_H
#define QUERA_Q14_H

#endif //QUERA_Q14_H

#include <stdio.h>

int run() {
    int n;
    scanf("%d", &n);
    const int whitespace = n * 2 - 2;
    // print from top to middle (middle row is also printed here)
    for (int i = 0; i < n; i++) {
        for (int star = 0; star <= i; star++)
            putchar('*');
        for (int white = 0; white < whitespace - 2 * i; white++) // in each iteration, we must reduce 2 from whitespaces
            putchar(' ');
        for (int star = 0; star <= i; star++)
            putchar('*');
        putchar('\n');
    }
    // print bottom of shape; Just a simple reverse loop
    for (int i = n - 2; i >= 0; i--) {
        for (int star = 0; star <= i; star++)
            putchar('*');
        for (int white = 0; white < whitespace - 2 * i; white++)
            putchar(' ');
        for (int star = 0; star <= i; star++)
            putchar('*');
        putchar('\n');
    }
    return 0;
}