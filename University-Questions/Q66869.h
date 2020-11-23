#ifndef QUERA_Q66869_H
#define QUERA_Q66869_H

#endif //QUERA_Q66869_H

#include <stdio.h>

/**
 * This code is also heavily inspired by a geeksforgeeks article
 * Is this code, just like Q12912, I used an int that its bits represents if that elements of the set must included in output or not
 */

/**
 * Prints the
 * @param bitset
 */
void print_set(unsigned int bitset) {
    printf("{ ");
    int counter = 1;
    while (bitset != 0) {
        if ((bitset & 1U) == 1) // check the first bit is 1; This can be simplified to if(bitset & 1U) but I prefer readability
            printf("%d ", counter); // print the counter with a space after it
        bitset >>= 1U; // shift one to right. This is used to always make the upper if statement read the first bit
        counter++;
    }
    printf("}\n");
}

/**
 * Generates sub-sets for the main set
 * The algorithm here is that at first include the "index"th element. Then recruits call the generate again
 * After it's done, now call the generate again without including the "index"th element.
 * Print and return as soon as max == index (the have included or excluded all elements)
 * @param max The number of elements in main set
 * @param index The index that we are working on now
 * @param generated The last generated subset
 */
void generate(const unsigned int max, unsigned int index, unsigned int generated) {
    if (index == max) { // we have included or excluded are elements from main set
        print_set(generated);
        return;
    }

    generate(max, index + 1, generated | (1U << index)); // include the "index"th element; The or operator changes the "index"th element (counting from 0) to one
    generate(max, index + 1, generated); // do not include the "index"th element
}

int main() {
    int n;
    scanf("%d", &n);
    generate(n, 0, 0);
    return 0;
}