#ifndef QUERA_MIDTERM_H
#define QUERA_MIDTERM_H

#endif //QUERA_MIDTERM_H

#include <stdio.h>

/**
 * Circular shifts a part of a number
 * One thing: Why the results must be 32 bits? It should
 * @param n The number
 * @param bytes Number of bytes to cycle
 * @param bits Number of bits to shift
 * @param dir Direction of shift
 * @return
 */
unsigned long int circular_shift(unsigned long int n, char bytes, char bits, char dir) {
    bits %= bytes * 8; // make the bits smaller than total bits that we want to shift
    if (bytes == 4) { // just normal shift
        if (dir == 'R') {
            return (n >> bits) | (n << (32 - bits)); // somehow this part of code is wrong?
        } else {
            return (n << bits) | (n >> (32 - bits));
        }
    }
    if (bytes == 2) {
        unsigned short small = n; // this is here to get the first 2 bytes of number
        if (dir == 'R') {
            small = (small >> bits) | (small << (16 - bits)); // short is 16 bits
        } else {
            small = (small << bits) | (small >> (16 - bits));
        }
        n &= 4294901760; // 11111111111111110000000000000000: Turn off the first 16 bits
        n |= small; // turn on the bits that is needed
        return n;
    } else {
        // bytes == 1
        unsigned char small = n;  // this is here to get the first byte of number
        if (dir == 'R') {
            small = (small >> bits) | (small << (8 - bits)); // char is 8 bits
        } else {
            small = (small << bits) | (small >> (8 - bits));
        }
        n &= 4294967040; // 11111111111111111111111100000000: Turn off the first 8 bits
        n |= small; // turn on the bits that is needed
        return n;
    }
}

int main() {
    unsigned long int n;
    int bytes, bit;
    char dir;
    scanf("%lu\n%d\n%d\n%c", &n, &bytes, &bit, &dir);
    printf("%u", circular_shift(n, bytes, bit, dir)); // we should print this as unsigned 32 bit number
    return 0;
}
