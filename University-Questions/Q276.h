#ifndef QUERA_Q276_H
#define QUERA_Q276_H

#endif //QUERA_Q276_H

#include <stdio.h>

int main(){
    int digits, sum;
    scanf("%d %d", &digits, &sum);
    if(sum == 0 || sum > digits * 9){
        printf("-1 -1");
        return 0;
    }
    // find the smallest number
    if(sum != 1) {
        int temp_sum = sum;
        int temp_digits = digits;
        if (temp_sum <= (temp_digits - 1) * 9) { // the number must not start with 0
            temp_sum--;
            temp_digits--;
            putchar('1');
        }
        while (1) {
            if (temp_sum > (temp_digits - 1) * 9) {
                char to_print = (temp_sum % 9) + '0';
                if (to_print == '0')
                    to_print = '9';
                putchar(to_print);
                temp_digits--;
                for (; temp_digits > 0; temp_digits--)
                    putchar('9');
                break;
            }
            temp_digits--;
            putchar('0');
        }
    } else {
        putchar('1');
        for(int i = 1; i < digits; i++)
            putchar('0');
    }
    putchar(' ');
    // find the biggest number
    int temp_sum = sum;
    int temp_digits = digits;
    while (temp_sum > 9){
        temp_sum-=9;
        temp_digits--;
        putchar('9');
    }
    putchar(temp_sum + '0');
    temp_digits--;
    for(; temp_digits > 0; temp_digits--)
        putchar('0');
    return 0;
}