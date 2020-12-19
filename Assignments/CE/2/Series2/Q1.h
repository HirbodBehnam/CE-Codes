#ifndef QUERA_Q1_H
#define QUERA_Q1_H

#endif //QUERA_Q1_H

#include <stdio.h>

int main() {
    unsigned long long to;
    scanf("%llu", &to);
    // we start from 1,1 and go on
    unsigned long long sum = 2, last = 1, now = 1; // last is the last number is series; now is the current candidate
    while (now <= to) {
        unsigned long long next = now + last; // a temp value because we will overwrite last later
        sum += next;
        last = now;
        now = next;
    }
    printf("%llu %llu", now, sum);
    return 0;
}