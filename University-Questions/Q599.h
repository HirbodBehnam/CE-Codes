#ifndef QUERA_Q599_H
#define QUERA_Q599_H

#endif //QUERA_Q599_H

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// I don't know why this doesn't work while the C# code works :|

double *calculate(double vx, double vy, double y0, double h) {
    double *res = malloc(2 * sizeof(double));
    double a = -5.0, b = vy, c = y0 - h;
    double delta = b * b - 4 * a * c;
    if (delta < 0) {
        res[0] = -1;
        res[1] = -1;
    } else if (delta == 0) {
        res[0] = (-b) / (2 * a);
        if (res[0] >= 0)
            res[0] *= vx;
        res[1] = -1;
    } else {
        delta = sqrt(delta);
        res[0] = (-b + delta) / (2 * a);
        res[1] = (-b - delta) / (2 * a);
        if (res[0] >= 0)
            res[0] *= vx;
        if (res[1] >= 0)
            res[1] *= vx;
    }
    return res;
}

int main() {
    double vx, vy, y0, h;
    scanf("%lf %lf %lf %lf", &vx, &vy, &y0, &h);
    double *res = calculate(vx, vy, y0, h);
    if (res[0] >= 0)
        printf("%.2lf", res[0]);
    if (res[1] >= 0)
        printf("%.2lf", res[1]);
    if (res[0] < 0 && res[1] < 0)
        printf("impossible");
    return 0;
}