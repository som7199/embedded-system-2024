/* 배열로 구현 */
#include <stdio.h>
#include <stdbool.h>
#define STACK_SIZE 10
#define TRUE 1
#define FALSE 0

int stack[STACK_SIZE];
int top = -1;
int isFull();
int isEmpty();
void push();
int pop();

void main()
{
  push(3);
  push(5);
  push(10);
  printf("%d\n", pop());
  printf("%d\n", pop());
}

int isFull()
{
  if (top == STACK_SIZE - 1) return TRUE;
  else return FALSE;
}

int isEmpty()
{
  if (top <= -1) return TRUE;
  else return FALSE;
}

void push(int data)
{
  if(isFull())
  {
    printf("stack overflow!!!\n");
    return;
  }
  stack[++top] = data;
}

int pop()
{
  if(isEmpty())
  {
    printf("stack underflow!!!\n");
    return -1;
  }
  return stack[top--];
  //top--;
}
