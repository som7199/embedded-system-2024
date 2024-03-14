#include <stdio.h>
#include <stdlib.h>

typedef struct NODE {
  int data;
  struct NODE *next;
} node;

// 전위삽입 - 새 노드가 제일 앞으로!
void pre_addNode(node* pnode, int _data)
{
  node* newNode = (node*)malloc(sizeof(node));
  newNode->data = _data;
  newNode->next = pnode->next;
  pnode->next = newNode;
}
// 후위삽입 - 새 노드를 제일 뒤로!
void rear_addNode(node *pnode, int _data)
{
  node* newNode = (node*)malloc(sizeof(node));
  newNode->data = _data;
  newNode->next = NULL;

  // 아무런 노드도 생성되지 않은 경우
  if(pnode->next == NULL)
  {
    pnode->next = newNode;
  }
  // 이미 생성된 노드들이 있는 경우
  else
  {
    node* curr = pnode->next;
    // 마지막 노드까지 순회하다가!
    while(curr->next != NULL){
      curr = curr->next;
    }
    // 마지막 노드에 새로운 노드 연결!!!
    curr->next = newNode;
  }
}


void showNode(node *pnode)
{
  node *curr = pnode->next;
  while (curr != NULL)
  {
    printf("%d\n", curr->data);
    curr = curr->next;
  }
}

void main()
{
  node* head = (node*)malloc(sizeof(node));
  head->next = NULL;

  pre_addNode(head, 10);
  pre_addNode(head, 20);
  pre_addNode(head, 30);
  pre_addNode(head, 40);
  pre_addNode(head, 50);

  rear_addNode(head, 60);
  rear_addNode(head, 70);
  rear_addNode(head, 80);
  rear_addNode(head, 90);
  /*
  node* curr = head->next;
  while(curr != NULL){
    printf("%d\n", curr->data);
    curr = curr->next;
  }
  */
  showNode(head);

  // 맨 앞의 노드부터 free(),
  // 그럼 맨 앞의 노드가 가리키는 다음 노드를 head로!
  // head를 이동시키면서 차례대로 free() 해주기
  node* curr = head->next;    // curr은 첫번째 노드를 가리킴
  while(curr != NULL) {
    head->next = curr->next;  // 두번째 노드가 첫번째 노드가 됨!
    free(curr);               // 첫번째 노드 free()
    curr = head->next;        // 이제 curr은 두번째 노드
  }

  printf("%d\n", head->next); // 0 출력 (NULL)
  free(head);     // head도 잊지말고 free()
  printf("%d\n", curr);       // 0 출력
  printf("%d\n", curr->data); // Segmentation fault : 잘못된 메모리 참조 때문>
}

