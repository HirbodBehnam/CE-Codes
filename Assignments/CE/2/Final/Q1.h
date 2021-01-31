#ifndef QUERA_Q1_H
#define QUERA_Q1_H

#endif //QUERA_Q1_H

#include <ctype.h>
#include <errno.h>
#include <stdio.h>
#include <string.h>

/**
 * A function to copy a file from src to dst while replacing all uppercase characters with lowercase, lowercase with uppercase
 * and do not touching anything else.
 * This function also automatically prints error messages and done message
 * @param src Source file path
 * @param dst Destination file path
 * @return Zero on success. Otherwise returns 1
 */
int copy_and_invert(const char *src, const char *dst) {
    // open files
    FILE *source = fopen(src, "r"); // read from this file
    if (source == NULL) {
        printf("Cannot open the source file: %d\n%s\n", errno, strerror(errno));
        return 1;
    }
    FILE *destination = fopen(dst, "w"); // write to this file; Overwrite the data
    if (source == NULL) {
        printf("Cannot open the destination file: %d\n%s\n", errno, strerror(errno));
        return 1;
    }
    // copy each char
    char ch;
    while ((ch = fgetc(source)) != EOF) { // read until "End of File"
        if (isupper(ch)) // convert uppercase to lowercase
            ch = tolower(ch);
        else if (islower(ch)) // convert lowercase to uppercase
            ch = toupper(ch);
        fputc(ch, destination); // write this char to file
    }
    // close files
    fclose(source);
    fclose(destination);
    puts("Copy is successful!");
    return 0;
}