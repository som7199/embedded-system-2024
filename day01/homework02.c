#include <stdio.h>

int add(int a, int b)
{
    return a + b;
}

int minus(int a, int b)
{
    if (a > b) { return a - b; }
    else { return b - a; }
}

int multiple(int a, int b)
{
    return a * b;
}

float divide(int a, int b)
{
    return a / b;
}


void main()
{
    while (1) {
        int num1, num2;
        char op;
        printf("\n두 개의 정수를 입력하시오>");
        scanf("%d %d", &num1, &num2);
        printf("연산자를 입력하시오 > (종료는 X)");
        scanf(" %c", &op);        // 다시 보기!

        if (op == '+') {
            printf("%d", add(num1, num2));
        }
        else if (op == '-') {
            printf("%d", minus(num1, num2));
        }
        else if (op == '*') {
            printf("%d", multiple(num1, num2));
        }
        else if (op == '/') {
            printf("%.1f", divide(num1, num2));
        }
        else if (op == 'X') {
            printf("프로그램 종료\n");
            break;
        }
    }
}
