#include "grader.h"
#include <stdarg.h>

/**
 * A macro that also accepts the operator as argument
 */
#define calc(n1, n2, opt) ((n1) opt (n2))

/**
 * We can't use math sqrt? No problem! Lets use this.
 * This is basically an old code I've written to practice binary search
 * Source: https://gist.github.com/HirbodBehnam/ec8f02f73608fe4aaa94d6d27bcb4bbe
 * Returns floor(sqrt(x))
 * @param x The number
 * @return floor(sqrt(x))
 */
unsigned long long floor_sqrt(unsigned long long x) {
    unsigned long long low = 0, high = x;
    // prevent integer overflow on pow2
    if (high > 18446744065119617025LLU)
        return 4294967296LLU;
    if (high > 4294967296LLU * 2 - 1)
        high = 4294967296LLU * 2 - 1;
    // use binary search
    while (low <= high) {
        const unsigned long long mid = (low + high) / 2;
        const unsigned long long pow2 = mid * mid;
        if (pow2 == x)
            return mid;

        if (pow2 < x) // target must be higher
            low = mid + 1;
        else // target must be lower
            high = mid - 1;
    }
    return high; // this returns the floor of the sqrt
}

/**
 * Sum of factors
 * 14 = {1,2,7,14} = 14 + 7 + 2 + 1 = 24
 * @param a
 * @return
 */
long long sum_factors(int a) {
    int to = (int) floor_sqrt(a);
    long long sum = 0;
    for (int i = 1; i <= to; i++)
        if (a % i == 0) {
            sum += i;
            if (i * i != a) // fix perfect square numbers
                sum += a / i;
        }

    return sum;
}

// It looks like that the preprocessor if works? I mean at least I'm not getting any compile errors
#if s == 0

/**
 * Gets the the max or min of sum of factors of these numbers
 * @param m 'M' to get the max 'm' to get the min
 * @param a First number
 * @param b Second number
 * @param c Third number
 * @return
 */
long long findDivisorSum(char m, int a, int b, int c) {
    long long res = sum_factors(a);
    long long sum = sum_factors(b);
    if (m == 'M') { // max
        if (res < sum)
            res = sum;
        sum = sum_factors(c);
        if (res < sum)
            res = sum;
    } else { // min
        if (res > sum)
            res = sum;
        sum = sum_factors(c);
        if (res > sum)
            res = sum;
    }
    return res;
}

#else
/**
 * Sources:
 * https://stackoverflow.com/a/10071238/4213397
 * @param a Number of numbers
 * @param ... The numbers
 * @return
 */
long long findDivisorSum(int a, ...) {
    va_list list;
    long long res = 0x7FFFFFFFFFFFFFFF;
    va_start(list, a);
    for (int j = 0; j < a; j++) {
        long long sum = sum_factors(va_arg(list, int));
        if (res > sum)
            res = sum;
    }
    va_end(list);
    return res;
}

#endif

long long run(char type, int num1, int num2, int num3, int num4) {
    return findDivisorSum(type, calc(num1, num2, +), calc(num1, num2, -), calc(num3, num4, *));
}
