#ifndef QUERA_Q1_H
#define QUERA_Q1_H

#endif //QUERA_Q1_H

#define MAX 1000
#define MASTER_LENGTH (7 + 10 + 28 + 28 + 1)

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *master;

int index_in_master(char c) {
    for (int i = 0; i < MASTER_LENGTH; i++)
        if (master[i] == c)
            return i;
    return -1;
}

int cmp(const void *a, const void *b) {
    const char *first = *(char **) a;
    const char *second = *(char **) b;
    int a_index = 0, b_index = 0;
    const int a_len = strlen(first), b_len = strlen(second);
    while (a_index < a_len && b_index < b_len) {
        int a_char = index_in_master(first[a_index]);
        if (a_char == -1) {
            a_index++;
            continue;
        }
        int b_char = index_in_master(second[b_index]);
        if (b_char == -1) {
            b_index++;
            continue;
        }
        // check not equal
        if (a_char != b_char)
            return a_char - b_char;
        a_index++;
        b_index++;
    }
    // find lengths without special chars
    int a_fixed_len = 0, b_fixed_len = 0;
    for (int i = 0; i < a_len; i++)
        if (index_in_master(first[i]) >= 0)
            a_fixed_len++;
    for (int i = 0; i < b_len; i++)
        if (index_in_master(second[i]) >= 0)
            b_fixed_len++;
    return a_fixed_len - b_fixed_len; // compare lengths
}

int main() {
    int n;
    scanf("%d\n", &n);
    // read inputs
    char **strings = malloc(n * sizeof(char *));
    for (int i = 0; i < n; i++) {
        char *tmp = malloc(MAX * sizeof(char));
        fgets(tmp, MAX, stdin);
        if (tmp[strlen(tmp) - 1] == '\n')
            tmp[strlen(tmp) - 1] = 0; // remove \n
        strings[i] = tmp;
    }
    // create master
    master = malloc(MASTER_LENGTH * sizeof(char));
    strcpy(master, "_-!@()%");
    strcat(master, "0123456789");
    strcat(master, "ABCDEFGHIJKLMNOPQRSTUVWXYZ");
    strcat(master, "abcdefghijklmnopqrstuvwxyz");
    // sort
    qsort(strings, n, sizeof(char *), cmp);
    // print
    for (int i = 0; i < n; i++)
        puts(strings[i]);
    return 0;
}