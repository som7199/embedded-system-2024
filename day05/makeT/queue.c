#include "queue.h"
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

bool isEmpty(linkQ* plq)
{
  if(plq->front == NULL) return true;
  else return false;
}

linkQ* createLinkQ()
{
  linkQ* lq = (linkQ*)malloc(sizeof(linkQ));
  if(lq == NULL) exit(1);
  lq->rear = NULL;
  lq->front = NULL;
  return lq;
}

void enQueue(linkQ* plq, int _data)
{
  node* newNode = (node*)malloc(sizeof(node));
  newNode->data = _data;
  newNode->link = NULL;

  // 노드가 하나도 생성되어있지 않은 경우
  // if(plq->front == plq->rear) 는 노드가 하나밖에 없는 경우와 동일하기에 쓰지 않음!
  if (plq->front == NULL)
  {
    plq->rear = newNode;
    plq->front = newNode;
  }
  // 노드가 이미 생성되어 있는 경우
  else
  {
    // 마지막 노드가 들어올 새 노드 가리키기
    plq->rear->link = newNode;
    // rear는 들어올 새 노드 가리키기
    plq->rear = newNode;
  }
}

void deQueue(linkQ* plq)
{
  if(isEmpty(plq)) {
    printf("Queue Underflow!!!\n");
  }
  node* curr = plq->front;
  plq->front = plq->front->link;
  printf("deQueue : %d / ", curr->data);
  free(curr);
  printf("메모리 반환 완료\n");
}

void printQ(linkQ* alq)
{
  printf("Queue : ");
  node* curr = alq->front;
  while(curr != NULL) {
    printf("%d ", curr->data);
    curr = curr->link;
  }
  printf("\n");
}
