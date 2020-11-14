#ifndef QUERA_Q658_H
#define QUERA_Q658_H

#endif //QUERA_Q658_H

#include <stdio.h>

int main() {
    int n;
    long long best = 0;
    int stonks[100];
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int temp;
        scanf("%d", &temp);
        stonks[i] = temp;
    }
    /**
     * Smart brute force. I don't know if there is any better way to do this
     * There are two optimization to this brute force:
     * 1. Do not start on negative or 0 numbers
     * 2. If at some point the sum is less than zero, break the inner loop and move index to j to start from counting there
     * The algorithm complexity is still O(n^2) however it's just a bit faster than simple brute force
     */
    for (int i = 0; i < n; i++) {
        if (stonks[i] <= 0) // do not start on the negative numbers
            continue;
        long long sum = stonks[i];
        if (sum > best)
            best = sum;
        for (int j = i + 1; j < n; j++) {
            sum += stonks[j];
            if (sum < 0) { // also do not check next numbers if the sum is less than 0
                i = j - 1; // -1 to counter the i++
                break;
            }
            if (sum > best)
                best = sum;
        }
    }
    printf("%lld", best);
}