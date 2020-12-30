#ifndef QUERA_Q1_H
#define QUERA_Q1_H

#endif //QUERA_Q1_H

#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    printf("1\n"); // first row
    int before_row[n], now_row[n + 1];
    // initialize the now_row
    now_row[0] = now_row[1] = before_row[0] = 1;
    before_row[1] = 0;
    for(int i = 2; i <= n; i++)
        now_row[i] = before_row[i] = 0;
    // print the triangle
    for (int i = 1; i < n; i++) {
        // print the row
        for (int j = 0; j < i; j++)
            printf("%d\t", now_row[j]);
        printf("1\n"); // one must be printed at last
        // copy from now to before
        for (int j = 0; j <= i; j++)
            before_row[j] = now_row[j];
        // create the next row
        for (int j = 1; j <= i + 1; j++) // to i + 1 for last element
            now_row[j] = before_row[j] + before_row[j - 1];
    }
    return 0;
}