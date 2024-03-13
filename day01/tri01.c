#include <stdio.h>

void main()
{
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 4; j++) {
            printf("*");
        }
        printf("\n");
    }
    printf("\n");

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j <= i; j++) {
            printf("*");
        }
        printf("\n");
    }
    printf("\n");

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5 - i; j++) {
            printf(" ");
        }
        for (int k = 0; k < (2 * i - 1); k++) {
            printf("*");
        }
        printf("\n");
    }

    int dan;
    printf("만들고 싶은 피라미드 단 > ");
    scanf("%d", &dan);

    for (int i = 0; i < dan + 1; i++) {
        for (int j = 0; j < dan + 1 - i; j++) {
            printf(" ");
        }
        for (int k = 0; k < (2 * i - 1); k++) {
            printf("*");
        }
        printf("\n");
    }

}
