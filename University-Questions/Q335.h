#ifndef QUERA_Q335_H
#define QUERA_Q335_H

#endif //QUERA_Q335_H

#define MAX 100

#include <stdio.h>

int main() {
    /**
     * So this array somehow plays the role of stack type in higher level languages
     * The strategy in this question is to use a stack like object to keep track of sums of sub-sets
     */
    unsigned long long sums[MAX], temp_number;
    int stack_size = 0;
    // read input char to char
    int c;
    while ((c = getchar()) != EOF) {
        if (c == '{') {
            // same as pushing zero into stack
            stack_size++;
            sums[stack_size - 1] = 0;
            temp_number = 0;
        } else if (c == '}') {
            sums[stack_size - 1] += temp_number;
            printf("%llu\n", sums[stack_size - 1]);
            // same as popping last element from stack
            stack_size--;
            if(stack_size != 0)
                sums[stack_size - 1] += sums[stack_size]; // add the sum to element before (to the set before)
            temp_number = 0;
        } else if (c == ',') { // done reading the number, add it into stack
            sums[stack_size - 1] += temp_number;
            temp_number = 0;
        } else if(c >= '0' && c <= '9') { // read the number
            temp_number *= 10;
            temp_number += c - '0';
        }
    }
    return 0;
}