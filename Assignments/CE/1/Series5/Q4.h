#ifndef QUERA_Q4_H
#define QUERA_Q4_H

#endif //QUERA_Q4_H

/**
 * Max uint32 value
 */
#define UINT32_MAX 0xFFFFFFFFU
/**
 * Message that must be repeated
 */
#define MESSAGE_INITIAL 0b01110110010011110110011101100111

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int n;
    scanf("%d\n", &n);
    n /= 32; // now n is the number of ints
    unsigned int *message = malloc(n * sizeof(unsigned int)); // create the message array on heap
    for (int i = 0; i < n; i++)
        message[i] = MESSAGE_INITIAL; // fill it
    while (1) {
        char command;
        scanf("%c%*s", &command);
        if (command == 'K')
            break;
        if (command == 'A') { // attack
            int a, b, c;
            scanf("%d %d %d\n", &a, &b, &c);
            a--;
            b--;
            if (a / 32 == b / 32) {
                // a mask that in the end would like 0..01..10..0
                unsigned int mask = UINT32_MAX;
                mask &= ((1ULL << (32 - (a % 32))) - 1); // fix left hand
                mask &= ~((1ULL << (31 - (b % 32))) - 1); // fix right hand
                if (c == 0)
                    message[a / 32] &= ~mask; // we should disable the bits; NOT the mask and 'and' it
                else
                    message[a / 32] |= mask; // we should enable the bits in mask
            } else {
                if (c == 0) {
                    // make whole numbers in between zero (turn all bits to 0)
                    for (int i = (a + 32 - 1) / 32; i < (b / 32); i++)
                        message[i] = 0;
                    message[a / 32] &= ~((1ULL << (32 - (a % 32))) - 1); // fix first of interval
                    message[b / 32] &= ((1ULL << (31 - (b % 32))) - 1); // fix last of interval
                } else {
                    // turn all bits of numbers in between to 1
                    for (int i = (a + 32 - 1) / 32; i < (b / 32); i++)
                        message[i] = UINT32_MAX;
                    message[a / 32] |= ((1ULL << (32 - (a % 32))) - 1); // fix first of interval
                    message[b / 32] |= ~((1ULL << (31 - (b % 32))) - 1); // fix last of interval
                }
            }
        } else { // get
            int a, b;
            scanf("%d %d\n", &a, &b);
            a--; // for example if a is 1, we should start from zero
            do {
                // get bits one by one
                putchar((char) ((message[a / 32] >> (unsigned int) (31 - a % 32)) & 1U) + '0');
                a++;
            } while (a != b);
            putchar('\n');
        }
    }
    return 0;
}