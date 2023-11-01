#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    // Check for the correct number of command line arguments.
    if (argc != 2) {
        printf("Usage: %s <N>\n", argv[0]);
        return 1;
    }

    // Convert the second command line argument to an integer.
    int N = atoi(argv[1]);

    // Check if N is less than 2, and if so, display an error message and exit.
    if (N < 2) {
        printf("N must be at least 2.\n");
        return 1;
    }

    // Print the header row for the table.
    printf("   |");
    for (int i = 2; i <= N; i++) {
        printf("%5d", i);
    }
    printf("\n");

    // Print the separator line.
    for (int i = 0; i <= N; i++) {
        printf("-----");
    }
    printf("\n");

    // Print the times tables.
    for (int i = 2; i <= N; i++) {
        printf("%2d |", i);
        for (int j = 2; j <= N; j++) {
            // Print the product of i and j with appropriate spacing.
            printf("%5d", i * j);
        }
        printf("\n");
    }

    return 0;
}