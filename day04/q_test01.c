#include <stdio.h>

void main()
{
  int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  int queue[20];
  int rear = 0, front = 0;    // 입구(rear)로 삽입하고, 출구(front)를 통해서 삭제한다.

  int size = sizeof(arr) / sizeof(arr[0]);
  // printf("%d\n", size);    // 10

  // 큐에 삽입
  for(int i = 0; i < size; i++) {
    queue[rear++] = arr[i];
  }

  // 큐에서 삭제
  for(int i = 0; i < size; i++) {
    printf("%d\n", queue[front++]);
  }
}
