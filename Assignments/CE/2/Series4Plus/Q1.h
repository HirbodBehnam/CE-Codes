#ifndef QUERA_Q1_H
#define QUERA_Q1_H

#endif //QUERA_Q1_H

#define MAX 50
#include <stdio.h>

int main(){
    int n;
    scanf("%d", &n);
    int top[MAX][MAX], bottom[MAX][MAX];
    // empty the rows
    for(int i = 0; i < MAX; i++)
        for(int j = 0; j < MAX; j++)
            top[i][j] = bottom[i][j] = 0;
    // set the first ones
    top[0][0] = 1;
    bottom[0][0] = bottom[0][1] = bottom[1][1] = 1;
    for(int depth = 2; depth <= n; depth++){
        // copy bottom to top
        for(int i = 0; i < MAX; i++)
            for(int j = 0; j < MAX; j++)
                top[i][j] = bottom[i][j];
        // fill side of bottom row with 1
        for(int i = 0; i < 2 * depth - 1; i++) {
            bottom[i][0] = 1; // left side
            bottom[2 * depth - 2][i] = 1; // down side
            bottom[i][i] = 1; // right side
        }

        // fill
        for(int i = 2; i < 2 * depth - 2; i++){
            for(int j = 1; j < i; j++){
                bottom[i][j] = top[i - 2][j - 1] + top[i - 1][j - 1] + top[i - 1][j];
            }
        }
    }
    // print
    for(int i = 0; i < 2 * n - 1; i++){
        for(int j = 0; j <= i; j++){
            printf("%d\t", bottom[i][j]);
        }
        printf("\n");
    }
    return 0;
}