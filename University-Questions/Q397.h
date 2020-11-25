#ifndef QUERA_Q397_H
#define QUERA_Q397_H

#endif //QUERA_Q397_H

#include <stdio.h>
#include <string.h>

int main() {
    /**
     * What is the algorithm here?
     * Let's at first talk about how we check if brackets are balanced
     * To check it you can simply use a stack and add all opening ones and pop when we reach a closed one
     * Read more at: https://www.geeksforgeeks.org/check-for-balanced-parentheses-in-an-expression/
     *
     * At very very first; If the input length is odd, the input is not balanced and it cannot be fixed.
     * However this question does not ask for it, so we can simply ignore checking input length
     *
     * But that algorithm can be improved if we are checking only (). We do not need to use stack anymore. (O(1) memory usage)
     * We can declare a value such as balance (open_brackets in this algorithm plays it's rule) to play as are stack rule
     * If we reach '(', we increase "balance" by one. If we reach ')', we decrease balance by one
     * Either if at end balance is not zero, or balance becomes negative at anypoint,the input is not valid
     * Otherwise the input is balanced and valid.
     *
     * Here the approach is kinda the same. We have a variable like balance (open_brackets). We try to remove balanced brackets from string first
     * But what is closed_brackets? Think of that an input begins with ')'. No matter how much or what we read
     * we cannot do anything to "cancel" that bracket. We count these brackets in closed_brackets.
     * How do we count them? Think about this input "()))((". Lets try to calculate the "balance" value for this
     * -> 0 -> 1 -> 0 -> -1 -> -2 -> 1 -> 0
     * As we can see, balance is 0 at last but we have reached negative values in middle of it
     * closed_brackets indicate how many "un-fixable" ')' we have no matter what or how much we read more.
     * It's value is increased everytime we reach ')' and balance is 0 or less.
     *
     * However that algorithm also have small problems. We have to forget about un-fixable ')' in balance and
     * start accepting new '(' when we reach them. So I do not allow open_brackets to go under 0.
     * If it's 0 and we reach ')'. We simply only increase closed_brackets by one.
     *
     * At last we have have to see how much of these brackets we have to swap in order to fix the input
     * we need to at least swap ceiling of half of both variables in order to make it balanced. Why?
     * Think of it this way: "))))((" (The value after removing balanced brackets). The length of that is always even
     * In this case we have to swap last bracket (open_brackets / 2), and swap first two brackets (closed_brackets / 2)
     * That can be also written as (open_brackets + closed_brackets) / 2
     * But look at this: ")))(". Now what should we do? Last formula returns '2' but we cant fix this string by swapping two brackets
     * We have to actually swap the last bracket and first and third. So we need to swap 3 of them
     * But why? Because closed_brackets and open_brackets are both odd.
     * So when both of them are odd we need to add 1 to the (open_brackets + closed_brackets) / 2. Otherwise we need to add nothing
     * Also note that never something like "))(" happens. Because closed_brackets + open_brackets is always even because input is always
     * in even length and when removing stuff like "()" we always remove a pair of them so the length stays even
     */
    int closed_brackets = 0, open_brackets = 0;
    while (1) {
        // I don't read all of the input to reduce RAM usage
        int c = getchar();
        if (c == '(') {
            open_brackets++;
        } else if (c == ')') {
            if (open_brackets == 0)
                closed_brackets++;
            else
                open_brackets--;
        } else {
            break;
        }
    }
    printf("%d", (open_brackets + closed_brackets) / 2 +
                 open_brackets % 2); // add one when open_brackets (or closed_brackets) is odd
    return 0;
}