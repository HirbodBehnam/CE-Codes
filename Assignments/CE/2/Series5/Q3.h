#ifndef QUERA_Q3_H
#define QUERA_Q3_H

#endif //QUERA_Q3_H

#define MAX_NAME_SIZE 1000
#define CHEAT (-1)

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int n;
    scanf("%d", &n);
    /**
     * Names contains names of each participant regarding of their index in other arrays as well
     */
    char names[n][MAX_NAME_SIZE];
    /**
     * Numbers contains the number that each participant has given
     * -1 means that that the user has cheated
     * So why n + 1 and then setting number[n] to -1?
     * At the for loop that we search for answer, we increase 'i' while it is less than 'n'
     * A problem occurs when we try to check 'i + 1' when i = n - 1
     * So we make the array one element bigger, and then we set the last element to -2 so it is not a repeated number in any way
     * Also note that the bubble sort is one on first n elements not first n + 1 elements
     */
    int numbers[n + 1];
    numbers[n] = -2;
    // read all participants
    for (int i = 0; i < n; i++) {
        // read the input
        scanf("%d ", &numbers[i]);
        int index = 0;
        char c;
        while ((c = getchar()) != '\n' && c != EOF) { // read manually because we may encounter whitespace
            names[i][index] = c;
            index++;
        }
        names[i][index] = '\0'; // null terminator
        // check if the user has cheated
        for (int j = 0; j < i; j++) { // check all users before
            if (strcmp(names[i], names[j]) == 0) {
                numbers[i] = CHEAT;
                numbers[j] = CHEAT;
                break;
            }
        }
    }
    // sort them (bubble sort)
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - i - 1; j++)
            if (numbers[j] > numbers[j + 1]) {
                // swap the number
                int temp = numbers[j];
                numbers[j] = numbers[j + 1];
                numbers[j + 1] = temp;
                // swap the name
                char temp_name[MAX_NAME_SIZE];
                strcpy(temp_name, names[j]);
                strcpy(names[j], names[j + 1]);
                strcpy(names[j + 1], temp_name);
            }
    // no read from first to find the min number which is unique
    for (int i = 0; i < n; i++) {
        if (numbers[i] > 0) {
            if (numbers[i] == numbers[i + 1]) {
                // if here is reached, move 'i' until we reach another value
                // this algorithm is so messy, I don't know if there is better way
                i++;
                while (i < n && numbers[i] == numbers[i - 1])
                    i++;
                i--; // put i-- to neutralize i++
            } else {
                printf("%s", names[i]);
                return 0;
            }
        }
    }
    printf("No One");
    return 0;
}