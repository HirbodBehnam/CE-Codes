#ifndef QUERA_Q72633_H
#define QUERA_Q72633_H

#endif //QUERA_Q72633_H

#include <stdio.h>

/**
 * How did i get those numbers?
 * Testing :|
 */
int run(){
    int n;
    scanf("%d", &n);
    // Print first row
    printf("*");
    for(int i = 0; i < 2 * n - 1; i++)
        printf(" ");
    for(int i = 0; i < n; i++)
        printf("* ");
    printf("\n");
    // Print other rows for top triangles
    for(int i = 0; i < n - 2; i++){
        // Print left triangle
        printf("*"); // print the vertical side
        for(int j = 0; j < i * 2 + 1; j++) // print the area of triangle
            printf(" ");
        printf("*"); // print the hypotenuse
        for(int j = 2 * n - 2 * i - 3; j > 0; j--) // print the spaces between this triangle and the right one
            printf(" ");
        // Print right triangle
        printf("*");
        for(int j = 2 * n - 2 * i - 5; j > 0; j--) // print the area of triangle
            printf(" ");
        printf("*");
        // Go to new line
        printf("\n");
    }
    // Print the last line of these triangles
    for(int i = 0; i < n; i++)
        printf("* ");
    printf("*");
    printf("\n");
    // Now print the lower triangles
    // Just like before at first print the top row
    for(int i = 0; i < 2 * n - 2; i++)
        printf(" ");
    printf("*");
    for(int i = 0; i < n; i++)
        printf(" *");
    printf("\n");
    // Print other rows
    for(int i = 0; i < n - 2; i++){
        // Print left triangle
        for(int j = 2 * n - 2 * i - 4; j > 0; j--) // print the spaces between this triangle and the right one
            printf(" ");
        printf("*"); // print the vertical side
        for(int j = 0; j < i * 2 + 1; j++) // print the area of triangle
            printf(" ");
        printf("*"); // print the hypotenuse
        // Print right triangle
        printf(" ");
        for(int j = 0; j < 2 * i + 2; j++)
            printf(" ");
        printf("*");
        for(int j = 2 * n - 2 * i - 5; j > 0; j--) // print the area of triangle
            printf(" ");
        printf("*");
        // Go to new line
        printf("\n");
    }
    // Print last row
    for(int i = 0; i < n; i++)
        printf("* ");
    for(int i = 0; i < n * 2 - 2; i++)
        printf(" ");
    printf("*");
    return 0;
}