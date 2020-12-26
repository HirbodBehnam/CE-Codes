#ifndef QUERA_Q5_H
#define QUERA_Q5_H

#endif //QUERA_Q5_H

#include <stdio.h>

/**
 * Checks if a number is palindrome or not
 * @param number The number to check
 * @return 1 if the number is palindrome otherwise 0
 */
char is_palindrome(unsigned long long number) {
    unsigned long long temp = number, reversed = 0;
    while (temp != 0) {
        reversed *= 10;
        reversed += temp % 10;
        temp /= 10;
    }
    return reversed == number;
}

int main() {
    unsigned long long n;
    scanf("%llu", &n);
    puts(is_palindrome(n) ? "yes" : "no");
    return 0;
}