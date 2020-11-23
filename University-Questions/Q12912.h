#ifndef QUERA_Q12912_H
#define QUERA_Q12912_H

#endif //QUERA_Q12912_H

#define MAX_OUTPUT_CHARS 100
#define MAX_ELEMENT_LENGTH 3

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/**
 * The main algorithm here is heavily inspired by https://www.geeksforgeeks.org/powet-set-lexicographic-order/
 * However, working with strings and arrays in C is not that easy, you have to be careful to do not cause memory leak and so much shit
 * So I invented my own method: Use an Int as bitset; It's easy to work with (in terms of passing it to functions) and there is no way
 * you can cause memory leak with it.
 * The plan is this: First bit in int, represents that if '1' must displayed or not; Second bit represents that if '2' must be displayed or not and so on
 * It's a messy code but it works
 */

/**
 * Prints a bitset in format of {a, b, c..., z}
 * If the first bit in bitset is 1, it means that 1 must be in set. If the second bit is 1, it means that 2 must be in set and so on
 * If the number is 0 it means that {} must be printed
 * The reason that I don't instantly print the results into output is that I have to at last remove last two chars ', '
 * @param bitset The bitset to print it
 */
void print_set(unsigned int bitset) {
    // the reason that this condition is separated is that the line to_print[strlen(to_print) - 2] = '\0'; causes run time error because it points to to_print[-1]
    if (bitset == 0) {
        printf("{}\n");
        return;
    }
    // generate the output
    char to_print[MAX_OUTPUT_CHARS];
    memset(to_print, '\0', sizeof(to_print)); // empty the string
    to_print[0] = '{'; // the first char must be {
    int counter = 1; // please not that if we are supposed to read the elements from an array, this must start from 0
    while (bitset != 0) { // if bitset is 0, it means that we are done (no other elements are 1)
        if ((bitset & 1U) == 1) { // check the first bit is 1; This can be simplified to if(bitset & 1U) but I prefer readability
            char digits[MAX_ELEMENT_LENGTH]; // temporary array to do the int to char* conversion
            sprintf(digits, "%d",
                    counter); // convert counter to string and store it in digits; If we were reading from an array this would have been array[counter]
            strcat(to_print, digits); // add digits to 'to_print'
            strcat(to_print, ", ");
        }
        bitset >>= 1U; // shift one to right. This is used to always make the upper if statement read the first bit
        counter++;
    }
    to_print[strlen(to_print) - 2] = '\0'; // remove last two chars which are ', '
    printf("%s}\n", to_print); // print the result with the ending } and a newline
}

/**
 * Generates a bitset of which elements must be written or not
 * Automatically prints the sets in output
 * @param max The number of elements in set
 * @param index The index that now is being seen
 * @param generated The last generated sub-set
 */
void generate(const int max, unsigned int index, unsigned int generated) {
    // do not continue generating if index of current element is max + 1. Note that if it was max, it would've missed the last element in set
    if (max + 1 == index)
        return;

    // print whatever have been generated so far
    print_set(generated);

    for (unsigned int i = index; i < max; i++) {
        generated |= 1U << i; // enable the index of i in the 'generated'
        generate(max, i + 1, generated); // with that index enabled, try to generate other sub-sets
        generated &= ~(1U << i); // disable the index of i in the 'generated'
        // now let the for loop continue and generate sub-sets without "i"th element
    }
}

int main() {
    int n;
    scanf("%d", &n);
    generate(n, 0, 0);
    return 0;
}