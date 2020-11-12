#ifndef QUERA_Q9773_H
#define QUERA_Q9773_H

#endif //QUERA_Q9773_H

#include <stdio.h>
/**
 * Returns |i|
 * @param i
 * @return
 */
int abs(int i){
    return i < 0 ? -i : i;
}

/**
 * Prints whitespace amount of whitespace, then starts amount of '*' and again whitespace amount of whitespace
 * @param whitespace
 * @param stars
 */
void print(int whitespace, int stars){
    for(int j = 0; j < whitespace; j++)
        printf(" ");
    for(int j = 0; j < stars; j++)
        printf("*");
    for(int j = 0; j < whitespace; j++)
        printf(" ");
}

int run(){
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        int whitespace = abs(n / 2 - i);
        int stars = n - whitespace * 2;
        print(whitespace, stars);
        print(whitespace, stars);
        printf("\n");
    }
    return 0;
}