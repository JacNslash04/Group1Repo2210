#include <stdio.h>
#include <stdlib.h>

int main() {

    char name[20];

    printf("\n\n   What is your name?\n");
    fgets(name, sizeof(name), stdin); //uses fgets for safer access <- GeeksForGeeks

    printf("\n\nHello, %10s \n", name);
    exit(0);
}
