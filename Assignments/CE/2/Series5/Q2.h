#ifndef QUERA_Q2_H
#define QUERA_Q2_H

#endif //QUERA_Q2_H

// 101 chars to include the null terminator
#define MAX_INPUT 101
#define YALDA_LENGTH 5

#include <ctype.h>
#include <stdio.h>

int main() {
    char input[MAX_INPUT];
    const char yalda[] = "yalda";
    gets(input);
    int index = 0;
    int index_of_search = 0;
    char search_char = yalda[0];
    while (input[index] != '\0') {
        if (tolower(input[index]) == search_char) {
            index_of_search++;
            if (index_of_search == YALDA_LENGTH) {
                printf("Yes");
                return 0;
            }
            search_char = yalda[index_of_search];
        }
        index++;
    }
    printf("No");
    return 0;
}