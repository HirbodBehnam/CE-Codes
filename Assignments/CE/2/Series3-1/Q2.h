#ifndef QUERA_Q2_H
#define QUERA_Q2_H

#endif //QUERA_Q2_H

#include <stdio.h>

/**
 * Well lemme tell you something; I'm really dumb :| At first I tried to solve this question with recursive functions and stuff like that
 * The plan is this. If the population is 4, we can infinitely increase the population by multiplying it in 1.5;
 * How? 4 * 1.5 = 6 -> 6 * 1.5 = 9 -> 9 - 1 = 8 -> 8 * 1.5 = 12 -> ... As you can see there is no limit to increasing the population
 * No need to say we can decrease the population by one each year; So EVERY NUMBER (except 0) is possible when the population is bigger or equal to 4
 * But what if current population is less than 4?
 * Let's see what happens then by checking each number
 * 3 -> If the number is 3, if the first move, we can only and only reduce the population by one -> 2.
 * When the population is 2, we have two options; We can either reduce one more to reach 1, or multiply 2 in 1.5 to get back to 3
 * So if the current population is either 2 or 3, we can only and only reach 1,2 or 3 in target population
 * If the current population is 1, we can't do anything unless the target is 1 too
 * @param x Current population
 * @param y Target population
 * @return 1 if reaching target is possible 0 if not
 */
char check(int x, int y) {
    if (y == 0) // we cannot reach zero population in anyway
        return 0;
    if (x >= 4) // any target is possible current population is more than, or equal to 4
        return 1;
    if (x == 3 || x == 2) // if current is 3 or 2, we can only reach 1,2,3 in target
        return y <= 3;
    if (x == 1) // if current is 1, we can only reach 1
        return y == 1;
    return 0;
}

int main() {
    int x, y, t;
    scanf("%d", &t);
    while (t--) {
        scanf("%d%d", &x, &y);
        if (check(x, y))
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}