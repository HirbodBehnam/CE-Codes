#ifndef QUERA_Q1_H
#define QUERA_Q1_H

#endif //QUERA_Q1_H

#include <stdio.h>

/**
 * Algorithm from:
 * https://www.geeksforgeeks.org/iterative-tower-of-hanoi/
 * https://en.wikipedia.org/wiki/Tower_of_Hanoi#Simpler_statement_of_iterative_solution
 * The algorithm here is to use bits in array as an array; For example if the first bit is one, it means that
 */

/**
 * Choose either dst or src for a legal move
 * @param src The source rod
 * @param dst The dst rod
 * @return 1 if we must make a move from src to dst, otherwise 0
 */
char choose(unsigned long long src, unsigned long long dst) {
    if (src == 0)
        return 0;
    if (dst == 0)
        return 1;
    unsigned int counter = 0;
    while (1) {
        if (((src >> counter) & 1) == 1)
            return 1; // must be moved to dst
        if (((dst >> counter) & 1) == 1)
            return 0; // must be moved to dst
        counter++;
    }
}

/**
 * Gets the first index in either src or dst which is not zero
 * This helps to find the top disk in either these two rods
 * @param src src
 * @param dst dst
 * @return The first index which is not zero
 */
unsigned int get_index(unsigned long long src, unsigned long long dst) {
    unsigned int counter = 0;
    while (1) {
        if (((src >> counter) & 1) == 1)
            return counter; // must be moved to dst
        if (((dst >> counter) & 1) == 1)
            return counter; // must be moved to dst
        counter++;
    }
}

int main() {
    /**
     * Number of disks in rods
     */
    unsigned long long A, B = 0, C = 0, FINAL;
    int total_disks;
    {
        scanf("%d", &total_disks);
        // turn on all of the bits
        A = FINAL = (1U << total_disks) - 1;
    }
    unsigned long long total_moves = 0;
    if (total_disks % 2 == 0) {
        while (C != FINAL) {
            char move_to_dst;
            unsigned int index_to_move;
            // First move
            move_to_dst = choose(A, B);
            index_to_move = get_index(A, B);
            if (move_to_dst) {
                A &= ~(1U << index_to_move); // remove from A
                B |= 1U << index_to_move; // add to B
            }else{
                B &= ~(1U << index_to_move); // remove from B
                A |= 1U << index_to_move; // add to A
            }
            total_moves++;
            // Second move
            move_to_dst = choose(A, C);
            index_to_move = get_index(A, C);
            if (move_to_dst) {
                A &= ~(1U << index_to_move); // remove from A
                C |= 1U << index_to_move; // add to C
            }else{
                C &= ~(1U << index_to_move); // remove from C
                A |= 1U << index_to_move; // add to A
            }
            total_moves++;
            // Third move
            move_to_dst = choose(B, C);
            index_to_move = get_index(B, C);
            if (move_to_dst) {
                B &= ~(1U << index_to_move); // remove from B
                C |= 1U << index_to_move; // add to C
            }else{
                C &= ~(1U << index_to_move); // remove from C
                B |= 1U << index_to_move; // add to B
            }
            total_moves++;
        }
    } else {
        while (1) {
            char move_to_dst;
            unsigned int index_to_move;
            // First move
            move_to_dst = choose(A, C);
            index_to_move = get_index(A, C);
            if (move_to_dst) {
                A &= ~(1U << index_to_move); // remove from A
                C |= 1U << index_to_move; // add to C
            }else{
                C &= ~(1U << index_to_move); // remove from C
                A |= 1U << index_to_move; // add to A
            }
            total_moves++;
            if(C == FINAL) // Note that the end is here not at the end
                break;
            // Second move
            move_to_dst = choose(A, B);
            index_to_move = get_index(A, B);
            if (move_to_dst) {
                A &= ~(1U << index_to_move); // remove from A
                B |= 1U << index_to_move; // add to B
            }else{
                B &= ~(1U << index_to_move); // remove from B
                A |= 1U << index_to_move; // add to A
            }
            total_moves++;
            // Third move
            move_to_dst = choose(B, C);
            index_to_move = get_index(B, C);
            if (move_to_dst) {
                B &= ~(1U << index_to_move); // remove from B
                C |= 1U << index_to_move; // add to C
            }else{
                C &= ~(1U << index_to_move); // remove from C
                B |= 1U << index_to_move; // add to B
            }
            total_moves++;
        }
    }
    printf("%llu", total_moves);
    return 0;
}