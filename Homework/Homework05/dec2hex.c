/* 
* Authors: Group 1
* Program: dec2hex
* Description: Converts a decimal number to hex
*
* TO RUN: 
*      $ gcc -o dec2hex dec2hex.c
*      $ ./dec2hex
*/
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <limits.h>

// Function to convert a decimal number to hex
void dec2hex(unsigned long long num, int bits) {
    
    if (bits == 32) {
        printf("0x%08llX\n", num); //converts to hex and makes the output 8 digits long
    } else if (bits == 64) {
        printf("0x%016llX\n", num); //converts to hex and makes the output 16 digits long
    } else {
        fprintf(stderr, "Invalid number of bits. Please choose 32 or 64.\n"); //checks if bit is valid
        exit(EXIT_FAILURE);
    }
    printf("\n");
}

int main(int argc, char *argv[]) {
    unsigned long long num; //64 bit hex is HUGE so long long may be better
    int bits = 32; // default value

    if (argc > 1) { //number from command line
        char *endptr;
        errno = 0;
        num = strtoull(argv[1], &endptr, 10); //converts to base 10 long long
        if (errno == ERANGE && num == ULLONG_MAX) {
            fprintf(stderr, "\nNumber is out of range for unsigned long long.\n"); //i would be surprised if you did this
            return EXIT_FAILURE;
        }
        if (errno != 0) {
            perror("strtoull");
            return EXIT_FAILURE;
        }
        if (*endptr != '\0') {
            fprintf(stderr, "\nInvalid input. Please enter a non-negative decimal number.\n");
            return EXIT_FAILURE;
        }
    } else { //if there is no number from the command line
        char numString[21];
        printf("\nEnter a non-negative decimal number: ");
        if (!fgets(numString, sizeof(numString), stdin)) {
            fprintf(stderr, "\nError reading input.\n");
            return EXIT_FAILURE;
        }
        char *endptr;
        errno = 0;
        num = strtoull(numString, &endptr, 10);
        if (errno == ERANGE && num == ULLONG_MAX) {
            fprintf(stderr, "\nNumber is out of range for unsigned long long.\n");
            return EXIT_FAILURE;
        }
        if (errno != 0) {
            perror("strtoull");
            return EXIT_FAILURE;
        }
        if (*endptr != '\n') {
            fprintf(stderr, "\nInvalid input. Please enter a non-negative decimal number.\n");
            return EXIT_FAILURE;
        }
    }

    if (argc > 2) { // if there was a bit put into command line
        bits = atoi(argv[2]); // to integer
    } else { //if there was no input on command line
        printf("Enter the number of bits for the output hexadecimal value (32 or 64): ");
        scanf("%d", &bits);
    }

    if (bits == 32 && num > UINT_MAX) {
        fprintf(stderr, "\n\tError: The input number is too large to be represented in 32 bits.\n");
        printf("\tWe will change your number to 64 bits.\n\n");
        bits = 64;
    }


    printf("\nThe hexadecimal equivalent of %llu is: \n\n\t > ", num);
    dec2hex(num, bits);

    return EXIT_SUCCESS;
}
