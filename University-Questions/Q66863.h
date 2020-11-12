#ifndef QUERA_Q66863_H
#define QUERA_Q66863_H

#endif //QUERA_Q66863_H

#define PRIME_TOTAL 5 * 1000 * 1000

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

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
    bool res = true;
    for(counter = 0; counter < len / 2; counter++)
        if(result[counter] != result[len - counter - 1]){
            res = false;
            break;
        }
    return res;
}

int run(){
    int base, n;
    scanf("%d %d",&n, &base);
    int counter = 0; // count the number of "khafan" numbers
    // no need to calculate 2 and 3 in seive
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
    /*
     * If start skipping is set to true, the program will explicitly start skipping the elimination
     * The reason that this variables is required is that if there is not such variable and the program executes continue
     * when i * i > length. This statement fails when i * i overflows the int thus i * i results in a negative value and statement turns true.
     */
    bool start_skipping = false;
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
            // end the loop (does not happen)
            if (!start_skipping && i * i <= length){
                // eliminate other non-primes
                j = 2;
                do{
                    candidates[j * i] = 1;
                    j++;
                } while (j * i < length);
            }else
                start_skipping = true;

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
            // end the loop (does not happen)
            if (!start_skipping && i * i <= length){
                // eliminate other non-primes
                j = 2;
                do{
                    candidates[j * i] = 1;
                    j++;
                } while (j * i < length);
            }else
                start_skipping = true;
        }
    }
}