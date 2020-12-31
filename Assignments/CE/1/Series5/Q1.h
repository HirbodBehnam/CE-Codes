#ifndef QUERA_Q1_H
#define QUERA_Q1_H

#endif //QUERA_Q1_H

#define MAX 1000000

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * I spend a fucking hour on paper to solve this question :|
 * @param array Array of alive people
 * @param size Number of alive people
 * @param start Should we start killing from first guy (0) or second guy (1)?
 * @return The alive person at last
 */
int josephus(int *array, const int size, const int start) {
    if (size == 1) // one guy is alive; return it's index
        return array[0];

    /**
     * Of course I can rewrite this as something like: array[i] = array[2 * i + (start + 1) % 2];
     * But the readily will drop to zero
     */
    if (start == 1)
        for (int i = 1; i < size / 2 + size % 2; i++)
            array[i] = array[2 * i];
    else
        for (int i = 0; i < size / 2 + size % 2; i++)
            array[i] = array[2 * i + 1];

    if (size % 2 == 0)
        return josephus(array, size / 2, start);
    return josephus(array, size / 2 + start, (start + 1) % 2);
}

int main() {
    int n;
    scanf("%d", &n);
    int *people = calloc(MAX, sizeof(int));
    for (int i = 0; i < n; i++)
        people[i] = i + 1;

    printf("%d", josephus(people, n, 1));
    return 0;
}