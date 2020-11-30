#ifndef QUERA_Q335_H
#define QUERA_Q335_H

#endif //QUERA_Q335_H

#define MAX 100

#include <stdio.h>

int run() {
    /**
     * So this array somehow plays the role of stack type in higher level languages
     * The strategy in this question is to use a stack like object to keep track of sums of sub-sets
     */
    unsigned long long sums[MAX], temp_number;
    int index = -1;
    // read input char to char
    int c;
    while ((c = getchar()) != EOF) {
        if (c == '{') {
            // same as pushing zero into stack
            index++;
            sums[index] = 0;
            temp_number = 0;
        } else if (c == '}') {
            sums[index] += temp_number;
            // same as popping last element from stack
            printf("%llu\n", sums[index]);
            sums[index - 1] += sums[index]; // add the sum to element before (to the set before)
            index--;
            temp_number = 0;
        } else if (c == ',') { // done reading the number, add it into stack
            sums[index] += temp_number;
            temp_number = 0;
            getchar(); // this skips the space after ,
        } else { // read the number
            temp_number *= 10;
            temp_number += c - '0';
        }
    }
    return 0;
}