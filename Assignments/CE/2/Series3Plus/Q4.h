#ifndef QUERA_Q4_H
#define QUERA_Q4_H

#endif //QUERA_Q4_H

#include <stdio.h>

/**
 * Does the thing that question asks for
 * @param number The number to check
 */
void math(unsigned long long number) {
    int odd_digits = 0, even_digits = 0;
    unsigned long long even_product = 1, odd_sum = 0; // even product can be more than 2^31`so use unsigned long long
    while (number != 0) { // read all digits
        char digit = (char) (number % 10); // get the char; smaller datatype because of my OCD
        if (digit % 2 == 0) { // even digit
            even_digits++;
            even_product *= digit;
        } else { // odd digit
            odd_digits++;
            odd_sum += digit;
        }
        number /= 10;
    }
    // check the digits count
    if (odd_digits == 0 || even_digits == 0) {
        puts("error");
        return;
    }
    // compare numbers
    puts(odd_sum == even_product ? "yes" : "no");
}

int main() {
    unsigned long long n;
    scanf("%llu", &n);
    math(n);
    return 0;
}