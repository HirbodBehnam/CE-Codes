#ifndef QUERA_Q712_H
#define QUERA_Q712_H

#endif //QUERA_Q712_H

#include <stdio.h>
#include <stdlib.h>

/**
 * Reverses a part of the array
 * @param ary
 * @param begin
 * @param end
 */
void reverse(int *arr, int start, int end) {
    int temp;
    while (start < end) {
        temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
}

// Time limit fail
int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    int *cassettes = malloc((n + 1) * sizeof(int));
    // fill cassettes
    for (int i = 1; i <= n; i++)
        cassettes[i] = i;
    // get commands
    for (; m > 0; m--) {
        char command[5];
        scanf("%s", command);
        if (command[0] == 'N') { // name
            int index;
            scanf("%d", &index);
            printf("%d\n", cassettes[index]);
        } else { // REV
            int begin, end;
            scanf("%d %d", &begin, &end);
            reverse(cassettes, begin, end);
        }
    }
    return 0;
}