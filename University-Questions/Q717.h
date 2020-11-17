#ifndef QUERA_Q717_H
#define QUERA_Q717_H

#endif //QUERA_Q717_H

#define MAX_COMMAND_SIZE 1000000

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * Simple compare test
 * @param a
 * @param b
 * @return
 */
int compare(const void *a, const void *b) {
    return (*(int *) a - *(int *) b);
}

/**
 * Simple binary search to find the index that "to_insert" must be inserted
 * @param ary The array to search in
 * @param size The size of array
 * @param to_insert The number that must be inserted in array
 * @return The index for insertion
 */
int b_search(const int *ary, int size, int to_insert) {
    if (size == 0)
        return 0;
    // If the number in first index is bigger than the number insert the number in first place
    if (to_insert < ary[0])
        return 0;
    // If the number in last index is smaller than the number insert the number in last place
    if (to_insert > ary[size - 1])
        return size;

    int lo = 0;
    int hi = size - 1;

    while (lo <= hi) {
        const int mid = (hi + lo) / 2;
        if (ary[mid] > to_insert)
            hi = mid - 1;
        else if (ary[mid] < to_insert)
            lo = mid + 1;
        else
            return mid;
    }
    return lo;
}

int main() {
    struct MPQ {
        // elements in the list
        int *elements;
        // size of the list
        int size;
    } sortedSet;
    // initialize list
    sortedSet.elements = malloc(0);
    sortedSet.size = 0;
    // read number of operations
    int t;
    scanf("%d", &t);
    for (; t > 0; t--) {
        char command[MAX_COMMAND_SIZE];
        scanf("%s", command);
        switch (command[0]) {
            case 'b': // build
            {
                int i = 5;
                if (command[i + 1] != ')') { // do not do anything if build is empty
                    while (command[i] != ')') {
                        i++;
                        // classic number parse algorithm
                        int temp = 0;
                        bool negative = false;
                        if (command[i] == '-') {
                            i++;
                            negative = true;
                        }
                        while (command[i] != ',' && command[i] != ')') {
                            temp *= 10;
                            temp += command[i] - '0';
                            i++;
                        }
                        if (negative == true)
                            temp = -temp;
                        // resize the set and insert data in it
                        sortedSet.elements = realloc(sortedSet.elements, (sortedSet.size + 1) * sizeof(int));
                        sortedSet.elements[sortedSet.size] = temp;
                        sortedSet.size++;
                    }
                }
                qsort(sortedSet.elements, sortedSet.size, sizeof(int), compare);
            }
                break;
            case 'r': // remove
            {
                // write data to stdout
                int middle = sortedSet.size / 2;
                if (sortedSet.size % 2 == 0)
                    middle--;
                printf("%d\n", sortedSet.elements[middle]);
                // remove middle element
                memmove(sortedSet.elements + middle, sortedSet.elements + middle + 1,
                        sizeof(int) * (sortedSet.size - middle - 1));
                sortedSet.size--;
                sortedSet.elements = realloc(sortedSet.elements, sortedSet.size * sizeof(int));
            }
                break;
            case 'i': // insert
            {
                int to_insert;
                sscanf(command, "%*[^-0123456789]%d", &to_insert);
                int index = b_search(sortedSet.elements, sortedSet.size, to_insert);
                // move data
                sortedSet.elements = realloc(sortedSet.elements, (sortedSet.size + 1) * sizeof(int));
                memmove(sortedSet.elements + index + 1, sortedSet.elements + index,
                        sizeof(int) * (sortedSet.size - index));
                sortedSet.elements[index] = to_insert;
                sortedSet.size++;
            }
                break;
        }
    }
    return 0;
}