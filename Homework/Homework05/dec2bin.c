/* 
* Authors: Group 1
* Program: dec2bin
* Description: Converts a decimal number to binary
*
* TO RUN: 
*      $ gcc -o dec2bin dec2bin.c
*      $ ./dec2bin
*/


#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <limits.h>

// Function to convert a decimal number to binary
void dec2bin(unsigned int num) {
    // Print each bit
    for (int i = 31; i >= 0; i--) {
        int bit = (num >> i) & 1; // Get specific bit to print
        printf("%d", bit);
        if (i % 4 == 0 && i != 0) { // Helps make binary more readable!
            printf(" ");
        }
    }
    printf("\n\n\n");
}

// Main function
int main(int argc, char *argv[]) {
    unsigned int num; // User's number
    char numString[12]; // String version of number

    // Check if the user has provided a command-line argument
    if (argc > 1) {
        char *endptr;
        errno = 0; // Clear error checking variable CITE: GEEKS4GEEKS
        num = strtoul(argv[1], &endptr, 10); // Convert string to unsigned long (base 10) 

        if (errno == ERANGE && num == UINT_MAX) {
            fprintf(stderr, "\nNumber is out of range for unsigned int.\n");
            return EXIT_FAILURE;
        }
        if (errno != 0) {
            perror("strtoul"); // Output error that occurred
            return EXIT_FAILURE;
        }
        if (*endptr != '\0') {
            fprintf(stderr, "\nInvalid input. Please enter a non-negative decimal number.\n");
            return EXIT_FAILURE;
        }
    } else {
        printf("\n\nEnter a non-negative decimal number: ");
        
        if (!fgets(numString, sizeof(numString), stdin)) { // Will be "true" if something goes wrong
            fprintf(stderr, "\nError reading input.\n");
            return EXIT_FAILURE;
        }
        
        char *endptr;
        errno = 0; // Clear error checking variable CITE: GEEKS4GEEKS
        num = strtoul(numString, &endptr, 10); // Convert string to unsigned long (base 10)

        if (errno == ERANGE && num == UINT_MAX) {
            fprintf(stderr, "\nNumber is out of range for unsigned int.\n");
            return EXIT_FAILURE;
        }
        if (errno != 0) {
            perror("strtoul"); // Output error that occurred
            return EXIT_FAILURE;
        }
        if (*endptr != '\n') {
            fprintf(stderr, "\nInvalid input. Please enter a non-negative decimal number.\n");
            return EXIT_FAILURE;
        }
    }

    // No errors!! We can print the binary number now :)
    printf("\nThe binary equivalent of %u is: \n\n\t > ", num);
    dec2bin(num);

    return EXIT_SUCCESS;
}


