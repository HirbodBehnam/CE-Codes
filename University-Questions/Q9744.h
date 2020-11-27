#ifndef QUERA_Q9744_H
#define QUERA_Q9744_H

#endif //QUERA_Q9744_H

#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

unsigned long long min = 0xffffffffffffffff;
char *p;

bool array_contains(const char *array, const int length, const char to_check) {
    for (int i = 0; i < length; i++)
        if (array[i] == to_check)
            return true;

    return false;
}

void backtrack(const int *map, const int length, const int level, unsigned long long sum, const char *chosen) {
    if (sum > min)
        return;
    if (level == length) {
        if (min >= sum) {
            memcpy(p, chosen, level);
            min = sum;
        }
        return;
    }
    char *chosen_now = malloc((level + 1) * sizeof(char));
    memcpy(chosen_now, chosen, level * sizeof(char));
    for (char i = 0; i < length; i++) {
        if (!array_contains(chosen, level, i)) {
            chosen_now[level] = i;
            backtrack(map, length, level + 1, sum + map[length * i + level], chosen_now);
        }
    }
    free(chosen_now);
}

int run() {
    int n;
    scanf("%d", &n);
    p = malloc(n * sizeof(char));
    int *cost = malloc(n * n * sizeof(int));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &cost[i * n + j]);

    backtrack((const int *) cost, n, 0, 0, 0);
    free(cost);

    for (int i = 0; i < n; i++)
        printf("%d\n", p[i]);

    free(p);
    return 0;
}