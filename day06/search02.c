/* 이진 탐색  - 단, 정렬이 되어 있어야함! */
#include <stdio.h>

int binarySearch(int* arr, int size, int target)
{
  int first = 0;
  int last = size;
  while(first <= last)
  {
    int middle = (first + last) / 2;
    if(target == arr[middle]) return middle;
    else
    {
      if(target > arr[middle]) first = middle + 1;
      else last = middle - 1;
    }
  }
  return -1;
}

void main()
{
  int arr[] = {1, 2, 3, 4, 5, 6, 7, 8};
  int size = sizeof(arr) / sizeof(int);
  printf("찾는 데이터의 인덱스 : %d\n", binarySearch(arr, size, 7));
}
