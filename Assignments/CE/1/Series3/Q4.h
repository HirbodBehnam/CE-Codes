#ifndef QUERA_Q4_H
#define QUERA_Q4_H

#endif //QUERA_Q4_H

#include <stdio.h>

/**
 * Calculates the distance^2 of a point from (0,0)
 * @param x
 * @param y
 * @return distance^2
 */
long long distance(long long x, long long y) {
    return x * x + y * y;
}

int main() {
    long long r1, r2, r3;
    long long score1, score2, score3;
    scanf("%lldR %lldR %lldR", &r1, &r2, &r3);
    if (r1 == r2 || r2 == r3 || r1 == r3) { // check same radius
        printf("error");
        return 0;
    }
    scanf("%lld %lld %lld", &score1, &score2, &score3);
    // sort scores
    {
        long long temp;
        // bubble sort
        // first iteration
        if (score1 < score2) {
            temp = score1;
            score1 = score2;
            score2 = temp;
        }
        if (score2 < score3) {
            temp = score2;
            score2 = score3;
            score3 = temp;
        }
        // second and last iteration
        if (score1 < score2) {
            temp = score1;
            score1 = score2;
            score2 = temp;
        }
    }
    // calculate the true radius
    {
        int smallest_r;
        scanf("%d", &smallest_r);
        double ratio = (double) r1 / smallest_r;
        r1 = (int) ((double) r1 / ratio);
        r2 = (int) ((double) r2 / ratio);
        r3 = (int) ((double) r3 / ratio);
    }
    // do this to eliminate the need of sqrt
    r1 *= r1;
    r2 *= r2;
    r3 *= r3;
    // get the darts
    long long n, score = 0;
    scanf("%lld", &n);
    for (; n > 0; n--) {
        long long x, y;
        scanf("%lld %lld", &x, &y);
        long long r = distance(x, y); // radius of circle ^ 2
        if (r <= r1)
            score += score1;
        else if (r <= r2)
            score += score2;
        else if (r <= r3)
            score += score3;
    }
    printf("%lld", score);
    return 0;
}