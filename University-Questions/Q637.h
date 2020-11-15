#ifndef QUERA_Q637_H
#define QUERA_Q637_H

#endif //QUERA_Q637_H

#define MAX_RES 1000
#define MAX_INPUT 1000 // It looks like that some inputs are even larger than 100 chars?

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main() {
    int n;
    int result[MAX_RES];
    memset(result, 0, sizeof(result));
    scanf("%d", &n);
    for (; n > 0; n--) {
        char input[MAX_INPUT];
        scanf("%s", input);
        // sum each digit
        int counter = 0;
        for (int i = strlen(input) - 1; i >= 0; i--) {
            result[counter] += input[i] - '0'; // deal with numbers more than 10 later
            counter++;
        }
    }
    // second pass to check for numbers like {1,10,2}
    for (int i = 0; i < MAX_RES; i++) {
        while (result[i] > 9) {
            result[i] -= 10;
            result[i + 1]++;
        }
    }
    // get size of result. We do not use strlen because it starts from beginning and stops as soon as it encounters \0
    int result_size = MAX_RES - 1;
    for (; result_size >= 0; result_size--)
        if (result[result_size] != 0)
            break;

    // print result
    if (result_size != -1) { // if the result size is -1 it means that the result is 0
        for (int i = result_size; i >= 0; i--)
            printf("%d", result[i]);
    } else {
        printf("0");
    }
    return 0;
}