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
    float interval_width = (b - a) / (float) n, area = 0;
    for (int i = 0; i < n; i++) { // calculate the area of rectangle
        area += a * a * interval_width; // a * a is here to calculate the height of rectangle
        a += interval_width; // move the start position of interval
    }
    return area;
}

int main() {
    float a, b;
    scanf("%f %f %d", &a, &b, &n);
    printf("%.2f", Integral(a, b));
    return 0;
}