#ifndef QUERA_Q3_H
#define QUERA_Q3_H

#endif //QUERA_Q3_H

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

/**
 * A struct to contain each entry of competition (?)
 */
typedef struct e {
    /**
     * The number which the user has participated with
     */
    int number;
    /**
     * The id of user
     */
    int id;
} entry;

/**
 * A function to sort these structs by their number
 * @param a First struct
 * @param b Second struct
 * @return
 */
int cmp(const void *a, const void *b) {
    return (((entry *) a)->number - ((entry *) b)->number);
}

int main() {
    // all entries will be hold here
    entry *entries = malloc(0);
    // number of entries
    int counter = 0;
    while (1) {
        entry e;
        scanf("%d", &e.id);
        if (e.id == -1) // read until -1
            break;
        scanf("%d", &e.number);
        // put the entry in memory
        counter++;
        entries = realloc(entries, counter * sizeof(entry));
        *(entries + counter - 1) = e;
    }
    /*
     * Add a helper value.
     * Why? If we only and only enter one value the first if the next for loop will check entries[i] and entries[i+1]
     * If there is only one element in array, this will probably cause a runtime error and thus crash the program
     * To fix this problem, I use a helper value at the very end of array
     * I create another entry with (-1, -1) values in it and I won't update the counter.
     * So in the for loop and qsort the last element wont be effected
     */
    {
        // do not update counter
        entries = realloc(entries, (counter + 1) * sizeof(entry));
        (entries + counter)->number = -1;
        (entries + counter)->id = -1;
    }
    // sort data
    qsort(entries, counter, sizeof(entry), cmp);
    // check for the smallest number
    for (int i = 0; i < counter; i++) {
        if ((entries + i)->number == (entries + i + 1)->number) {
            // if here is reached, move 'i' until we reach another value
            // this algorithm is so messy, I don't know if there is better way
            i++;
            while (i < counter && (entries + i)->number == (entries + i - 1)->number)
                i++;
            i--; // put i-- to neutralize i++
        } else {
            // check for cheat
            // the array is not sorted according to id so linear search is it
            for (int j = 0; j < counter; j++) {
                if ((entries + i)->id == (entries + j)->id && i != j) {
                    printf("%d cheated.", (entries + i)->id);
                    return 0;
                }
            }
            // no cheat
            printf("%d won.", (entries + i)->id);
            return 0;
        }
    }
    // exiting the for loop means that no one won
    printf("no one won.");
    return 0;
}