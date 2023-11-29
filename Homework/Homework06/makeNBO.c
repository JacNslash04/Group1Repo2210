#include <stdio.h>

unsigned int swapByteOrder(unsigned int num) {
    return ((num & 0xFF000000) >> 24) | ((num & 0x00FF0000) >> 8) |
           ((num & 0x0000FF00) << 8) | ((num & 0x000000FF) << 24);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <number>\n", argv[0]);
        return 1;
    }

    unsigned int inputNum;
    scanf(argv[1], "%u", &inputNum);

    unsigned int result = swapByteOrder(inputNum);

    printf("Original Number: %u\n", inputNum);
    printf("Number in Network Byte Order: %u\n", result);

    return 0;
}
