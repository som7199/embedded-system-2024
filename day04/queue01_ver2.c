#include <stdio.h>
#define Q_SIZE 10

int rear = -1;
int front = -1;
int queue[Q_SIZE];

void enqueue(int _data)
{
  if(rear == Q_SIZE - 1) {
    printf("QUEUE OverFlow!!!\n");
    return;
  }
  queue[++rear] = _data;
}

int dequeue()
{
  if (front == rear)
  {
    printf("QUEUE UnderFlow!!!\n");
    return -1;
  }
  return queue[++front];
}

void main()
{
  enqueue(10);
  enqueue(20);
  enqueue(30);

  printf("%d\n", dequeue());    // 10
  printf("%d\n", dequeue());    // 20
  printf("%d\n", dequeue());    // 30
}
