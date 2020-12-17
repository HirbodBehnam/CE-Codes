#ifndef QUERA_Q9743_H
#define QUERA_Q9743_H

#endif //QUERA_Q9743_H

#define DIMENSION 9
/**
 * The number in cells that their numbers are not filled
 */
#define NOT_FILLED 0

/**
 * A macro to somehow convert a 1D array to 2D array
 */
#define INDEX_2D(i, j) ((i)*DIMENSION + (j))

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

/**
 * Good ol' backtrack it is, ain't it?
 */

/**
 * Checks if a number can be safely placed in the table of numbers
 * @param table The table of numbers
 * @param x The row number
 * @param y The column number
 * @param to_check The number to check
 * @return True if ok otherwise false
 */
bool ok(const int *table, const int x, const int y, const int to_check) {
    // check the row and column
    for (int i = 0; i < DIMENSION; i++)
        if (table[INDEX_2D(x, i)] == to_check || table[INDEX_2D(i, y)] == to_check)
            return false;

    // check the small tiles; Lines below could be written as x - x % 3
    const int row = x / 3 * 3; // first row of small square
    const int column = y / 3 * 3; // first column of small square
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (table[INDEX_2D(row + i, column + j)] == to_check)
                return false;
    // the number is ok
    return true;
}

/**
 * What is backtrack? Read this: https://en.wikipedia.org/wiki/Sudoku_solving_algorithms#Backtracking
 * @param table The table to bruteforce it
 * @param x The current row we want to fill
 * @param y The current column we want to fill
 * @return Returns true a solution is found
 */
bool backtrack(int *table, int x, int y) {
    // check end
    if (x == DIMENSION - 1 && y == DIMENSION)
        return true;
    // check end of row
    if (y == DIMENSION)
        return backtrack(table, x + 1, 0); // move to next row
    // check filled number
    if (table[INDEX_2D(x, y)] != NOT_FILLED)
        return backtrack(table, x, y + 1);
    // so we ready to bruteforce this thing right?
    for (int i = 1; i <= DIMENSION; i++) {
        if (ok(table, x, y, i)) { // check if it's ok to put this number in table
            table[INDEX_2D(x, y)] = i; // put the number in table!
            if(backtrack(table, x, y + 1)) // check if this number is ok with other tiles after filling
                return true; // end of the story...
        }
        // if we have reached here, it means that this number was not correct and we must change it
        // replace the number with zero to do not fuckup the "ok" function
        table[INDEX_2D(x, y)] = NOT_FILLED;
    }
    // nope; We fucked up somewhere. Backtrack to see what other numbers can be filled
    return false;
}

int main() {
    int *table = malloc(DIMENSION * DIMENSION * sizeof(int));
    for (int i = 0; i < DIMENSION; i++)
        for (int j = 0; j < DIMENSION; j++)
            scanf("%d", &table[INDEX_2D(i, j)]);

    backtrack(table, 0, 0); // solve it

    for (int i = 0; i < DIMENSION; i++) {
        for (int j = 0; j < DIMENSION; j++)
            printf("%d ", table[INDEX_2D(i, j)]);
        putchar('\n');
    }
    return 0;
}