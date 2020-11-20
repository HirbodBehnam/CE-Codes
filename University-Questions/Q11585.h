#ifndef QUERA_Q11585_H
#define QUERA_Q11585_H

#endif //QUERA_Q11585_H

#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    scanf("%d", &n);
    /**
     * The n-th element in the input_sums, is sum of all inputs from 0 to n
     */
    unsigned long long *input_sums = malloc(n * sizeof(unsigned long long));
    /**
     * The n-th element in input_sums_sums is the sum of all elements from 0 to n from input_sums
     */
    unsigned long long *input_sums_sums = malloc(n * sizeof(unsigned long long));
    scanf("%llu", &input_sums[0]); // read the first element to avoid using if in the loop
    /**
     * The result
     */
    unsigned long long sum = input_sums_sums[0] = input_sums[0];
    for (int i = 1; i < n; i++) {
        scanf("%llu", &input_sums[i]);
        input_sums[i] += input_sums[i - 1];
        input_sums_sums[i] = input_sums[i] + input_sums_sums[i - 1];
        /**
         * So let me explain what is happening here. I used a part of face recognition algorithm from https://youtu.be/uEJ71VlUmMQ?t=395
         * The approach is to have sum of all inputs from 0 to n stored in an array like input_sums. With that, if I want to find out
         * what is the sum of first n elements, I just have to look at input_sums[n]
         * Now let's say I want to find out what the is sum of elements 2 to 6 (0 is the first element); In this case
         * all I have to calculate is input_sums[6] - input_sums[2 - 1].
         *
         * Here is an example:
         * If the input is {1,2,3,4,5} then the input_sums is going to be {1,3,6,10,15}
         * I want to find out what the sum of elements 4(last element) to 2. All I have to is to subtract 15 - 3 = 12 (3 + 4 + 5 = 12)
         *
         * Before submitting this code, I used to have a another for loop to do like:
         * for(int i = 0; i < n; i++)
         *  for(int j = i + 1; j < n; j++)
         *   sum += input_sums[j] - input_sums[i];
         * This nested loops used to calculate all f(l,r)s possible
         * That algorithm was O(n^2) and thus used to fail if n was big (test 10 to 13)
         *
         * Next, I wrote a code here (in this loop) to reduce the LOC. The approach was this:
         * sum += input_sums[i];
         * for(int j = 0; j < i; j++)
         *  sum += input_sums[i] - input_sums[j];
         * This algorithm was still O(n^2) and thus failed again
         *
         * When I looked at this code once again, I told myself "I am summing input_sums[i] with sum (i + 1) times; Why not use multiplication?"
         * So I changed the code to:
         * sum += input_sums[i] * (i + 1);
         * for(int j = 0; j < i; j++)
         *  sum -= input_sums[j];
         * The algorithm was still O(n^2) but a bit faster.
         *
         * Then finally, I thought that "Well, I'm always subtracting first 'i' elements from input_sums from sum.
         * Why not use another sum array for this one?"
         *
         * So I came out with this algorithm which is O(n).
         */
        sum += input_sums[i] * (i + 1) - input_sums_sums[i - 1];
    }
    printf("%llu\n", sum);
    return 0;
}
