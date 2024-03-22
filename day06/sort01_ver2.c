/* 오름차순 정렬 함수 (버블 정렬) */
#include <stdio.h>

int* bubSort(int *arr, int size)
{
  // printf("%d\n", sizeof(arr)); // 포인터 변수의 크기는 8byte!
  // int asize = sizeof(arr)/sizeof(int); // 그래서 size가 2가 됨 ㅠ
  // printf("%d\n", asize);
  for(int i = 0; i < size - 1; i++)
  {
    for(int j = 0; j < size - 1; j++)
    {
      if(arr[j] > arr[j + 1])
      {
        int temp = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = temp;
      }
    }
  }
  return arr;
}

void main()
{
  int arr[] = {9, 4, 8, 15, 3, 7, 2, 1, 30, 5};
  int size = sizeof(arr)/sizeof(int);

  printf("arr : ");
  for(int i = 0; i < size; i++)
  {
    printf("%d ", arr[i]);
  }
  printf("\n");

  printf("sorted_arr: ");
  int *sorted_arr = bubSort(arr, size);

  for(int i = 0; i < size; i++)
  {
    printf("%d ", sorted_arr[i]);
  }
  printf("\n");
}
