#ifndef QUERA_Q9744_H
#define QUERA_Q9744_H

#endif //QUERA_Q9744_H

#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// Set the min value to max value of unsigned long long to avoid declaring a starting value and checking it
unsigned long long min = 0xffffffffffffffff;
// The candidates of jobs are stored here
char *candidates;

/**
 * Checks if an array contains an element
 * @param array The array to check
 * @param length Length of array
 * @param to_check The number to check
 * @return True if the element exists, false otherwise
 */
bool array_contains(const char *array, const int length, const char to_check) {
    for (int i = 0; i < length; i++)
        if (array[i] == to_check)
            return true;

    return false;
}

/**
 * Bruteforce all the possible ways to choose people
 * Before this I used a better bruteforce method that checked sum in each step but it didn't work
 * This method builds the permutations of candidates, then at last, calculates the sum of costs of candidates
 * If the sum is less than min, updates the min and candidates list
 * @param map The map of costs of employees
 * @param length Number of employees
 * @param level The depth of backtracking; The last depth is same as length
 * @param chosen Array of chosen candidates
 */
void backtrack(const int *map, const int length, const int level, const char *chosen) {
    // Check if we have reached the end
    if (level == length) {
        unsigned long long sum = 0;
        for(int i = 0; i < level; i++)
            sum += map[i * length + chosen[i]]; // map is actually a 2D array
        if (min >= sum) {
            memcpy(candidates, chosen, level); // update the candidates and sum
            min = sum;
        }
        return;
    }
    // Choose someone for next job
    char *chosen_now = malloc((level + 1) * sizeof(char)); // create an array with one more element to choose
    memcpy(chosen_now, chosen, level * sizeof(char));
    for (char i = 0; i < length; i++) {
        if (!array_contains(chosen, level, i)) { // choose someone who is not being chosen
            chosen_now[level] = i;
            backtrack(map, length, level + 1, chosen_now); // use recursion to choose someone else
        }
    }
    free(chosen_now); // prevent memory leak
}

int main() {
    int n;
    scanf("%d", &n); // read number of employees
    candidates = malloc(n * sizeof(char));
    int *cost = malloc(n * n * sizeof(int));
    // read the cost matrix
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &cost[i * n + j]);

    // bruteforce all possible ways
    backtrack((const int *) cost, n, 0, 0);
    free(cost); // we do not need cost anymore

    for (int i = 0; i < n; i++) // print candidates
        printf("%d\n", candidates[i]);

    free(candidates); // free candidates as well mostly because it's a global variable
    return 0;
}