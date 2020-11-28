#ifndef QUERA_Q72631_H
#define QUERA_Q72631_H

#endif //QUERA_Q72631_H

#include <stdio.h>

int run(){
    long long a, b, c, d; // why long long? because multiplying ints might cause integer overflow
    scanf("%lld %lld %lld %lld", &a, &b, &c, &d);
    long long max = b * d > a * c ? b * d : a * c; // this is normal checking
    if(max < a * d) // for something i don't remember :|
        max = a * d;
    if(max < b * c) // for -20 -10 10 20
        max = b * c;
    printf("%lld", max);
    return 0;
}