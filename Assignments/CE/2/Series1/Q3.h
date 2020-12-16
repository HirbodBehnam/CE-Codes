#include <stdio.h>

int main() {
    float Q1, Q2, Q3, Q4, E, F;
    float result = Q1 + Q2 + Q3 + Q4 + E + F;
    // find min
    float min = Q1; // we suppose that Q1 is the min for now. Then we check all other variables
    if (Q2 < min)
        min = Q2;
    if (Q3 < min)
        min = Q3;
    if (Q4 < min)
        min = Q4;
    if (E / 2 < min)
        min = E / 2;
    if (F / 2 < min)
        min = F / 2;
    // now subtract the min
    result -= min;
    if (result > 20) // fix scores more than 20
        result = 20;
    // print the result
    printf("%.2f", result); // round with 2 decimal places
    return 0;
}