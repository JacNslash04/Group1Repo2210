#include <stdio.h>
#include <ctype.h>

int main( int argc, char * argv[] ) {
    printf("Enter Word or Phrase: \n");
    char str[1000];
    int len = 0;
    fgets(str, 1000, stdin);
    for (int i = 0; str[i] != '\0'; ++i){ // gets length of string
        len++;
    }
    printf("\n");

    int j =0;
    char ch;
    while (str[j]) { // makes each char in our string lowercase
        ch = str[j];
        putchar(tolower(ch));
        j++;
    }

    char nato[26][10] = { "alpha", "bravo", "charlie", "delta", "echo", "foxtrot", "golf", "hotel",
                         "india", "juliett", "kilo", "lima", "mike", "november", "oscar", "papa",
                         "quebec", "romeo", "sierra", "tango", "uniform", "victor", "whiskey",
                         "xray", "yankee", "zulu" };

    char alphabet[26] = "abcdefghijklmnopqrstuvwxyz";

    for(int i = 0; i <= len; i++){ // nested forloop iterates through each char of string and prints correlating nato element
        for(int j = 0; j < 26; j++){
            if(str[i] == alphabet[j]){
                printf("\n");
                printf("%s", nato[j] );
            }
        }
    }
    return 0;
}