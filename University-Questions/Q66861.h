#ifndef QUERA_Q66861_H
#define QUERA_Q66861_H

#endif //QUERA_Q66861_H

#include <math.h>
#include <stdio.h>
#include <string.h>

/**
 * Returns the number of factors of a number
 * @param number The number
 * @return Number of factors
 */
int number_of_factors(unsigned int number) {
    int counter = 0;
    const unsigned int To = (unsigned int) sqrt((double) number);
    for (int i = 1; i <= To; i++)
        if (number % i == 0)
            counter += 2; // one for i and another for (number/i)

    // fix perfect square numbers
    if (To * To == number)
        counter--;
    return counter;
}

void run() {
    // this array must be filled with first number that have n (array's index) of factors
    // so at first calculate the lookup table
    unsigned int first_number[300 + 1];
    memset(first_number, 0, sizeof(first_number)); // zero the array
    first_number[1] = 1;
    unsigned int index = 2, sum = 1;
    while (1) {
        sum += index;
        index++;
        int factors_count = number_of_factors(sum);
        for (int i = 1; i <= factors_count; i++)
            if (first_number[i] == 0)
                first_number[i] = sum;
        if (factors_count == 300)
            break;
    }
    // get the input
    int number;
    scanf("%d", &number);
    printf("%u", first_number[number]);
}
