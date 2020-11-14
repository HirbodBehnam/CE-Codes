#ifndef QUERA_Q655_H
#define QUERA_Q655_H

#endif //QUERA_Q655_H

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int run() {
    int n;
    bool whitespace; // true if the string is now in whitespace. The next non-whitespace char must be uppercase
    scanf("%d", &n);
    char *name = malloc(sizeof(char) * 1000); // no need for calloc. We must reset this array everytime in the for loop
    for (; n >= 0; n--) {
        memset(name, 0, sizeof(char) * 1000); // clear the last input
        fgets(name, 1000, stdin);
        unsigned long len = strlen(name);
        if (len != 0) { // im not sure if this is even needed
            // upper case the first letter
            name[0] = toupper(name[0]);
            // check all other letters
            whitespace = false;
            for (int i = 1; i < len; i++) {
                if (whitespace) // the next char must be uppercase
                    name[i] = toupper(name[i]);
                else // the char must be lowercase
                    name[i] = tolower(name[i]);
                // update whitespace mode
                whitespace = name[i] == ' ';
            }
        }
        printf("%s\n", name);

    }
    return 0;
}