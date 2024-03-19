#include <stdio.h>
#define Q_SIZE 10

// 배열 이름은 주소니까!
void enqueue(int* pqueue, int* _rear, int _data)
{
  if(_rear == Q_SIZE - 1) {
    printf("QUEUE OVERFLOW!!!");
    return;
  }
  pqueue[++*(_rear)] = _data;
}

void main()
{
  int rear = -1;
  int front = -1;
  int queue[Q_SIZE];

  enqueue(queue, &rear, 10);
  enqueue(20);
}
