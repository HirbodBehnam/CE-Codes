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
    double interval_width = (double)(b - a) / (double) n, area = 0, begin = a; // use double not float to get 100 not 80
    for (int i = 0; i < n; i++) { // calculate the area of rectangle
        area += begin * begin * interval_width; // a * a is here to calculate the height of rectangle
        begin += interval_width; // move the start position of interval
    }
    return area;
}

int main() {
    float a, b;
    scanf("%f %f %d", &a, &b, &n);
    printf("%.2f", Integral(a, b));
    return 0;
}