#ifndef QUERA_Q3_H
#define QUERA_Q3_H

#endif //QUERA_Q3_H

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
 * Returns |a|
 * @param a
 * @return
 */
int abs(int a) {
    return a > 0 ? a : -a;
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
 * Counts the digits in a number
 * @param a Number to count the digits
 * @return Number of digits
 */
int digits_count(int a) {
    int counter = 0;
    while (a != 0) {
        counter++;
        a /= 10;
    }
    return counter;
}

/**
 * Calculates the sums of digits of a number
 * @param a The number to calculate it's sum of digits
 * @return Sums of digits
 */
int digits_sum(int a) {
    int sum = 0;
    while (a != 0) {
        sum += a % 10;
        a /= 10;
    }
    return sum;
}

/**
 * Calculates the product of digits of a number
 * @param a The number to calculate it's product of digits
 * @return Product of digits
 */
int digits_product(int a) {
    int product = 1;
    while (a != 0) {
        product *= a % 10;
        a /= 10;
    }
    return product;
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
 * Counts the factors of a number
 * @param a
 * @return
 */
int count_factors(int a) {
    int to = (int) floor_sqrt(a);
    int count = 0;
    for (int i = 1; i <= to; i++)
        if (a % i == 0)
            count += 2;

    if (to * to == a) // fix perfect square numbers
        count--;
    return count;
}

/**
 * Counts number of prime factors
 * 14 = {1,2,7,14} = 2
 * @param a
 * @return
 */
int count_prime_factors(int a) {
    int to = (int) floor_sqrt(a);
    int count = 0;
    for (int i = 1; i <= to; i++)
        if (a % i == 0) {
            if (is_prime(i) == 0)
                count++;
            if (is_prime(a / i) == 0) {
                if (i * i != a) // fix perfect square root numbers
                    count++;
            }
        }
    return count;
}

/**
 * Counts number of prime factors
 * 14 = {1,2,7,14} = 9
 * @param a
 * @return
 */
int sum_prime_factors(int a) {
    int to = (int) floor_sqrt(a);
    int sum = 0;
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
 * Checks if a number is prime even if we shift it
 * For example 1193 is prime because 1193, 3119, 9311 and 1931 is prime thus this function returns true
 * @param a The number to check
 * @return
 */
bool loop_prime(int a) {
    int multiplier = 1, digits = digits_count(a);
    for (int i = 1; i < digits; i++)
        multiplier *= 10;
    // calculate all permutations
    for (int i = 0; i < digits; i++) {
        if (is_prime(a) != 0)
            return false;
        int first_digit = a % 10;
        a /= 10;
        a += multiplier * first_digit; // this rotates the number
    }
    return true;
}

int main() {
    int n, best_code = 0;
    bool first = true;
    double best_stonks;
    scanf("%d", &n);
    for (; n > 0; n--) {
        int stonks = 0;
        int code, volume_transaction, price, volume_need, volume_giving;
        scanf("%d %d %d %d %d", &code, &volume_transaction, &price, &volume_need, &volume_giving);
        // check volume of transaction
        if (loop_prime(volume_transaction))
            stonks += digits_sum(volume_transaction);
        else
            stonks -= count_prime_factors(volume_transaction);
        // check x
        int x = volume_need - volume_giving;
        if (x != 0) {
            if (abs(x) % count_factors(abs(x)) == 0) {
                int product = digits_product(abs(x));
                if (x > 0)
                    stonks += product;
                else
                    stonks -= product;
            } else {
                int sum = sum_prime_factors(abs(x));
                if (x > 0)
                    stonks += sum;
                else
                    stonks -= sum;
            }
        }
        // check the stonks
        if (best_stonks < (double) stonks / price || first) {
            best_stonks = (double) stonks / price;
            best_code = code;
            first = false;
        }
        printf("%d", stonks);
        puts("%\n");
    }
    printf("Best option: %d", best_code);
    return 0;
}