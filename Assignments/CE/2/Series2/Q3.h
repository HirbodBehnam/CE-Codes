#ifndef QUERA_Q3_H
#define QUERA_Q3_H

#endif //QUERA_Q3_H

#include <stdio.h>

int main() {
    int a, b;
    scanf("%d %d", &a, &b);
    // print the top
    for (int i = 0; i < a; i++) {
        for (int j = 0; j < a - i - 1; j++)
            printf(" ");
        for (int j = 0; j < 2 * i + 1; j++)
            printf("*");
        // in quera, next whitespaces doesn't matter
        printf("\n");
    }
    // print the bottom
    for (int i = 0; i < b; i++) {
        for (int j = 0; j < a - 1; j++)
            printf(" ");
        printf("*\n");
    }
    return 0;
}