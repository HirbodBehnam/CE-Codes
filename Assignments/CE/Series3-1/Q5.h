#ifndef QUERA_Q5_H
#define QUERA_Q5_H

#endif //QUERA_Q5_H

#include <stdio.h>

int run() {
    int n;
    scanf("%d", &n);
    for (; n > 0; n--) {
        int fateme_odd = 0, fateme_even = 0, mohamad_odd = 0, mohamad_even = 0, digits_total = 0;
        unsigned long long input;
        scanf("%llu", &input);
        if(input == 0)
        {
            printf("2\n");
            continue;
        }
        // count the odd and even digits
        {
            char fateme_round = 1;
            while (input != 0) {
                int digit = input % 10;
                if(fateme_round){
                    if(digit % 2 == 0)
                        fateme_even++;
                    else
                        fateme_odd++;
                    fateme_round = 0;
                }else{
                    if(digit % 2 == 0)
                        mohamad_even++;
                    else
                        mohamad_odd++;
                    fateme_round = 1;
                }
                digits_total++;
                input /= 10;
            }
        }
        if(digits_total % 2 == 1){
            printf(fateme_odd > 0 ? "1\n" : "2\n");
        }else{
            printf(mohamad_even > 0 ? "2\n" : "1\n");
        }
    }
    return 0;
}