#ifndef QUERA_Q2_H
#define QUERA_Q2_H

#endif //QUERA_Q2_H

#include <stdio.h>

double a, b, c, d, e, f;

/**
 * Calculates the function by the given x
 * @param x X
 * @return f(x)
 */
double function(double x) {
    return a * x * x * x * x * x + b * x * x * x * x + c * x * x * x + d * x * x + e * x + f;
}

/**
 * Does binary search to find the root of function
 * @param start The start x of the interval
 * @param end The end x of the interval
 * @param start_result The start y of the interval
 * @param end_result The end y of the interval
 * @return
 */
double binary_search(double start, double end, double start_result, double end_result) {
    const double mid = (start + end) / 2; // find the mid x
    const double mid_res = function((start + end) / 2); // find the mid y
    if (mid_res < 0.000001 && mid_res > -0.000001) // set the precision
        return mid;
    if ((mid_res > 0 && start_result < 0) || (mid_res < 0 && start_result > 0)) // check the sign (they must deffer)
        return binary_search(start, mid, start_result, mid_res);
    return binary_search(mid, end, mid_res, end_result); // otherwise this one must be called
}

int main() {
    double start, end;
    scanf("%lf %lf %lf %lf %lf %lf", &a, &b, &c, &d, &e, &f);
    scanf("%lf %lf", &start, &end);
    // check the sign
    double start_result = function(start), end_result = function(end);
    if ((start_result > 0 && end_result > 0) || (start_result < 0 && end_result < 0)) {
        printf("NOT POSSIBLE!");
        return 0;
    }
    // do the search
    double res = binary_search(start, end, start_result, end_result);
    printf("%.6lf", res);
    return 0;
}