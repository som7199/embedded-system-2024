#include <stdio.h>
#include <stdlib.h>

typedef struct NODE {
  int data;
  struct NODE *next;
} node;

typedef struct {
  node *head;
} headNode;

headNode* createHeadNode(void)
{
  headNode* headnode = (headNode*)malloc(sizeof(headNode));
  if (headnode == NULL)
  {
    printf("NULL");
  }
  headnode->head = NULL;
  return headnode;
}

// 전위삽입 - 새 노드가 제일 앞으로!
void pre_addNode(headNode* pnode, int _data)
{
  node* newNode = (node*)malloc(sizeof(node));
  newNode->data = _data;
  newNode->next = pnode->head;    // headNode 자체가(headNode 필드의 head가) node를 가리키기 때문에 바로 노드 넣어줘도 됨 next 쓸 필요 없음!
  pnode->head = newNode;
}

// 후위삽입 - 새 노드를 제일 뒤로!
void rear_addNode(headNode *pnode, int _data)
{
  node* newNode = (node*)malloc(sizeof(node));
  newNode->data = _data;
  newNode->next = NULL;

  // 아무런 노드도 생성되지 않은 경우
  if(pnode->head == NULL)
  {
    pnode->head = newNode;
  }
  // 이미 생성된 노드들이 있는 경우
  else
  {
    node* curr = pnode->head;
    // 마지막 노드까지 순회하다가!
    while(curr->next != NULL){
      curr = curr->next;
    }
    // 마지막 노드에 새로운 노드 연결!!!
    curr->next = newNode;
  }
}

void showNode(headNode *pnode)
{
  node *curr = pnode->head;
  while (curr != NULL)
  {
    printf("%d\n", curr->data);
    curr = curr->next;
  }
}

void allFreeNode(headNode* pnode)   // 전체 메모리 해제
{
  node *curr = pnode->head;
  int a = 0;
  while (curr != NULL)
  {
    pnode->head = curr->next;
    free(curr);
    a++;
    printf("%d번째 노드 반환\n", a);
    curr = pnode->head;
  }
  free(pnode);    // head도 잊지말고 메모리 해제
}

void main()
{
  headNode* h = createHeadNode();

  pre_addNode(h, 10);
  pre_addNode(h, 20);
  pre_addNode(h, 30);
  pre_addNode(h, 40);
  pre_addNode(h, 50);

  rear_addNode(h, 60);
  rear_addNode(h, 70);
  rear_addNode(h, 80);
  rear_addNode(h, 90);

  showNode(h);
  allFreeNode(h);
}
