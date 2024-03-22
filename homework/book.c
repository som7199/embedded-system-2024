
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#define SIZE 100

typedef struct BOOK {
  char id[20];
  char title[SIZE];
  char author[SIZE];
  char publisher[SIZE];
  int* price;
  char borrow;
  struct BOOK* next;
} book;


typedef struct {
  book* head;
} headNode;

void showMenu();
int selectMenu();
headNode* createHead();
void addBook(headNode*);
void searchBook(headNode*);
void deleteBook();
void printBook(headNode*);


void main()
{
  headNode* h = createHead();

  while(true)
  {
    showMenu();
    int select = selectMenu();

    if(select == 1) {
      printf("\n****** 도서 등록 ******\n");
      addBook(h);
    }
    else if(select == 2) {
      printf("\n****** 도서 검색 ******\n");
      searchBook(h);
    }
    else if(select == 3) printf("도서 삭제\n");
      //deleteBook();
    else if(select == 4) {
      printf("\n****** 현재 도서 목록 ******\n");
      printBook(h);
    }
    else if(select == 0)
    {
      printf("프로그램 종료!뿅!\n");
      break;
    }
    else
      printf("다시 입력해주세요");
  }
}

void showMenu()
{
  printf("**** 메 뉴 ****\n");
  printf("1. 도서 등록\n");
  printf("2. 도서 검색\n");
  printf("3. 도서 삭제\n");
  printf("4. 도서 출력\n");
  printf("0. 종료\n");
}

int selectMenu()
{
  int select;
  printf("선택 > ");
  scanf("%d", &select);
  return select;
}

headNode* createHead()
{
  headNode* headnode = (headNode*)malloc(sizeof(headNode));
  if(headnode == NULL) printf("NULL\n");
  headnode->head = NULL;
  return headnode;
}

// 후위 삽입
void addBook(headNode *pnode)
{
  book* newBook = (book*)malloc(sizeof(book));
  printf("Book's ID : ");
  scanf("%s", newBook->id);
  printf("Book's title : ");
  scanf("%s", newBook->title);
  printf("Book's author : ");
  scanf("%s", newBook->author);
  printf("Book's publisher : ");
  scanf("%s", newBook->publisher);
  printf("Book's price : ");
  scanf("%d",&(newBook->price));
  printf("\n");

  newBook->borrow = 'y';
  newBook->next = NULL;

  book* curr = pnode->head;
  // 한 권도 등록 안 된 경우
  if (curr == NULL){
    pnode->head = newBook;
  }
  // 책들이 등록되어 있을 경우
  else {
    while(curr->next != NULL) {
      curr = curr->next;
    }
    curr->next = newBook;
  }
}

// 검색한 도서 => 대여 여부 묻기(단, 대여 가능한 상태의 책인지 확인)
void searchBook(headNode* pnode)
{
  char data[SIZE];
  printf("검색하고 싶은 도서명 : ");
  scanf("%s", data);

  int a = 0;
  // 책을 찾자!
  book* curr = pnode->head;
  while(curr != NULL) {
    if(strcmp(curr->title, data) == 0) {
      printf("<%s>이 있습니다.\n\n", curr->title);
      a++;
    }
    curr = curr->next;
  }
  if (a == 0) printf("찾으시는 책이 없습니다.\n\n");
}

/*
void deleteBook()   // 메모리 해제도 같이 해주기
{

}
*/

void printBook(headNode* pnode)
{
  book* curr = pnode->head;
  //while(curr->next != NULL) {     // 제일 마지막 노드는 curr->next가 NULL이라서 출력이 안됨!
  while(curr != NULL) {             // curr(노드를 가리키니까)을 통해 curr의 값들을 출력하기!
    printf("Book's ID : %s\n", curr->id);
    printf("Book's title : %s\n", curr->title);
    printf("author : %s\n", curr->author);
    printf("publisher : %s\n", curr->publisher);
    printf("price : %d\n\n", curr->price);
    curr = curr->next;
  }
}

