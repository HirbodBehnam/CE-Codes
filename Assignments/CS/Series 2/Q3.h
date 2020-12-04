#ifndef QUERA_Q3_H
#define QUERA_Q3_H

#endif //QUERA_Q3_H

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
     * After looking at some big examples from my friend's code, I stated seeing a pattern in the x of the squares
     * If n was 4, the x for squares was {0,4} -> 4 = 4
     * If n was 5, the x for squares was {0,4,6} -> 6 = 4 + 2
     * If n was 6, the x for squares was {0,8,12} -> 12 = 8 + 4
     * If n was 7, the x for squares was {0,8,12,14} -> 14 = 8 + 4 + 2
     * I wanted to somehow connect the number of each set to how many recursions are left (AKA depth)
     * Obviously, there should have been a depth/2 somewhere in the formula. I also had the last x from the last recrusion
     * So the only thing I had to do was to calculate how much I should add to it
     * The formula I came with was
     * x + 2 ^ ceiling(depth / 2)
     * Which is correct. Note that the x the formula is the x of the last square not the rhombus. This means that
     * when calling print_square, I should use x - 1 instead of x
     * I also didn't want to use ceiling function or such stuff; ceiling(depth / 2) can be simply written as
     * floor(depth / 2 + 0.5) which is (depth + 1) / 2 (integer division)
     * The bitshift is also used to fastly compute 2 ^ n
     */
    print_square(array, diameter / 2 + 1, x - 1 + (1U << ((depth + 1) / 2)), depth - 1);
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

int run() {
    unsigned int n;
    scanf("%u", &n); // read the number of iterations
    final_width = (1U << (n / 2 + 2)) - 1; // get the width
    char *result = malloc(final_width * final_width * sizeof(char)); // create an array to print it at last
    memset(result, '.', final_width * final_width * sizeof(char)); // fill the result with '.'
    // use recursion to fill the result
    print_square(result, final_width, 0, n);
    // print the result
    print_result((const char *) result);
    return 0;
}