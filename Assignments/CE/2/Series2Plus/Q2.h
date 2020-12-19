#ifndef QUERA_Q2_H
#define QUERA_Q2_H

#endif //QUERA_Q2_H

#include <stdio.h>

int main() {
    int price, count;
    scanf("%d %d", &price, &count);
    int primes_numbers = 0;
    for(int candidate = 2; candidate < price; candidate++){
        if (candidate == 2 || candidate == 3 || candidate == 5 || candidate == 7) { // these are prime numbers
            primes_numbers++;
        } else {
            char prime = 1;
            if (candidate % 2 == 0 || candidate % 3 == 0 || candidate == 1) { // 1 is not prime :D (looks like test 1 needs this)
                prime = 0;
            } else {
                const unsigned long long To = candidate /
                                              2; // the correct number is sqrt(number); But since we cannot use functions, I use number / 2
                // we guess that number is prime at first
                for (unsigned long long i = 5; i <= To; i += 4) { // check 6k+-1
                    if (candidate % i == 0) // 6k - 1
                    {
                        prime = 0;
                        //break; // I'm not sure if we can use break or not so I comment it out just in case
                    }
                    i += 2;
                    if (candidate % i == 0) // 6k + 1
                    {
                        prime = 0;
                        //break; // I'm not sure if we can use break or not so I comment it out just in case
                    }
                }
            }
            if (prime == 1)
                primes_numbers++;
        }
    }
    printf("%d", primes_numbers * count);
    return 0;
}