
#include <stdio.h>
#define MAX 20

void main()
{
  int arr[MAX];
  int num, inNum;

  printf("Input Data >> ");
  scanf("%d", &num);
  printf("배열 입력\n");
  for(int i = 0; i < num; i++) {
    scanf("%d", &inNum);
    arr[i] = inNum;
  }
  //배열 출력
  printf("순차 출력 > ");
  for(int i = 0; i < num; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");

  // 역순으로 출력
  printf("역순 출력 > ");
  for(int i = num - 1; i > -1; i--) {
    printf("%d ", arr[i]);
  }
  printf("\n");
}
