#ifndef QUERA_Q66867_H
#define QUERA_Q66867_H

#endif //QUERA_Q66867_H

#define MAX_FLOWERS 20

#include <stdio.h>
#include <string.h>

int main() {
    int flowers_count, months;
    scanf("%d %d", &flowers_count, &months);
    int white_occurrences[MAX_FLOWERS]; // count the occurrences for the white flowers. The index is the flower index
    memset(white_occurrences, 0, sizeof(white_occurrences));
    // read months
    for (; months > 0; months--) {
        char status[MAX_FLOWERS];
        scanf("%s", status);
        for (int i = 0; i < flowers_count; i++)
            if (status[i] == 'W') // black flowers does not matter. Only white ones matter
                white_occurrences[i]++;
    }
    // check white occurrences
    for (int i = 0; i < flowers_count; i++)
        if (white_occurrences[i] % 2 == 0) // even occurrences = bad
            putchar('B');
        else
            putchar('F');

    return 0;
}