#ifndef QUERA_Q597_H
#define QUERA_Q597_H

#endif //QUERA_Q597_H

#include <stdio.h>

int run() {
    int steps, x, y;
    scanf("%d", &steps);
    if (steps % 4 == 0) {
        x = -steps / 4;
        y = steps / 4; // or -x
    } else if (steps % 4 == 1) {
        x = y = -steps / 4;
    } else if (steps % 4 == 2) {
        x = y = steps / 4;
        x++;
        y = -y;
    } else if (steps % 4 == 3) {
        x = y = steps / 4 + 1;
    }
    printf("%d %d", x, y);
    return 0;
}