#ifndef QUERA_MIDTERM2_H
#define QUERA_MIDTERM2_H

#endif //QUERA_MIDTERM2_H

#include <stdio.h>

/**
 * Circular shifts a part of number
 * @param L The starting number
 * @param i The first index to start shifting
 * @param j The last index to end the shifting
 * @param bits Number of bits to shift
 * @param dir Direction of shift
 * @return The shifted number
 */
unsigned int shift(unsigned int L, unsigned char i, unsigned char j, char bits, char dir) {
    bits %= j - i + 1;
    unsigned int extracted_bits = 0;
    // extract all bits and zero them
    unsigned int bit_counter = 0;
    for (unsigned int bit = i; bit <= j; bit++) {
        extracted_bits |= ((L >> bit) & 1U) << bit_counter; // extract the bit and store it in the extracted_bits
        bit_counter++;
        L &= ~(1U << bit); // zero that bit in number
    }
    // rotate the extracted_bits, bits times
    if (dir == 'R') {
        extracted_bits = (extracted_bits >> bits) | (extracted_bits << (bit_counter - bits));
    } else {
        extracted_bits = (extracted_bits << bits) | (extracted_bits >> (bit_counter - bits));
    }
    // remove last bits
    if (bit_counter != 32) // if the bit counter is 32, we will zero the whole extracted bits
        extracted_bits &= (1U << bit_counter) - 1;
    // mask it
    extracted_bits <<= i; // shift back to position
    L |= extracted_bits; // turn on the bits
    return L;
}

int main() {
    unsigned int n;
    int bit_start, bit_end, bits;
    char dir;
    scanf("%u\n%d\n%d\n%d\n%c", &n, &bit_start, &bit_end, &bits, &dir);
    printf("%u", shift(n, (char) bit_start, (char) bit_end, (char) bits, dir));
    return 0;
}