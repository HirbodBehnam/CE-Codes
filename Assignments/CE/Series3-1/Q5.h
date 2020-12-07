#ifndef QUERA_Q5_H
#define QUERA_Q5_H

#endif //QUERA_Q5_H

#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    getchar(); // skip the \n after the number
    for (; n > 0; n--) {
        char fatemeh_have_odd = 0, mohamad_have_even = 0, digits_total = 0;
        // count the odd and even digits
        char c, fatemeh_round = 1;
        // this counts the input from left to right
        while ((c = getchar()) != '\n' && c != EOF) {
            int digit = c - '0';
            if (fatemeh_round) {
                if (digit % 2 == 1)
                    fatemeh_have_odd = 1; // fatemeh can win the round if number of digits is odd
                fatemeh_round = 0;
            } else {
                if (digit % 2 == 0)
                    mohamad_have_even = 1; // mohamad can win the round if number of digits is even
                fatemeh_round = 1;
            }
            digits_total++;
        }
        /**
         * So what is the algorithm for this?
         * If the count of digits is odd, it means that one of the digits from odd indexes (fatemeh numbers) will be remained at last
         * This means that mohamad have no control over the game, because in all scenarios, mohamad have to eliminate all of his numbers
         * So if fatemeh have at least one odd number it it's numbers (indexes) can win the game by leaving that number as the last number
         */
        if (digits_total % 2 == 1)
            printf(fatemeh_have_odd > 0 ? "1\n" : "2\n");
        else
            printf(mohamad_have_even > 0 ? "2\n" : "1\n");
        /**
         * If the count of digits is even, it means that one of the digits from even indexes (mohamad numbers) will be remained at last
         * This means that fatemeh have no control over the game, because in all scenarios, fatemeh have to eliminate all of his numbers
         * So if mohamad have at least one even number it it's numbers (indexes) can win the game by leaving that number as the last number
         */
    }
    return 0;
}