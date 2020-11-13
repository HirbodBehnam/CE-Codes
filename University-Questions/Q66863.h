#ifndef QUERA_Q66863_H
#define QUERA_Q66863_H

#endif //QUERA_Q66863_H

#define PRIME_TOTAL 5 * 1000 * 1000

#include <math.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

/**
 * Checks if a number is palindrome is a specific base
 * @param number The number to check
 * @param to_base The base to convert to
 * @return True if the number is palindrome otherwise false
 */
bool check_base_convert(long number, int to_base){
    char letters[] = "0123456789ABCDEF";
    char result[64];
    memset(result, 0, sizeof(result));
    int counter = 0;
    while (number >= to_base){
        result[counter] = letters[number % to_base];
        number /= to_base;
        counter++;
    }
    result[counter] = letters[number]; // the last digit
    // check if reversed string is same as normal one
    unsigned long len = strlen(result);
    for(counter = 0; counter < len / 2; counter++)
        if(result[counter] != result[len - counter - 1])
            return false;

    return true;
}

int main(){
    int base, n;
    scanf("%d %d",&n, &base);
    int counter = 0; // count the number of "khafan" numbers
    // no need to calculate 2 and 3 in sieve
    // so check them now
    if(check_base_convert(2,base)){
        counter++;
        if(counter == n){
            printf("2");
            return 0;
        }
    }
    if(check_base_convert(3,base)){
        counter++;
        if(counter == n){
            printf("3");
            return 0;
        }
    }
    // do sieve
    char* candidates = malloc(PRIME_TOTAL * sizeof(char));
    memset(candidates, 0, PRIME_TOTAL * sizeof(char));
    int length = PRIME_TOTAL + 1;
    const int To = (int)sqrt((double)length);
    int i;
    for (i = 5; ; i += 4) // only check 6k +- 1
    {
        int j;
        if (candidates[i] == 0)
        {
            // check prime
            if(check_base_convert(i,base)){
                counter++;
                if(counter == n){
                    printf("%d", i);
                    return 0;
                }
            }
            // check if eliminating candidates is needed
            if (i <= To) {
                // eliminate other non-primes
                j = 2;
                do {
                    candidates[j * i] = 1;
                    j++;
                } while (j * i < length);
            }

        }
        i += 2;
        if (candidates[i] == 0)
        {
            // check prime
            if(check_base_convert(i,base)){
                counter++;
                if(counter == n){
                    printf("%d", i);
                    return 0;
                }
            }
            // check if eliminating candidates is needed
            if (i <= To) {
                // eliminate other non-primes
                j = 2;
                do {
                    candidates[j * i] = 1;
                    j++;
                } while (j * i < length);
            }
        }
    }
}