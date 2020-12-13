#ifndef QUERA_Q634_H
#define QUERA_Q634_H

#endif //QUERA_Q634_H

#define MAX_LINE 2000

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * Checks if a char is a vowel
 * Vowels are a-e-i-o-u-y
 * @param c The char to check
 * @return True if vowel
 */
bool is_vowel(int c) {
    c = tolower(c);
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'y';
}

int main() {
    while (1) {
        char line[MAX_LINE];
        if (fgets(line, MAX_LINE, stdin) == NULL)
            break;

        int line_len = strlen(line);
        int no_vowel_counter = 0;
        for (int i = 0; i < line_len; i++) {
            if (is_vowel(line[i]) || !isalpha(line[i])) {
                no_vowel_counter = 0;
            } else {
                no_vowel_counter++;
                if (no_vowel_counter == 5) {
                    // find the first index of word
                    int first_index;
                    bool uppercase_word = true;
                    for (first_index = i - 4;; first_index--) {
                        if (!isalpha(line[first_index]))
                            break;
                        if (!isupper(line[first_index]))
                            uppercase_word = false;
                    }
                    if (uppercase_word)
                        continue;
                    // now print until next word
                    while (1) {
                        first_index++;
                        if (!isalpha(line[first_index]))
                            break;
                        putchar(line[first_index]);
                    }
                    putchar(' ');
                    // move the cursor to next word
                    i = first_index;
                    no_vowel_counter = 0;
                }
            }
        }
    }
    return 0;
}