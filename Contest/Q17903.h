#ifndef QUERA_Q17903_H
#define QUERA_Q17903_H

#endif //QUERA_Q17903_H

#include <stdio.h>

#define MOD 1000000007

// From https://www.geeksforgeeks.org/compute-ncr-p-set-3-using-fermat-little-theorem/

/**
 * Raises x to power of y, mod MOD
 * @param x The base
 * @param y The power
 * @return x^y % MOD
 */
unsigned long long pow_mod(unsigned long long x, int y) {
    unsigned long long res = 1;
    x %= MOD;
    while (y > 0) {
        if (y & 1)
            res = (res * x) % MOD;
        y = y >> 1;
        x = (x * x) % MOD;
    }
    return res;
}

/**
 * Finds a^-1 mod MOD using fermat little theorem
 * @param a
 * @return a^-1 mod MOD
 */
unsigned long long modInverse(unsigned long long a) {
    return pow_mod(a, MOD - 2);
}

int main() {
    /**
     * The algorithm is to find the (n+1)th row of pascal triangle. Each column is the multiplier of "i"th number.
     * The sign of each each sentence changes everytime
     * For example for n=3 we have:
     * sum = -a+3b-3c+d
     */
    int n;
    scanf("%d", &n);
    long long multiplier = 1, sum = 0; // multiplier is the number in nth row of pascal triangle mod MOD. Sum is the sum of sentences until now
    if (n % 2 == 0)
        multiplier = -1;
    for (int i = 0; i < n; i++) {
        // read the "i"th number
        long long sentence;
        scanf("%lld", &sentence);
        sentence *= multiplier; // multiply the multiplier
        // add to sum
        sum += sentence;
        sum %= MOD;
        /**
         * Fix the multiplier; We must calculate multiplier = (multiplier * (n - i - 1) / (i + 1))
         * If we want to find the mod of that to a prime number, we can use
         * multiplier = ((multiplier * (n - i - 1)) mod MOD) * ((i + 1)^-1 mod MOD) mod MOD
         * (from https://stackoverflow.com/questions/12235110/modulo-of-division-of-two-numbers)
         * To find ((i + 1)^-1 mod MOD) we can use fermat little theorem: https://www.geeksforgeeks.org/multiplicative-inverse-under-modulo-m/
         * Then, just multiply all of the values together
         */
        multiplier = ((multiplier * ((n - i - 1) % MOD)) % MOD) * (long long) (modInverse(i + 1) % MOD);
        multiplier %= MOD;
        multiplier *= -1; // swap sign
    }
    // positive modulo
    printf("%lld", (sum % MOD + MOD) % MOD);
    return 0;
}
