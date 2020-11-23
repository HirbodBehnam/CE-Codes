#ifndef QUERA_Q654_H
#define QUERA_Q654_H

#endif //QUERA_Q654_H

#include <stdio.h>

int main() {
    int sum;
    scanf("%d", &sum);
    // Odd sums are not acceptable
    if (sum % 2 == 1) {
        printf("Impossible");
        return 0;
    }
    /**
     * A semi-fucked brute force. We assume that a < b < c
     * We can conclude that 'a' must be less than floor(sum / 3) because in that case 'a' is not the smallest number
     * In b loop, we terminate the loop as soon as c becomes less than b. Because we have assumed that a < b < c
     * At last check if they satisfy the pythagorean theorem
     */
    for (int a = 1; a < sum / 3; a++) { // a cannot be more than sum / 3
        for (int b = a + 1;; b++) { // a and b cannot be equal
            int c = sum - a - b; // calculate c
            if (c <= b)
                break;
            if (a * a + b * b == c * c) { // apply simple pythagorean theorem
                printf("%d %d %d", a, b, c);
                return 0;
            }
        }
    }
    printf("Impossible");
    return 0;
}