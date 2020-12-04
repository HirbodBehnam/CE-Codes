#ifndef QUERA_Q287_H
#define QUERA_Q287_H

#endif //QUERA_Q287_H

#include <stdbool.h>
#include <stdio.h>

/**
 * Find sums of prime factors of a number. For example 12 is 2+3 = 5
 * @param number The number to find it's prime factors
 * @return The sum of primes
 */
int prime_factors_sum(const int number) {
    // lookup table for primes from 1 to 1000 because why not :D https://byjus.com/maths/prime-numbers/
    const int primes[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89,
                          97, 101, 103, 107, 109, 113, 127, 131, 137, 139, 149, 151, 157, 163, 167, 173, 179, 181, 191,
                          193, 197, 199, 211, 223, 227, 229, 233, 239, 241, 251, 257, 263, 269, 271, 277, 281, 283, 293,
                          307, 311, 313, 317, 331, 337, 347, 349, 353, 359, 367, 373, 379, 383, 389, 397, 401, 409, 419,
                          421, 431, 433, 439, 443, 449, 457, 461, 463, 467, 479, 487, 491, 499, 503, 509, 521, 523, 541,
                          547, 557, 563, 569, 571, 577, 587, 593, 599, 601, 607, 613, 617, 619, 631, 641, 643, 647, 653,
                          659, 661, 673, 677, 683, 691, 701, 709, 719, 727, 733, 739, 743, 751, 757, 761, 769, 773, 787,
                          797, 809, 811, 821, 823, 827, 829, 839, 853, 857, 859, 863, 877, 881, 883, 887, 907, 911, 919,
                          929, 937, 941, 947, 953, 967, 971, 977, 983, 991, 997};
    int sum = 0;
    // 168 is the number of primes in primes array
    for (int i = 0; i < 168; i++) {
        if (number % primes[i] == 0)
            sum += primes[i];
        else if (number < primes[i]) // terminate the loop early if the number is bigger than current prime
            return sum;
    }
    return sum;
}

/**
 * Calculate sum of digits of a number
 * @param number Number to find it's digits
 * @return The sum of digits
 */
int sum_of_digits(int number) {
    int sum = 0;
    while (number != 0) {
        sum += number % 10;
        number /= 10;
    }
    return sum;
}

int main() {
    // get number of tests
    int t;
    scanf("%d", &t);
    for (; t > 0; t--) {
        int n;
        scanf("%d", &n);
        // simple brute force
        bool ok = false;
        for (int i = n - 1; i > 0; i--) { // start from end, because we might reach the answer faster
            if (n == i + sum_of_digits(i) + prime_factors_sum(i)) {
                ok = true;
                break;
            }
        }
        printf(ok ? "Yes\n" : "No\n");
    }
    return 0;
}