/* 순차탐색 */
#include <stdio.h>

int lSearch(int *arr, int size, int data)
{
  for (int i = 0; i < size; i++)
  {
    if(arr[i] == data) return i;
  }
  return -1;
}

void main()
{
  int arr[] = {3, 5, 2, 4, 9, 8, 1};
  int size = sizeof(arr) / sizeof(arr[0]);
  int ridx;
  ridx = lSearch(arr, size, 9);
  if (ridx == -1) printf("찾는 원소가 없습니다.\n");
  else {
    printf("찾은 인덱스 : %d\n", ridx);
    //printf("찾는 데이터는 %d번째에 있습니다.\n", ridx + 1);
  }
}
