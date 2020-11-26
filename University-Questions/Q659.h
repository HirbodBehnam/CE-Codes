#ifndef QUERA_Q659_H
#define QUERA_Q659_H

#endif //QUERA_Q659_H

#define MAX_BOOK_LENGTH 150
#define MAX_COMMAND_LENGTH 11

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/**
 * A book in the bookshelf
 */
struct Book {
    /**
     * The name of book
     */
    char *Name;
    /**
     * Next book in the list
     */
    struct Book *Next;
};

/**
 * Reads the next line from input and adds it to left side (first book)
 * @param first_book Pointer to the pointer of first book
 * @param last_book Pointer to the pointer of last book
 */
void add_book_left(struct Book **first_book, struct Book **last_book) {
    // At first read the book name
    char *book_name = malloc(MAX_BOOK_LENGTH * sizeof(char));
    size_t len = MAX_BOOK_LENGTH;
    getline(&book_name, &len, stdin);
    // Now add the book to the list
    struct Book *ptr = *first_book; // get the pointer to the first book; because we will loose track of it when we update first_book
    (*first_book) = malloc(sizeof(struct Book)); // create another book
    (*first_book)->Next = ptr; // give the address to next book
    (*first_book)->Name = book_name; // set the name of it
    // Check if this is also the last book (happens with empty list)
    if (*last_book == NULL)
        *last_book = *first_book;
}

/**
 * Reads the next line from input and adds it to right side (last book)
 * @param first_book Pointer to the pointer of first book
 * @param last_book Pointer to the pointer of last book
 */
void add_book_right(struct Book **first_book, struct Book **last_book) {
    // At first read the book name
    char *book_name = malloc(MAX_BOOK_LENGTH * sizeof(char));
    size_t len = MAX_BOOK_LENGTH;
    getline(&book_name, &len, stdin);
    // Now add the book to the list
    if (*last_book == NULL) { // prevent segmentation fault. Happens when the list is empty
        *last_book = malloc(sizeof(struct Book)); // Create the first and last book
        *first_book = *last_book;
    } else {  // if the list is not empty
        (*last_book)->Next = malloc(sizeof(struct Book)); // create a book at very left
        (*last_book) = (*last_book)->Next; // the book we created is now the the last book
    }
    (*last_book)->Next = NULL; // there is no next book; Is is the very left book
    (*last_book)->Name = book_name; // set the name of it
}

/**
 * Removes a book from memory
 * @param book The book to remove from memory
 */
void free_book(struct Book **book){
    free((*book)->Name); // free up the memory for book name
    free(*book); // remove the struct form memory
}

// I'm not sure if this implementation causes memory leak or not
int main() {
    char *command = malloc(MAX_COMMAND_LENGTH * sizeof(char));
    size_t l = MAX_COMMAND_LENGTH;
    getline(&command, &l, stdin);
    int n = atoi(command);
    int book_count = 0; // keep count of books for the result
    struct Book *first_book = NULL; // keeping track of first book
    struct Book *last_book = NULL; // keeping track of last book
    for (; n > 0; n--) {
        add_book_right(&first_book, &last_book);
        // We added a book!
        book_count++;
    }
    // Now read the commands
    while (1) {
        getline(&command, &l, stdin); // don't use scan because it will fuck up new lines
        if (strcmp(command, "Exit\n") == 0)
            break;
        if (strcmp(command, "AddLeft\n") == 0) {
            add_book_left(&first_book, &last_book);
            book_count++;
        } else if (strcmp(command, "AddRight\n") == 0) {
            add_book_right(&first_book, &last_book);
            book_count++;
        } else if (strcmp(command, "DeleteLeft\n") == 0) {
            struct Book *deleted_book = first_book; // get the pointer of first book to free it
            first_book = first_book->Next; // second book is now the first book
            free_book(&deleted_book);
            book_count--;
            /**
             * I think next line is needed.
             * I do not need to set the first_book because first_book->Next was NULL (it was the last book as well)
             * However, deleting the first book doesn't do anything to the last_book
             * So I'm pretty sure I need to assign last_book to NULL to tell functions that there is no book
             */
            if(book_count == 0)
                last_book = NULL;
        }
    }
    free(command);
    // Print what is in the list
    printf("%d\n", book_count);
    for (; book_count > 0; book_count--) { // this loop can also be written to break when it reaches NULL in pointer
        printf("%s",  // note that readline gets the '\n' char too. So we do not need to add \n to end of string
               first_book->Name);
        struct Book *ptr = first_book;
        first_book = first_book->Next;
        free_book(&ptr); // free the book from memory
    }
    return 0;
}