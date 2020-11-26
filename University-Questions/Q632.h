#ifndef QUERA_Q632_H
#define QUERA_Q632_H

#endif //QUERA_Q632_H

#define MAX_LENGTH 3003 // two bytes for null terminator and \n and a space

#include <ctype.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

bool punctuation_char(char c) {
    return c == ' ' || c == '!';
}

int main() {
    char input[MAX_LENGTH], to_search[MAX_LENGTH], to_search_reversed[MAX_LENGTH];
    /**
     * I did a small trick. To check the words, I check for space and then start looking next words after spaces
     * However the first word does not have a space before it; So I add one!
     */
    memset(input, 0, sizeof(input));
    fgets(input + 1, MAX_LENGTH, stdin);
    input[0] = ' ';
    int input_len = strlen(input);
    input[input_len] = ' ';
    input[input_len + 1] = 0;
    // read the string to check
    scanf("%s", to_search);
    // Fix to search
    int to_search_len = strlen(to_search);
    for (int i = 0; i < to_search_len; i++) {
        to_search[i] = tolower(to_search[i]);
        to_search_reversed[to_search_len - 1 - i] = to_search[i];
    }
    // Add the space to search values to make it easier to search
    to_search_reversed[to_search_len] = '\0';
    to_search[to_search_len] = '\0';
    // Search
    int counter = 0;
    if (to_search_len > input_len) {
        printf("0");
        return 0;
    }
    // check words of string
    for (int i = 0; i < input_len; i++) {
        if (input[i] == ' ') {
            bool ok = true;
            // check normal
            for (int j = 0; j < to_search_len; j++) {
                if (tolower(input[j + i + 1]) != to_search[j]) {
                    ok = false;
                    break;
                }
            }
            if (ok && punctuation_char(input[i + 1 + to_search_len])) {
                counter++;
                continue;
            }
            // check reversed
            ok = true;
            for (int j = 0; j < to_search_len; j++) {
                if (tolower(input[j + i + 1]) != to_search_reversed[j]) {
                    ok = false;
                    break;
                }
            }
            if (ok && punctuation_char(input[i + 1 + to_search_len]))
                counter++;
        }
    }
    printf("%d", counter);
    return 0;
}