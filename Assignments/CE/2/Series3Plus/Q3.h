#ifndef QUERA_Q3_H
#define QUERA_Q3_H

#endif //QUERA_Q3_H

#include <stdio.h>

/**
 * Number of rectangles
 */
int n;

/**
 * Calculates the integral of x^2 in a specified interval with 'n' rectangles
 * @param a The beginning of interval
 * @param b The end of interval
 * @return The integral
 */
float Integral(float a, float b) {
    float width = (b - a) / (float) n;
    float first = (float) n * a * a;
    float second = (float) (n - 1) * (b - a) * a;
    float third = (float) (n - 1) * (float) (n) * (float) (2 * (n - 1) + 1) * width * width / 6;
    return width * (first + second + third);
}

int main() {
    float a, b;
    scanf("%f %f %d", &a, &b, &n);
    printf("%.2f", Integral(a, b));
    return 0;
}