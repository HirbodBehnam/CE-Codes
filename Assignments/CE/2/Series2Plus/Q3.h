#ifndef QUERA_Q3_H
#define QUERA_Q3_H

#endif //QUERA_Q3_H

#include <stdio.h>

int main() {
    int a, b;
    scanf("%d %d", &a, &b);
    // the second number is whitespace i think
    int whitespace = b;
    // print top
    for (int i = 0; i < a; i++) {
        for (int j = 0; j < whitespace - i; j++)
            printf(" ");
        for (int j = 0; j < 2 * i + 1; j++)
            printf("*");
        printf("\n");
    }
    // print middle row
    for(int i = 0; i < b - a; i++)
        printf(" ");
    for(int i = 0; i <= 2 * a; i++)
        printf("*");
    printf("\n");
    // print bottom
    for (int i = a - 1; i >= 0; i--) {
        for (int j = 0; j < whitespace - i; j++)
            printf(" ");
        for (int j = 0; j < 2 * i + 1; j++)
            printf("*");
        printf("\n");
    }
    return 0;
}