#ifndef QUERA_Q10640_H
#define QUERA_Q10640_H

#endif //QUERA_Q10640_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/**
 * Total width of the square we are going to print
 * This variable is used in INDEX_2D macro in order to get the index of a element
 */
unsigned int final_width;

/**
 * Gets the index of element in 1D array with 2D array coordinates
 * Uses final_width as width of array
 */
#define INDEX_2D(i, j) ((i)*final_width + (j))

/**
 * Draws a square in array with given width and position (x)
 * @param array The array to draw the square in
 * @param width The width of square to draw
 * @param x The x and y position of top left edge of square. Please note that x and y of the edge is always the same
 * @param depth The depth of recursion. The recursion must stop when it reaches 0
 */
void print_square(char *array, unsigned int width, unsigned int x, unsigned int depth);

/**
 * Prints a 2D square array to STDOUT
 * Uses final_width to get the array width and height
 * @param result The array to print
 */
void print_result(const char *result) {
    for (int i = 0; i < final_width; i++) {
        for (int j = 0; j < final_width; j++) // print row
            putchar(result[INDEX_2D(i, j)]);
        putchar('\n'); // go to new line to print the next row
    }
}

/**
 * Prints a rhombus in an array of char
 * Well, it's not just a rhombus, it's supposed to be a rotated square
 * @param array The array to print the rhombus in
 * @param diameter Diameter of the rhombus. Note that both diameters are equal
 * @param x X is the distance from the edges of the array. For example 1 means that the leave the most left,right,top,bottom rows and columns of array alone
 * @param depth The depth of recursion. The recursion must stop when it reaches 0
 */
void print_rhombus(char *array, const unsigned int diameter, const unsigned int x, const unsigned int depth) {
    if (depth == 0)
        return;

    int whitespace = (int) diameter / 2; // amount of whitespace before we should use #
    for (unsigned int i = 0; i < diameter; i++) {
        array[INDEX_2D(x + i, x + abs(whitespace))] = '#'; // goes middle to left
        array[INDEX_2D(x + i, diameter - 1 + x - abs(whitespace))] = '#';  // goes middle to right
        whitespace--;
    }
    /**
     * So lemme explain how we are calling the square function again
     * We pass the array again to fill it
     * I found the width by just looking at the examples and trying to find a pattern
     * Depth must be decreased by one because we have done one recursion
     * What about X?
     * This is the only part that is different from that CS problem
     * It was obvious that x - 1 must exist so that change the position relative to last x
     * For the other part, I found ceiling(diameter + 2) / 2 / 2
     * I basically, guessed this formula mostly because I thought: I can use diameter as well instead of depth
     * With that formula, we can simplify that to (diameter + 3) / 4 to get rid of ceiling
     */
    print_square(array, diameter / 2 + 1, x - 1 + (diameter + 3) / 4, depth - 1);
}

// Explained it at top
void print_square(char *array, const unsigned int width, const unsigned int x, const unsigned int depth) {
    if (depth == 0)
        return;

    for (unsigned int i = 0; i < width; i++) {
        array[INDEX_2D(x, i + x)] = '#'; // top row
        array[INDEX_2D(width - 1 + x, i + x)] = '#'; // bottom row
        array[INDEX_2D(i + x, x)] = '#'; // right row
        array[INDEX_2D(i + x, width - 1 + x)] = '#'; // left row
    }
    /**
     * This one is a bit self explained
     * We pass the array again to fill it
     * The diameter is just the width of this square minus two because we cannot use the top and bottom rows of square
     * We must also increase the distance by one because we don't want to use the square sides to draw the rhombus
     * Depth must be decreased by one because we have done one recursion
     */
    print_rhombus(array, width - 2, x + 1, depth - 1);
}

int main() {
    unsigned int n;
    scanf("%u", &n); // read the number of iterations
    final_width = (1U << (n + 1)) - 1; // get the width
    char *result = malloc(final_width * final_width * sizeof(char)); // create an array to print it at last
    memset(result, '.', final_width * final_width * sizeof(char)); // fill the result with '.'
    // use recursion to fill the result
    print_square(result, final_width, 0, n);
    // print the result
    print_result((const char *) result);
    return 0;
}