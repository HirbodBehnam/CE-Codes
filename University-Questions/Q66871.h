#ifndef QUERA_Q66871_H
#define QUERA_Q66871_H

#endif //QUERA_Q66871_H

#include <math.h>
#include <stdio.h>
#include <string.h>

#define NOT_PRIME 0
#define DONE 0
#define NOT_DONE 1

char path[1000]; // I really doubt this is going to be more than 1000 chars in output
int end_x, end_y; // finish point x and y

/**
 * Returns 0 if the number is prime. Returns it's first factor if not
 * @param number The number to check
 * @return 0 if the number is prime otherwise it's first factor
 */
unsigned long long is_prime(unsigned long long x) {
    if (x == 1)
        return 1;
    if (x == 2 || x == 3 || x == 5 || x == 7)
        return 0;
    if (x % 2 == 0)
        return 2;
    if (x % 3 == 0)
        return 3;
    const unsigned long long To = (unsigned long long) sqrt((double) x);
    for (unsigned long long i = 5; i <= To; i += 4) {
        if (x % i == 0)
            return i;
        i += 2;
        if (x % i == 0)
            return i;
    }
    return 0;
}

/**
 * Backtracks the path
 * @param map The map of area
 * @param n Size of map
 * @param i Current x position
 * @param j Current y position
 * @param index The index to write in global variable "path"
 * @return DONE if valid path is found, otherwise NOT_DONE
 */
char backtrack(int *map, const int n, int i, int j, int index) {
    if (i == end_x && j == end_y) // we have reached the destination
        return DONE;

    /*
     * We set this tile's value to 0 (NOT_PRIME)
     * This helps us to avoid re-visiting the visited tiles
     * If this function doesn't find a path until end, THERE IS NO NEED TO RESTORE IT
     * Why? Because if we reach here again, we already know that there is no valid path from here
     * So setting it to 0 and not setting it back later speedups the program (just a bit)
     */
    *((map + i * n) + j) = NOT_PRIME;
    // try to go down
    if ((i + 1) != n && (*((map + (i + 1) * n) + j) != NOT_PRIME)) {
        path[index] = 'D';
        if (backtrack(map, n, i + 1, j, index + 1) == DONE)
            return DONE;
    }
    // try to go up
    if ((i - 1) != -1 && (*((map + (i - 1) * n) + j) != NOT_PRIME)) {
        path[index] = 'U';
        if (backtrack(map, n, i - 1, j, index + 1) == DONE)
            return DONE;
    }
    // try to go right
    if ((j + 1) != n && (*((map + i * n) + j + 1) != NOT_PRIME)) {
        path[index] = 'R';
        if (backtrack(map, n, i, j + 1, index + 1) == DONE)
            return DONE;
    }
    // try to go left
    if ((j - 1) != -1 && (*((map + i * n) + j - 1) != NOT_PRIME)) {
        path[index] = 'L';
        if (backtrack(map, n, i, j - 1, index + 1) == DONE)
            return DONE;
    }
    // if we have reached here, it means that non of the paths were ok; So we remove the last character from string
    path[index] = '\0';
    return NOT_DONE; // we have not found a way yet
}

int main() {
    // read number of problems
    int t;
    scanf("%d", &t);
    for (; t > 0; t--) {
        memset(path, 0, sizeof(path)); // empty the path from last problem (or at start)
        int n;
        scanf("%d", &n);
        // Read the map
        int map[n][n];
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++) {
                int num;
                scanf("%d", &num);
                map[i][j] = is_prime(num) == 0 ? num : NOT_PRIME;
            }
        // read the
        int start_x, start_y;
        scanf("%d %d", &start_x, &start_y);
        scanf("%d %d", &end_x, &end_y);
        if (backtrack((int *) map, n, start_x, start_y, 0) == DONE)
            printf("%s\n", path);
        else
            printf("No Monaseb Masir!\n");
    }
    return 0;
}