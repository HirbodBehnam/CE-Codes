#ifndef QUERA_Q291_H
#define QUERA_Q291_H

#endif //QUERA_Q291_H

#define MAX_STRING_LENGTH 50

#include <stdbool.h>
#include <stdio.h>
#include <string.h>

/**
 * Checks if a string contains a substring or reverse of it
 * @param init The string to search in
 * @param to_check The string to check
 * @param reversed_to_check The reversed string to check
 * @return True if contains at least one of them
 */
bool contains_substring(const char *init, const char *to_check, const char *reversed_to_check) {
    return strstr(init, to_check) != NULL || strstr(init, reversed_to_check) != NULL; // I didn't know C had these :|
}

int main() {
    int n;
    scanf("%d", &n);
    char input[n][MAX_STRING_LENGTH];
    // read the input
    for (int i = 0; i < n; i++)
        scanf("%s", input[i]);
    // now check the substrings
    int first_len = strlen(input[0]), best_length = 0;
    char best[MAX_STRING_LENGTH];
    for (int i = 0; i < first_len; i++) {
        for (int j = i + 1; j <= first_len; j++) {
            int substring_len = j - i;
            if (substring_len <= best_length) // choose first substring
                continue;
            // create the substring
            char substring[substring_len + 1], substring_reversed[substring_len + 1];
            substring[substring_len] = substring_reversed[substring_len] = 0; // null terminator
            // fill the substring
            for (int index = i, counter = 0; index < j; index++, counter++) {
                substring[counter] = input[0][index];
                substring_reversed[substring_len - counter - 1] = input[0][index];
            }
            // check each string
            bool ok = true;
            for (int string_number = 1; string_number < n; string_number++) {
                if (!contains_substring(input[string_number], substring, substring_reversed)) {
                    ok = false;
                    break;
                }
            }
            // set the substring
            if (ok) {
                strcpy(best, substring);
                best_length = substring_len;
            }
        }
    }
    printf("%s", best);
    return 0;
}