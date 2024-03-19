#ifndef QUEUE_H
#define QUEUE_H
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
#endif
