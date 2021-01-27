#ifndef QUERA_Q4_H
#define QUERA_Q4_H

#endif //QUERA_Q4_H

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define TYPE_BOOL 0
#define TYPE_CHAR 1
#define TYPE_INT 2

#define MAX_LINE 250

/**
 * This union can contain all of the data types needed to be stored
 */
typedef union e {
    int i;
    char c;
    bool b;
} entry;

/**
 * A variable data type that can be either int, char or bool
 */
typedef struct d {
    /**
     * The value
     */
    entry value;
    /**
     * The value type from TYPE_BOOL or TYPE_CHAR or TYPE_INT
     */
    char type;
} data;

int n, m, l;

/**
 * Macro to get the element in 3d array (used for input matrix)
 */
#define INDEX_3D(x, y, z) (((x)*m*l)+((y)*l)+(z))
/**
 * Macro to get element in 2d array (used for final matrix)
 */
#define INDEX_2D(x, y) (((x)*m)+(y))

/**
 * Reads from stdin until it reaches a newline char
 */
void read_until_newline() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int main() {
    scanf("%d %d %d", &n, &m, &l);
    read_until_newline();
    l++;
    data *d = malloc(n * m * l * sizeof(data));
    data *result = malloc(n * m * sizeof(data));
    for (int counter_n = 0; counter_n < n; counter_n++) {
        for (int counter_m = 0; counter_m < m; counter_m++) {
            char c = getchar(); // read the bool from first char
            read_until_newline();
            // save in result matrix
            {
                data front;
                front.type = TYPE_BOOL;
                front.value.b = c == 'T';
                *(d + INDEX_3D(counter_n, counter_m, 0)) = front;
            }
            if (c == 'T') {
                int max_so_far = 0, max_ending_here = 0;
                for (int i = 1; i < l; i++) {
                    (d + INDEX_3D(counter_n, counter_m, i))->type = TYPE_INT;
                    scanf("%d", &(d + INDEX_3D(counter_n, counter_m, i))->value.i);
                    // set max
                    max_ending_here += (d + INDEX_3D(counter_n, counter_m, i))->value.i;
                    if (max_so_far < max_ending_here)
                        max_so_far = max_ending_here;

                    if (max_ending_here < 0)
                        max_ending_here = 0;
                }
                (result + INDEX_2D(counter_n, counter_m))->type = TYPE_INT;
                (result + INDEX_2D(counter_n, counter_m))->value.i = max_so_far;
                read_until_newline();
            } else if (c == 'F') {
                char *line = malloc(MAX_LINE * sizeof(char));
                fgets(line, MAX_LINE * sizeof(line), stdin); // use fgets; Apparently, using getchar fucks up everything
                char max = 0; // the largest char
                for (int i = 1; i < l; i++) {
                    char read = *(line + 2 * i - 2); // chars in index of 0, 2, 4 ...
                    (d + INDEX_3D(counter_n, counter_m, i))->type = TYPE_CHAR;
                    (d + INDEX_3D(counter_n, counter_m, i))->value.c = read;
                    // check max
                    if (read > max)
                        max = read;
                }
                free(line);
                // update result array
                (result + INDEX_2D(counter_n, counter_m))->type = TYPE_CHAR;
                (result + INDEX_2D(counter_n, counter_m))->value.c = max;
            }
        }
    }
    // print result
    for (int counter_n = 0; counter_n < n; counter_n++) {
        for (int counter_m = 0; counter_m < m; counter_m++) {
            switch ((result + INDEX_2D(counter_n, counter_m))->type) {
                case TYPE_CHAR:
                    printf("%c ", tolower((result + INDEX_2D(counter_n, counter_m))->value.c));
                    break;
                case TYPE_INT:
                    printf("%d ", (result + INDEX_2D(counter_n, counter_m))->value.i);
                    break;
            }
        }
        putchar('\n');
    }
    return 0;
}