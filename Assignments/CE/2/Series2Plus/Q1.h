#ifndef QUERA_Q1_H
#define QUERA_Q1_H

#endif //QUERA_Q1_H

#include <stdio.h>

int main() {
    int n;
    double x, sum = 1, numerator;
    unsigned long long factorial = 1;
    scanf("%d %lf", &n, &x);
    numerator = x;
    for (int i = 1; i <= n; i++) {
        factorial *= i;
        double now = numerator / (double) factorial; // calculate next number in series
        printf("%.16lf\t%.16lf\n", sum, now);
        sum += now;
        numerator *= x; // calculate power
    }
    return 0;
}