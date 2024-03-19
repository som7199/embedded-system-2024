/* 순차 자료구조를 이용한 큐 자료구조 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define QSIZE 10

typedef struct {
  int front;
  int rear;
  char queue[QSIZE];
} queue;

queue* create();
void enqueue(queue*, char);
char dequeue(queue*);
bool isEmpty(queue*);
bool isFull(queue*);
void printQueue(queue*);

void main()
{
  queue* qa = create();
  enqueue(qa, 'A');
  enqueue(qa, 'B');
  enqueue(qa, 'C');
  enqueue(qa, 'D');

  printQueue(qa);
  printf("\n\n");

  printf("dequeue() : %c\n", dequeue(qa));
  printf("dequeue() : %c\n", dequeue(qa));

  printQueue(qa);
  printf("\n\n");

  printf("dequeue() : %c\n", dequeue(qa));
  printf("dequeue() : %c\n", dequeue(qa));

  printQueue(qa);
  printf("\n");
}

bool isFull(queue* pq)
{
  if(pq->rear == QSIZE - 1){
    printf("Queue Overflow!!!\n");
    return true;
  }
  else return false;
}

bool isEmpty(queue *pq)
{
  if(pq->rear == pq->front){
    printf("Queue Underflow!!!\n");
    return true;
  }
  else return false;
}

queue* create()
{
  // 동적할당
  queue* newQueue = (queue*)malloc(sizeof(queue));
  if(newQueue == NULL) exit(1);
  newQueue->front = -1;
  newQueue->rear = -1;
  return newQueue;
}

void enqueue(queue *pq, char data)
{
  if(isFull(pq)) return;
  pq->queue[++(pq->rear)] = data;
  // printf("%c\n", pq->queue[(pq->rear)]);
}

char dequeue(queue *pq)
{
  if(isEmpty(pq)) return 'X';
  return pq->queue[++(pq->front)];
}

void printQueue(queue *pq)
{
  printf("Queue =>  ");
  for (int i = (pq->front)+1; i <= pq->rear; i++) {
    printf("%c ", pq->queue[i]);
  }
}
