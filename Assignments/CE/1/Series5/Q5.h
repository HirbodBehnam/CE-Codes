#ifndef QUERA_Q5_H
#define QUERA_Q5_H

#endif //QUERA_Q5_H

#define MAX 100001

#include <stdio.h>

int main() {
    unsigned long long powers[MAX] = {0}; // initialize array with zero
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        powers[x] += x;
    }
    /**
     * From https://www.geeksforgeeks.org/maximum-sum-such-that-no-two-elements-are-adjacent/
     * I kinda know and don't know at the same time what is going on here;
     * So in include, we must add the this element in array + the excluded value from before because we cannot
     * include the previews number (they are adjacent)
     * For exclude, obviously, we shouldn't add this number to it; Instead we get the max of exclude and include
     * Why? because probably we can pick the old include (old number) or do not include that one either
     * I have to learn more about this algorithm; I don't still really understand this algorithm
     */
    unsigned long long include = powers[1], exclude = 0;
    for (int i = 2; i < MAX; i++) {
        unsigned long long temp = (include > exclude) ? include : exclude;
        include = exclude + powers[i];
        exclude = temp;
    }
    printf("%llu", (include > exclude) ? include : exclude);
    return 0;
}