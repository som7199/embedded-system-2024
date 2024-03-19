#include "queue.h"
#include <stdio.h>
#include <stdbool.h>

extern linkQ* createLinkQ();
extern void enQueue(linkQ*, int);
extern void deQueue(linkQ*);
extern void printQ(linkQ*);
extern bool isEmpty(linkQ*);

void main()
{
  linkQ* lq = createLinkQ();
  enQueue(lq,10);
  enQueue(lq,20);
  enQueue(lq,30);
  printQ(lq);

  deQueue(lq);
  deQueue(lq);
  deQueue(lq);
  printQ(lq);
}
