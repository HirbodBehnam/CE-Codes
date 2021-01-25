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

typedef union e {
    int i;
    char c;
    bool b;
} entry;

typedef struct d {
    entry value;
    char type;
} data;

int n, m, l;

#define INDEX_3D(x, y, z) (((x)*m*l)+((y)*l)+(z))
#define INDEX_2D(x, y) (((x)*m)+(y))

/**
 * Reads from stdin until it reaches a newline char
 */
void read_until_newline() {
    char c;
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
            char c = getchar();
            read_until_newline();
            // save to matrix
            {
                data front;
                front.type = TYPE_BOOL;
                front.value.b = c == 'T';
                *(d + INDEX_3D(counter_n, counter_m, 0)) = front;
            }
            if (c == 'T') {
                int max_so_far = -2147483648, max_ending_here = 0;
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
                (result + INDEX_2D(counter_n, counter_m))->value.i = max_so_far < 0 ? 0 : max_so_far;
                read_until_newline();
            } else {
                char max = 0;
                for (int i = 1; i < l; i++) {
                    char read = getchar();
                    getchar();
                    (d + INDEX_3D(counter_n, counter_m, i))->type = TYPE_CHAR;
                    (d + INDEX_3D(counter_n, counter_m, i))->value.c = read;
                    // check min
                    if (read > max)
                        max = read;
                }
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