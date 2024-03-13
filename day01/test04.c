#include <stdio.h>
#define BUFSIZE 13

void main()
{
    char str[BUFSIZE] = "RaspberryPi!!";
    printf("%s\n", str);

    for (int i = 0; i < BUFSIZE; i++) {
        printf("%c ", str[i]);
    }
}
