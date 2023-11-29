#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

extern int GCDfinder(int a, int b);

int main(int argc, char *argv[]) {
    assert(argc == 3);

    int num1 = atoi(argv[1]);
    int num2 = atoi(argv[2]);

    assert(num1 > 0);
    assert(num2 > 0);

    int result = GCDfinder(num1, num2);
    printf("The GCD of %d and %d is %d\n", num1, num2, result);

    return 0;
}
