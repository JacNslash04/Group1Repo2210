#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "r");

    if (file == NULL) {
        perror("Failed to open file");
        return 1;
    }

    int wordCount = 0;
    int inWord = 0;
    int c;

    while ((c = fgetc(file)) != EOF) {
        if (c == ' ' || c == '\t' || c == '\n' || c == '\r') {
            inWord = 0;
        } else if (!inWord) {
            inWord = 1;
            wordCount++;
        }
    }

    if (ferror(file)) {
        perror("File reading error");
    }

    fclose(file);

    printf("Word count: %d\n", wordCount);

    return 0;
}
