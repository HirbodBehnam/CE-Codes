#ifndef QUERA_Q4_H
#define QUERA_Q4_H

#endif //QUERA_Q4_H

#define MAX_STRING 1000

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct block {
    int P;
    /**
     * Number of transactions
     */
    int n;
    char **transactions;
    char *primary_string;
};

typedef struct block Block;

Block *new_block(int, int);

void free_block(Block *);

char value(const char *, int);

char *read_line();

int main() {
    // number of blockchains including genesis block
    int m;
    scanf("%d\n", &m);
    // create genesis block
    Block *first_block = new_block(0, 0);
    free(first_block->primary_string); // do not leak memory
    first_block->primary_string = read_line();
    // read next blocks
    while ((m--) > 1) {
        int n, P;
        scanf("%d %d\n", &n, &P);
        Block *second_block = new_block(n, P);
        for(int i = 0; i < n; i++)
            second_block->transactions[i] = read_line();
        // calculate primary string (hash)
        for(int i = 0; i < n; i++)
            second_block->primary_string[i] = value(second_block->transactions[i], second_block->P);

        char alter = value(first_block->primary_string, second_block->P);
        second_block->primary_string[alter % second_block->n] = alter;
        // free last block and replace this block with it
        free_block(first_block);
        first_block = second_block;
    }

    puts(first_block->primary_string);
    return 0;
}

/**
 * Creates a new block and returns its pointer
 * @param n The number of transactions
 * @param P The prime number
 * @return A pointer to block
 */
Block *new_block(int n, int P) {
    Block *b = malloc(sizeof(Block));
    b->n = n;
    b->P = P;
    b->primary_string = malloc((n + 1) * sizeof(char));
    b->primary_string[n] = 0;
    b->transactions = malloc((n + 1) * sizeof(char *));
    return b;
}

/**
 * Frees a block from memory
 * @param block
 */
void free_block(Block *block) {
    free(block->primary_string);
    for (int i = 0; i < block->n; i++)
        free(block->transactions[i]);
    free(block->transactions);
    free(block);
}

/**
 * Semi hash function?
 * @param s The string
 * @param P The prime number
 * @return Result
 */
char value(const char *s, const int P) {
    int pk = 1;
    int sum = 0;
    for (int k = 0; k < strlen(s); k++) {
        sum += s[k] * pk;
        pk *= P;
        pk %= 94;
        sum %= 94;
    }
    return (char) (sum + 33);
}

/**
 * Reads a line from stdin and removes it new line
 * @return The line
 */
char *read_line() {
    char *buffer = malloc(MAX_STRING * sizeof(char));
    fgets(buffer, MAX_STRING, stdin);
    buffer[strcspn(buffer, "\n")] = 0;
    return buffer;
}