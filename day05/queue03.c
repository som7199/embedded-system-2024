/* 연결 자료구조를 이용한 큐 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct NODE {
  int data;
  struct NODE *link;
} node;

typedef struct {
  node* rear;       // 새로 들어올 노드를 가리킴(가리키기만 하는 애!) 배열로 만들었을 때랑 달리 ++ 필요 없음!
  node* front;      // 나갈 노드를 가리킴
} linkQ;

linkQ* createLinkQ();
void enQueue(linkQ*, int);
void deQueue(linkQ*);
void printQ(linkQ*);
bool isEmpty(linkQ*);

void main()
{
  linkQ* lq = createLinkQ();
  enQueue(lq,10);
  enQueue(lq,20);
  enQueue(lq,30);
  printQ(lq);

  deQueue(lq);
  deQueue(lq);
  printQ(lq);
}

bool isEmpty(linkQ* plq)
{
  if(plq->rear == plq->front) return true;
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
