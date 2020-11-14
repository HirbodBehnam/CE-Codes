#ifndef QUERA_Q630_H
#define QUERA_Q630_H

#endif //QUERA_Q630_H

#define MAX_WORDS 1000
#define MAX_WORDS_SIZE 100

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * Compares two strings as the question said
 * @param a First string
 * @param b Second string
 * @return A positive number if a must after before b. Otherwise a negative number. 0 if there is no difference
 */
int compare_string(const char a[], const char b[]) {
    char a1 = a[0], b1 = b[0];
    if (tolower(a1) == tolower(b1)) {
        if (a1 != b1) { // this is for example A and a
            return (int) a1 - (int) b1;
        } else { // for example A and A. We should check the next char if it exists
            char a2 = a[1], b2 = b[1];
            if (a2 == '\0') // a must come after b
                return 1;
            if (b2 == '\0') // b must come after a
                return -1;
            return (int) a2 - (int) b2; // just compare the next char
        }
    } else {
        return tolower(a1) - tolower(b1); // be sure to compare the lowercase chars
    }
}

int main() {
    char words[MAX_WORDS][MAX_WORDS_SIZE];
    int counter = 0;
    // read all data
    while (1) {
        memset(words[counter], 0, sizeof(words[counter]));
        scanf("%s", words[counter]);
        if (strcmp(words[counter], "0") == 0)
            break;
        counter++;
    }
    // sort data with bubble sort for sake of question (do not use prepared sort algorithms)
    for (int i = 0; i < counter - 1; i++)
        for (int j = 0; j < counter - i - 1; j++) {
            if (compare_string(words[j], words[j + 1]) > 0) {
                char temp[MAX_WORDS_SIZE];
                memset(temp, 0, sizeof(temp)); // is this needed?
                strcpy(temp, words[j]);
                strcpy(words[j], words[j + 1]);
                strcpy(words[j + 1], temp);
            }
        }
    // but also you can use qsort to sort the data using quick sort. Just uncomment the line below:
    //qsort(words, counter, MAX_WORDS_SIZE, compare_string);
    // print sorted words
    for (int i = 0; i < counter; i++)
        printf("%s ", words[i]);
    return 0;
}