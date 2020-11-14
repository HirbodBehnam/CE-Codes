#ifndef QUERA_Q283_H
#define QUERA_Q283_H

#endif //QUERA_Q283_H

#include <stdio.h>

int run() {
    int a, b;
    scanf("%d %d", &a, &b);

    if ((a - b) % 2 == 1) { // odd number. Could have just wrote (a - b) & 1
        printf("Wrong difference!");
        return 0;
    }

    if (a <= b) {
        printf("Wrong order!");
        return 0;
    }

    int inner_thickness = (a - b) / 2;

    for (int i = 0; i < a; i++) {
        if (inner_thickness - i > 0 || a - i <= inner_thickness) { // print the think part without the empty space
            for (int j = 0; j < a; j++)
                printf("* ");
        } else { // some parts in middle is empty
            for (int j = 0; j < inner_thickness; j++)
                printf("* ");
            for (int j = 0; j < b; j++)
                printf("  ");
            for (int j = 0; j < inner_thickness; j++)
                printf("* ");
        }
        printf("\n");
    }
    return 0;
}