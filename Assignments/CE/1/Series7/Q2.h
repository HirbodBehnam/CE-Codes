#ifndef QUERA_Q2_H
#define QUERA_Q2_H

#endif //QUERA_Q2_H

#define MAX 10001

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * Reverses an array
 * @param ary The array to reverse
 * @param n The number of elements in array
 */
void reverse_array(char *ary, int n) {
    int begin = 0;
    int end = n - 1;
    while (begin < end) {
        char temp = ary[begin];
        ary[begin] = ary[end];
        ary[end] = temp;
        end--;
        begin++;
    }
}

int main() {
    bool print_mode = true;
    // read the string string
    char string[MAX];
    fgets(string, MAX, stdin);
    string[strlen(string) - 1] = 0; // remove \n
    // read commands
    char command[MAX];
    while (1) {
        fgets(command, MAX, stdin);
        command[strlen(command) - 1] = 0; // remove \n
        switch (command[0]) {
            case 'e': // exit
                return 0;
            case 'p': // print
                puts(string);
                break;
            case 'P': // PRINT_MODE
                print_mode = command[12] == 'N'; // on
                break;
            case 'a': // append
                strcat(string, command + 7); // skip the append + space
                if (print_mode)
                    puts(string);
                break;
            case 'f': // find
            {
                const char *substring = command + 5; // skip the find and space
                char *str = string; // create a copy of pointer
                int count = 0; // number of occurrences
                while ((str = strstr(str, substring)) != NULL) { // move forward until there is no more substrings
                    count++;
                    str++; // skip the substring as well
                }
                // append either number of occurrences or substring
                if (count == 0)
                    strcat(string, substring);
                else {
                    char tmp[10];
                    sprintf(tmp, "%d", count);
                    strcat(string, tmp);
                }
                if (print_mode)
                    puts(string);
            }
                break;
            case 'd': // delete
            {
                const char *substring = command + 7; // skip the delete and space
                int substr_len = strlen(substring);
                char *tmp = string;
                while ((tmp = strstr(tmp, substring)) != NULL) // move forward until there is no more substrings
                    memmove(tmp, tmp + substr_len, strlen(tmp + substr_len) + 1); // + 1 is for null terminator
                if (print_mode)
                    puts(string);
            }
                break;
            case 'r': // reverse
            {
                int n, m;
                if (sscanf(command, "%*s %d,%d", &m, &n) == 2) // reverse all of string
                    reverse_array(string + m, n - m);
                else
                    reverse_array(string, strlen(string));
                if (print_mode)
                    puts(string);
            }
                break;
            case 'c': // copy or count
                if (command[2] == 'p') { // copy
                    int n = 1;
                    sscanf(command, "%*s %d", &n);
                    char tmp[MAX];
                    strcpy(tmp, string);
                    while (n--)
                        strcat(string, tmp);
                } else if (command[2] == 'u') { // count
                    int counter = 0;
                    if (strlen(command) == 7) { // count [char]
                        for (int i = 0; i < strlen(string); i++)
                            if (string[i] == command[6])
                                counter++;
                    } else {
                        if (command[6] == 'a') { // alphabet
                            for (int i = 0; i < strlen(string); i++)
                                if (isalpha(string[i]))
                                    counter++;
                        } else {
                            for (int i = 0; i < strlen(string); i++)
                                if (isdigit(string[i]))
                                    counter++;
                        }
                    }
                    char tmp[10];
                    sprintf(tmp, "%d", counter);
                    strcat(string, tmp);
                }
                if (print_mode)
                    puts(string);
                break;
        }
    }
}