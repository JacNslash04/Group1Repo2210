# include <stdio.h>

int main() {
    unsigned int num = 1;
    char *endianCheck = (char*)&num;

    if (*endianCheck == 1){
        printf("This computer is Little-Endian. \n");
    }
    else{
        printf("This computer is Big Endian. \n");
    }

    return 0;
}