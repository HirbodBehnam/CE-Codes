#ifndef QUERA_Q3_H
#define QUERA_Q3_H

#endif //QUERA_Q3_H

#include <stdio.h>

int steps = 0;

/**
 * Hanoi towers
 * Source of this code: https://www.geeksforgeeks.org/c-program-for-tower-of-hanoi/
 * Also this video has helped me ALOT to understand what is going on: https://www.youtube.com/watch?v=fffbT41IuB4
 * Also it's good to know that the number of steps is 2^n-1
 * @param rings The rings remaining
 */
void hanoi(int rings) {
    if (rings == 1) {
        steps++;
        return;
    }
    hanoi(rings - 1);
    steps++;
    hanoi(rings - 1);
}

int main() {
    int i;
    scanf("%d", &i);
    hanoi(i);
    printf("%d", steps);
    return 0;
}