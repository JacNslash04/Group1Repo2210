#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <number>\n", argv[0]);
        return 1;
    }

    // Compile makeNBO.c and link with this test program
    char command[100];
    sprintf(command, "gcc makeNBO.c -o makeNBO");
    system(command);

    // Run the makeNBO program with the provided number
    sprintf(command, "./makeNBO %s", argv[1]);
    system(command);

    return 0;
}
