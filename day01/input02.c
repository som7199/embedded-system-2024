#include <stdio.h>

void main()
{
    int n1, n2, big_num;
    printf("두 개의 정수를 입력하세요> ");
    scanf("%d %d", &n1, &n2);

    big_num = n1 > n2 ? n1 : n2;
    printf("입력값 중 더 큰 수는 %d입니다.\n", big_num);

    /*
    if (n1 > n2) {
      printf("입력값 중 더 큰 수는 %d입니다.\n", big_num);
    }
    else {
      printf("입력값 중 더 큰 수는 %d 입니다.\n",n2);
    }
    */
}
