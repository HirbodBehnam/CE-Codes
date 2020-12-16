#ifndef QUERA_Q5_H
#define QUERA_Q5_H

#endif //QUERA_Q5_H

#include <stdbool.h>
#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    getchar(); // skip the \n after the number
    for (; n > 0; n--) {
        bool fatemeh_have_odd = false, mohamad_have_even = false, fatemeh_round = true;
        // count the odd and even digits
        char c, digits_total = 0;
        // this counts the input from left to right
        while ((c = getchar()) != '\n' && c != EOF) {
            int digit = c - '0';
            if (fatemeh_round) {
                if (digit % 2 == 1)
                    fatemeh_have_odd = true; // fatemeh can win the round if number of digits is odd
                fatemeh_round = false;
            } else {
                if (digit % 2 == 0)
                    mohamad_have_even = true; // mohamad can win the round if number of digits is even
                fatemeh_round = true;
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
            printf(fatemeh_have_odd ? "1\n" : "2\n");
        else
            printf(mohamad_have_even ? "2\n" : "1\n");
        /**
         * If the count of digits is even, it means that one of the digits from even indexes (mohamad numbers) will be remained at last
         * This means that fatemeh have no control over the game, because in all scenarios, fatemeh have to eliminate all of his numbers
         * So if mohamad have at least one even number it it's numbers (indexes) can win the game by leaving that number as the last number
         */
    }
    return 0;
}