#ifndef QUERA_Q303_H
#define QUERA_Q303_H

#endif //QUERA_Q303_H

#include <stdio.h>

/**
 *
 * @param n The next number in series
 * @param m The first number in series
 */
void ShowFibNth(long int n, long int m){
    printf("%ld\n", m);
    if(n == 1) // terminate the function when it reaches the first element (1)
        return;
    ShowFibNth(m, n - m);
}

int run(){
    long int a, b;
    scanf("%ld", &a);
    scanf("%ld", &b);
    ShowFibNth(b, a);
}