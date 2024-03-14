#include <stdio.h>
#include <stdlib.h>

typedef struct NODE {
  int data;
  struct NODE *next;    // 자기자신을 가리키는 구조체변수(자기참조구조체)
} node;
void main()
{
  node* head = (node*)malloc(sizeof(node));     // head 노드 :  첫번째 노드를>
  head->next = NULL;

  node* node1 = (node*)malloc(sizeof(node));    // 첫번째 노드
  node1->data = 10;
  node1->next = NULL;
  head->next = node1;

  node* node2 = (node*)malloc(sizeof(node));    // 두번째 노드
  node2->data = 20;
  node2->next = NULL;
  node1->next = node2;    // 두번째 노드 연결

  node* node3 = (node*)malloc(sizeof(node));
  node3->data = 30;
  node3->next = NULL;
  node2->next = node3;

  // curr이라는 노드 타입 포인터로 노드들에 접근!
  node* curr = head->next;    // 첫번째 노드를 가리키게 한다.
  while(curr != NULL) {
    printf("%d\n", curr->data);
    curr = curr->next;          // 다음 노드를 가리키게 됨!
  }

  free(node1);
  free(node2);
  free(node3);
}
