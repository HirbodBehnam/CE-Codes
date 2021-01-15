#ifndef QUERA_Q5_H
#define QUERA_Q5_H

#endif //QUERA_Q5_H

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define TYPE_FLOAT 0
#define TYPE_INT 1
#define TYPE_CHAR 2
#define TYPE_BOOL 3

/**
 * A value with unknown type
 */
typedef union variables {
    double f;
    long long i;
    char c;
    bool b;
} var_type;

/**
 *
 */
typedef struct variable {
    /**
     * The value it self
     */
    var_type value;
    /**
     * Type of the value
     */
    char type;
} var;

/**
 * Prints the value to stdout when adding to database
 * @param value The value to print
 * @param index The index which is added in
 */
void print_var_added(var value, int index) {
    switch (value.type) {
        case TYPE_FLOAT:
            printf("Float %.6lf", value.value.f);
            break;
        case TYPE_INT:
            printf("Integer %lld", value.value.i);
            break;
        case TYPE_CHAR:
            printf("Character %c", value.value.c);
            break;
        case TYPE_BOOL:
            printf("Boolean %s", value.value.b ? "True" : "False");
            break;
    }
    printf(" is in index %d\n", index);
}

/**
 * Prints variable formatted for "print-all" command
 * @param value Value to
 * @param index
 */
void print_var_all(var value, int index) {
    printf("%d: ", index);
    switch (value.type) {
        case TYPE_FLOAT:
            printf("Float - %.6lf", value.value.f);
            break;
        case TYPE_INT:
            printf("Integer - %lld", value.value.i);
            break;
        case TYPE_CHAR:
            printf("Character - %c", value.value.c);
            break;
        case TYPE_BOOL:
            printf("Boolean - %s", value.value.b ? "True" : "False");
            break;
    }
    printf("\n");
}

/**
 * Reads from stdin until it reaches a newline char
 */
void read_until_newline() {
    while (getchar() != '\n');
}

int main() {
    var *variables = malloc(0);
    int size = 0;
    while (1) {
        char r = getchar();
        if (r == 'o') // out; exit the app
            break;
        read_until_newline();
        switch (r) {
            case 'a': // access
            {
                int index;
                scanf("%d", &index);
                read_until_newline();
                if (index >= size || index < 0)
                    puts("Out of Boundaries");
                else
                    print_var_added(*(variables + index), index);
            }
                break;
            case 'b': // bool
            {
                int b;
                scanf("%d", &b);
                read_until_newline();
                size++;
                variables = realloc(variables, size * sizeof(var));
                (variables + size - 1)->type = TYPE_BOOL;
                (variables + size - 1)->value.b = b;
                printf("Boolean %s added to index %d\n", b ? "True" : "False", size - 1);
            }
                break;
            case 'c': // char
            {
                char c = getchar();
                read_until_newline();
                size++;
                variables = realloc(variables, size * sizeof(var));
                (variables + size - 1)->type = TYPE_CHAR;
                (variables + size - 1)->value.c = c;
                printf("Character %c added to index %d\n", c, size - 1);
            }
                break;
            case 'f': // float
            {
                double f;
                scanf("%lf", &f);
                read_until_newline();
                size++;
                variables = realloc(variables, size * sizeof(var));
                (variables + size - 1)->type = TYPE_FLOAT;
                (variables + size - 1)->value.f = f;
                printf("Float %.6lf added to index %d\n", f, size - 1);
            }
                break;
            case 'i': // int
            {
                long long i;
                scanf("%lld", &i);
                read_until_newline();
                size++;
                variables = realloc(variables, size * sizeof(var));
                (variables + size - 1)->type = TYPE_INT;
                (variables + size - 1)->value.i = i;
                printf("Integer %lld added to index %d\n", i, size - 1);
            }
                break;
            case 'e':
                size = 0;
                puts("All Data Has Been Cleared...");
                break;
            case 'p':
                if (size == 0)
                    puts("Nothing Exists...");
                else
                    for (int i = 0; i < size; i++)
                        print_var_all(*(variables + i), i);
                break;
        }
    }
    return 0;
}