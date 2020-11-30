#ifndef QUERA_Q652_H
#define QUERA_Q652_H

#endif //QUERA_Q652_H

#include <math.h>
#include <stdio.h>

// I used bruteforce here; I don't know if there is a better way or not
// I can also use a lookup table
int main() {
    unsigned long long EndInterval;
    {
        unsigned long long pow2_sum = 0, sum = 0;
        int n;
        scanf("%d", &n);
        for (int i = 0; i < n; i++) {
            unsigned long long input;
            scanf("%llu", &input);
            pow2_sum += input * input;
            sum += input;
        }
        EndInterval = sum * sum - pow2_sum;
    }

    for (unsigned long long i = 100; i <= EndInterval; i++) {
        int digits = log10(i);
        digits++;
        unsigned long long temp = i, sum = 0;
        while (temp != 0) {
            sum += pow(temp % 10, digits);
            temp /= 10;
        }
        if (sum == i)
            printf("%llu\n", i);
    }
    return 0;
}
