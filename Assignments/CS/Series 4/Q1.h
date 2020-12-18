#ifndef QUERA_Q1_H
#define QUERA_Q1_H

#endif //QUERA_Q1_H

#include <stdio.h>

/**
 * Kinda bruteforce all the ways that dices sum can be a value
 * In each step we reduce one from dices (the imagine that we have thrown one) and subtract it's number from from remaining
 * Now we have (dice - 1) dices and a new remaining to calculate; So do recursive call
 * Most of this code is my friend's code but I've done some optimizations to make it faster
 * @param dice The number of dices remaining
 * @param remaining The sum remaining
 * @return Number of ways that dices can create remaining
 */
unsigned long long test(unsigned long long dice, unsigned long long remaining) {
    /**
     * If anytime the remaining becomes less than 1, it means that we cannot do ANYTHING to add to remaining.
     * So this "branch" is lost and there is no way that we can create this sum. (Now the sum is more than target sum)
     * If dice * 6 is less than remaining also means that this branch is lost and we cannot recover.
     * It mostly means that if all of the remaining dices are 6, we cannot create sum because we the sum upto now is very low
     * This if case makes the code at least 2 times faster
     */
    if (remaining <= 0 || dice * 6 < remaining)
        return 0;
    if (dice == 1) // if the above 'if' is false and dices is one, it means that there is only one way we can complete dices
        return 1;
    // test all other options
    dice--;
    return test(dice, remaining - 1) + test(dice, remaining - 2)
           + test(dice, remaining - 3) + test(dice, remaining - 4)
           + test(dice, remaining - 5) + test(dice, remaining - 6);

}

int main() {
    unsigned long long d, r;
    scanf("%llu %llu", &d, &r);
    printf("%llu", test(d, r));
}