#ifndef QUERA_UTILITY_H
#define QUERA_UTILITY_H

#endif //QUERA_UTILITY_H

#include <math.h>
#include <stdlib.h>
#include <string.h>

/**
 * Converts a number from base 10 to a number to another base
 * @param number The input number
 * @param to_base Target base
 * @return String of the number
 */
char *base_convert(long number, int to_base) {
    char letters[] = "0123456789ABCDEF";
    char result[64];
    memset(result, 0, sizeof(result));
    int counter = 0;
    while (number >= to_base) {
        result[counter] = letters[number % to_base];
        number /= to_base;
        counter++;
    }
    result[counter] = letters[number]; // the last digit
    // the string must be reversed
    unsigned long len = strlen(result);
    char *result_reversed = calloc(len + 1, sizeof(char)); // create a string to reverse the result
    for (counter = 0; counter < len; counter++)
        result_reversed[counter] = result[len - 1 - counter];
    return result_reversed;
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
    const unsigned long long To = (unsigned long long) sqrt((double) x);
    for (unsigned long long i = 5; i <= To; i += 4) {
        if (x % i == 0)
            return i;
        i += 2;
        if (x % i == 0)
            return i;
    }
    return 0;
}

/**
 * Converts a number from a base to long
 * @param number The number
 * @param base base
 * @return
 */
long long convert_from_base(const char number[], int base) {
    long long multiplier = 1;
    long long result = 0;
    for (int i = strlen(number) - 1; i >= 0; i--) {
        result += multiplier * (number[i] - '0');
        multiplier *= base;
    }
    return result;
}

/**
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
 * Checks if x is a perfect square root with binary search
 * @param x The number to check
 * @return The sqrt of x if x is perfect square. Otherwise 0
 */
unsigned long long perfect_sqrt(unsigned long long x) {
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
    return 0; // not prefect square root
}

/**
 * Integer power
 * https://stackoverflow.com/a/101613/4213397
 * @param base The base of power
 * @param exp The exponent
 * @return The result
 */
long long ipow(long long base, int exp) {
    long long result = 1;
    for (;;) {
        if (exp & 1)
            result *= base;
        exp >>= 1;
        if (!exp)
            break;
        base *= base;
    }

    return result;
}