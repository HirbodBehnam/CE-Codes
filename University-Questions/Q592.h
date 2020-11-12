#ifndef QUERA_Q592_H
#define QUERA_Q592_H

#endif //QUERA_Q592_H

#include <stdio.h>

// This is not optimized. I might optimize it later
int run(){
    int a, b;
    scanf("%d %d", &a, &b);

    int max = a > b ? a : b;
    if(a == b){ // the numbers must not be same. If so, all of the numbers will fit in the answer
        return 0;
    }

    for(int i = 2; i <= max; i++)
        if(a % i == b % i)
            printf("%d ", i);

    return 0;
}