#ifndef QUERA_Q11585_H
#define QUERA_Q11585_H

#endif //QUERA_Q11585_H

#include <stdio.h>
#include <stdlib.h>

int main(){
    int n;
    scanf("%d", &n);
    /**
     * The n-th element in the input_sums, is sum of all inputs from 0 to n
     */
    unsigned long long* input_sums = malloc(n * sizeof(unsigned long long));
    /**
     * The n-th element in input_sums_sums is the sum of all elements from 0 to n from input_sums
     */
    unsigned long long* input_sums_sums = malloc(n * sizeof(unsigned long long));
    scanf("%llu", &input_sums[0]); // read the first element to avoid using if in the loop
    /**
     * The result
     */
    unsigned long long sum = input_sums_sums[0] = input_sums[0];
    for(int i = 1; i < n; i++) {
        scanf("%llu", &input_sums[i]);
        input_sums[i] += input_sums[i - 1];
        input_sums_sums[i] = input_sums[i] + input_sums_sums[i - 1];
        sum += input_sums[i] * (i + 1) - input_sums_sums[i - 1];
    }
    printf("%llu\n", sum);
    return 0;
}