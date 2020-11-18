#ifndef QUERA_Q304_H
#define QUERA_Q304_H

#endif //QUERA_Q304_H

#include <stdio.h>

long double myPow(long double base, unsigned int expo){
    if(expo == 0)
        return 1;
    return base * myPow(base, expo - 1);
}

int main() {
    long double Base;
    unsigned int expo;
    scanf("%Lf %du", &Base, &expo);
    printf("%.3Lf", myPow(Base, expo));
    return 0;
}