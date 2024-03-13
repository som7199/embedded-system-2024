#include <stdio.h>

void main()
{
    int n;
    printf("정수 하나를 입력하세요: ");
    scanf("%d", &n);

    while (1) {
        if (n == 0) {
            printf("종료합니다.\n");
            break;
        }
        else if (n == 1) {
            printf("1을 입력하셨습니다.\n");
            break;
        }
        else if (n == 2) {
            printf("2를 입력하셨습니다.\n");
            break;
        }
        else {
            continue;
        }
    }
}
