#ifndef QUERA_6_H
#define QUERA_6_H

#endif //QUERA_6_H

#include <stdarg.h>
#include "grader.h"

extern int s;

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
 * Returns 0 if the number is prime. Returns it's first factor if not
 * @param number The number to check
 * @return 0 if the number is prime otherwise it's first factor
 */
unsigned long long is_prime(unsigned long long x) {
    if (x == 1)
        return 1;
    if (x == 2 || x == 3 || x == 5 || x == 7)
        return 0;
    if (x % 2 == 0)
        return 2;
    if (x % 3 == 0)
        return 3;
    const unsigned long long To = floor_sqrt(x);
    for (unsigned long long i = 5; i <= To; i += 4) { // check 6k+-1
        if (x % i == 0) // 6k - 1
            return i;
        i += 2;
        if (x % i == 0) // 6k + 1
            return i;
    }
    return 0;
}

/**
 * Counts number of prime factors
 * 14 = {1,2,7,14} = 9
 * @param a
 * @return
 */
long long sum_prime_factors(int a) {
    int to = (int) floor_sqrt(a);
    long long sum = 0;
    for (int i = 1; i <= to; i++)
        if (a % i == 0) {
            if (is_prime(i) == 0)
                sum += i;
            if (i * i != a) { // fix perfect square numbers
                if (is_prime(a / i) == 0)
                    sum += a / i;
            }
        }

    return sum;
}

/**
 * Sources:
 * https://stackoverflow.com/a/10071238/4213397
 * @param a
 * @param ...
 * @return
 */
long long findDivisorSum(int a, ...) {
    if (s == 0) {
        if (a == 'M') {

        } else {

        }
    } else {
        long long min = 0x7FFFFFFFFFFFFFFF;
        va_list list;
        va_start(list, a);
        for (int j = 0; j < a; j++) {
            long long sum = sum_prime_factors(va_arg(list, int));
            if(min < sum)
                min = sum;
            printf("%d", va_arg(list, int));
        }
        va_end(list);
        return min;
    }
}

int calc(){

}

long long run(char type, int num1, int num2, int num3, int num4) {
    return findDivisorSum(type, calc(num1, num2, +), calc(num1, num2, -), calc(num3, num4, *));
}