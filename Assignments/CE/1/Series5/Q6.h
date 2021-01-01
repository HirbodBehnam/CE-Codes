#ifndef QUERA_Q6_H
#define QUERA_Q6_H

#endif //QUERA_Q6_H

#include <stdio.h>

/**
 * The strategy to solve this question is this:
 * 1. If the number is odd, we cannot do anything so remove one coin from table
 * 2. If the number is even, check if we half the number we reach an even number again:
 * 2.1. If we reach an even number again, remove one coin from table to make sure enemy also picks one coin from table
 * 2.2. If we reach an odd number, pick half of the coins to ensure that enemy picks one coin
 *
 * But there is a small catch that I don't know why or how:
 * If we reach 4, we must break the algorithm; If we reach 4, we must at first pick the half of it (to get two coins),
 * then the enemy has to pick one coin in either ways. And we pick the last coin to get 3 coins
 */

int main() {
    int n;
    scanf("%d", &n);
    while (n--) {
        unsigned long long sam = 0, number;
        scanf("%llu", &number);
        while (number != 0) {
            // sam
            if (number == 4) {
                sam += 3;
                break;
            }
            if (number % 2 == 1 || (number / 2) % 2 == 0) {
                number--;
                sam++;
            } else {
                sam += number / 2;
                number /= 2;
            }
            if (number == 0) // end of the game
                break;
            // enemy
            if (number == 4) {
                sam++;
                break;
            }
            if (number % 2 == 1 || (number / 2) % 2 == 0)
                number--;
            else
                number /= 2;
        }
        printf("%llu\n", sam);
    }
    return 0;
}