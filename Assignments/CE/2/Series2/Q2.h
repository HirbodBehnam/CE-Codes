#ifndef QUERA_Q2_H
#define QUERA_Q2_H

#endif //QUERA_Q2_H

#include <stdio.h>

int main() {
    unsigned long long number;
    scanf("%llu", &number);
    // calculate the sum of digits
    unsigned long long sum_of_digits = 0, temp = number;
    while (temp > 0) {
        sum_of_digits += temp % 10;
        temp /= 10;
    }
    // now find primes
    while (sum_of_digits > 0) {
        // small algorithm to check prime number
        if (number == 2 || number == 3 || number == 5 || number == 7) { // these are prime numbers
            sum_of_digits--;
        } else {
            char prime = 1;
            if (number % 2 == 0 || number % 3 == 0 || number == 1) { // 1 is not prime :D (looks like test 1 needs this)
                prime = 0;
            } else {
                const unsigned long long To = number /
                                              2; // the correct number is sqrt(number); But since we cannot use functions, I use number / 2
                // we guess that number is prime at first
                for (unsigned long long i = 5; i <= To; i += 4) { // check 6k+-1
                    if (number % i == 0) // 6k - 1
                    {
                        prime = 0;
                        //break; // I'm not sure if we can use break or not so I comment it out just in case
                    }
                    i += 2;
                    if (number % i == 0) // 6k + 1
                    {
                        prime = 0;
                        //break; // I'm not sure if we can use break or not so I comment it out just in case
                    }
                }
            }
            if (prime == 1)
                sum_of_digits--;
        }
        number++;
    }
    // print number
    printf("%llu", number - 1);
    return 0;
}