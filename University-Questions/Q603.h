#ifndef QUERA_Q603_H
#define QUERA_Q603_H

#endif //QUERA_Q603_H

#include <stdio.h>

/**
 * A recursive algorithm to check in how many ways this climb can be code
 * @param needed The amount of steps needed to reach the top
 * @return The amount of ways that can be done
 */
int check_ways(int needed) {
    if (needed < 0) // there is no way down!
        return 0;
    if (needed == 1 || needed ==
                       0) // if needed is 0, it means that we are already there, if it's 1 we can only use 1 step stair to reach top
        return 1;
    // we can either go 1 step, 2 steps or 5 steps
    return check_ways(needed - 1) + check_ways(needed - 2) + check_ways(needed - 5);
}

/**
 * This question is a bit different from that coin problem
 * In coin problem there is no difference between the order of appearances of coins.
 * However in this question order of appearances matter
 */
int main() {
    int n;
    scanf("%d", &n);
    printf("%d", check_ways(n));
    return 0;
}