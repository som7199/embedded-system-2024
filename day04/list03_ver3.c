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
  // if(newNode == NULL) return -1;
  if(newNode != NULL) {
    newNode->data = _data;
    newNode->next = pnode->head;    // headNode 자체가(headNode 필드의 head가) node를 가리키기 때문에 바로 노드 넣어줘도 됨 next 쓸 필요 없음!
    pnode->head = newNode;
  }
}

// 후위삽입 - 새 노드를 제일 뒤로!
void rear_addNode(headNode *pnode, int _data)
{
  node* newNode = (node*)malloc(sizeof(node));
  if(newNode != NULL) {
    newNode->data = _data;
    newNode->next = NULL;
  }

  // 아무런 노드도 생성되지 않은 경우
  if(pnode->head == NULL)
  {
    pnode->head = newNode;          // 첫번째 노드로 삽입
  }
  // 이미 생성된 노드들이 있는 경우
  else
  {
    node* curr = pnode->head;       // 마지막 노드를 찾는다.
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
    printf("%d ", curr->data);
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
  free(pnode);        // head도 잊지말고 메모리 해제
}

/* // 노드 검색 void 반환형
void searchNode(headNode* pnode, int _data){    // 노드 검색
  node* curr = pnode->head;
  int a = 0;
  while (curr != NULL) {
    if (curr->data == _data) {
      printf("검색한 노드는 %d번째 노드입니다!\n", a+1);
    }
    curr = curr->next;
    a++;
  }
}
*/

// 노드 검색 node* 반환
node* searchNode(headNode* pnode, int _data){   // 노드 검색
  node* curr = pnode->head;
  int a = 1;
  while (curr != NULL) {
    if (curr->data == _data) {
      printf("%d번째 노드에서 %d 발견\n", a, curr->data);
      return curr;
    }
    curr = curr->next;
    a++;
  }
}

/* 왕권이 코드
node* searchNode(headNode* pnode, int data) // data를 통한 노드 검색
{
  node*curr = pnode -> head;
  int a = 1;
  printf("[검색 시작!]\n");
  while(curr->data != data)
  {
    curr = curr -> next;
    a ++;
  }
  printf("%d번째 노드에서 data %d 발견!!\n",a,data);
  return curr;
}
*/

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
  printf("\n\n");

  node* searchResult = searchNode(h, 30);
  printf("찾은 데이터의 값은 %d입니다.\n", searchResult->data);
  searchNode(h, 10);
  searchNode(h, 90);
  printf("\n");

  allFreeNode(h);
}

