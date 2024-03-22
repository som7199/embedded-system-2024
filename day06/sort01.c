/*  오름차순 정렬하기 */
#include <stdio.h>

void main()
{
  int arr[] = {9, 4, 8, 15, 3, 7, 2, 1};
  int size = sizeof(arr)/sizeof(int);

  printf("arr : ");
  for(int i = 0; i < size; i++)
  {
    printf("%d ", arr[i]);
  }
  printf("\n");

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

  printf("sorted_arr: ");
  for(int i = 0; i < size; i++)
  {
    printf("%d ", arr[i]);
  }
  printf("\n");

  // printf("%d", sizeof(arr)/sizeof(int));
}
