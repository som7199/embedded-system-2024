/* 연결리스트로 구 현 */
#include <stdio.h>
#include <stdbool.h>
#define STACK_SIZE 3
#define TRUE 1
#define FALSE 0

typedef struct STACK {
  int buf[STACK_SIZE];
  int top;
} stack;

int isFull(stack*);
int isEmpty(stack*);
void push(stack*, int);
int pop(stack*);

void main()
{
  stack s;      // 구조체 변수!
  //stack* s;   // 구조체 변수를 가리키는 포인터
  s.top = -1;   // top을 -1로 해주자! 안그럼 push함수에서 top++ 하면서 뭔가 이상한 값이 top에 들어가는 듯..
  push(&s, 10);
  push(&s, 20);
  push(&s, 30);

  printf("pop() : %d\n", pop(&s));
  printf("pop() : %d\n", pop(&s));
  printf("pop() : %d\n", pop(&s));
  printf("pop() : %d\n", pop(&s));
}

int isFull(stack* pstk)
{
  if(pstk->top == STACK_SIZE-1) return TRUE;
  else return FALSE;
}

int isEmpty(stack* pstk)
{
  if(pstk->top <= -1) return 1;
  else return 0;
}

void push(stack* pstk, int value)
{
  if(isFull(pstk)) {
    printf("stack overflow!!!\n");
    return;
  }
  pstk->buf[++(pstk->top)] = value;     // top을 -1로 초기화해줬으니까 ++(pstk->top)으로 시작해주기!
  printf("%d\n", pstk->buf[pstk->top]);
  //pstk->top++;
  //printf("%d\n", pstk->top);
}

// 쓰레기값 하나 반환되는 문제,, s.top = -1로 초기화 해주니까 돌아감!
int pop(stack* pstk)
{
  if(isEmpty(pstk)) {
    printf("stack underflow!!!\n");
    return -1;
  }
  return pstk->buf[(pstk->top)--];    // pstk의 top값이 push()에서 1증가되어 있으니까 1 감소 해줘야 top에 있는 값이 나오겠지 소민아..

  /*아니면 이렇게 두 줄 써도 돼
  pstk->top--;
  data = pstk->buf[pstk->top];
  */
}
