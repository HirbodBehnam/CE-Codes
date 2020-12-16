#ifndef QUERA_Q1_H
#define QUERA_Q1_H

#endif //QUERA_Q1_H

#include <stdbool.h>
#include <stdio.h>

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
 * Checks if a number is shansi or not
 * Shani number is a number which only contains 7 or 4
 * @param a The number to check
 * @return True if the number is shansi
 */
bool shansi(unsigned long long a) {
    if (a == 0) // zero is not a shansi number
        return false;
    while (a != 0) {
        if (a % 10 != 7 && a % 10 != 4) // check if the number contains anything other than 4 or 7
            return false;
        a /= 10;
    }
    return true;
}

/*
 * Small explanation on how I calculate factors of numbers
 * The strategy is if the number "i" is divisible by "a", it means that obviously, a/i is also divisible by a
 * Have this example: We want to calculate factors of 100
 * We start from 1; 1 is divisible by 100. So 100/1 = 100 Must also be divisible by 100
 * 2 is divisible by 100. So 100/2 = 50 Must also be divisible by 100
 * 3 is not divisible by 100
 * 4 is divisible by 100. So 100/4 = 25 Must also be divisible by 100
 * The last number that we have to check is 10. floor(sqrt(number))
 * 10 is divisible by 100. So 100/10 = 10 Must also be divisible by 100
 * But we have encountered a problem; If the number is perfect square, we have counted the sqrt(number) (for example here 10) twice
 * So it's mandatory to check if the number is perfect square at last or while increasing i (the counter) to prevent counting these number twice
 */

/**
 * A function to list all factors of a number and check them to see any of them is shansi or not
 * @param a The number to check
 * @return True if the number is semi-shansi
 */
bool semi_shansi(unsigned long long a) {
    unsigned long long to = floor_sqrt(a);
    for (unsigned long long i = 1; i <= to; i++) {
        if (a % i == 0) {
            if (shansi(i) || shansi(a / i))
                return true;
        }
    }
    return false;
}

int main() {
    int n;
    scanf("%d", &n);
    for (; n > 0; n--) {
        // read each number and check it
        unsigned long long number;
        scanf("%lld", &number);
        printf(semi_shansi(number) ? "YES\n" : "NO\n");
    }
}