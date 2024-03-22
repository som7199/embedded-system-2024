#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct BOOK {
  char id[20];
  char title[100];
  char author[100];
  int* price;
  struct BOOK* next;
} book;

typedef struct {
  book* head;
} headNode;

void showMenu();
int selectMenu();
headNode* createHead();
void addBook();
void searchBook();
void deleteBook();
void printBook();

void main()
{
  headNode* h = createHead();

  while(true)
  {
    showMenu();
    int select = selectMenu();

    if(select == 1) {
      printf("\n도서 등록을 시작합니다.\n");
      addBook(h);
    }
    else if(select == 2) printf("도서 검색\n");
      //searchBook();
    else if(select == 3) printf("도서 삭제\n");
      //deleteBook();
    else if(select == 4) {
      printf("\n도서 출력을 시작합니다.\n");
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
  printf("Book's price : ");
  scanf("%d",&(newBook->price));
  printf("\n");

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

/*
void searchBook()
{

}

void deleteBook()   // 메모리 해제도 같이 해주기
{

}
*/

void printBook(headNode* pnode)
{
  book* curr = pnode->head;
  while(curr != NULL) {
    printf("Book's ID : %s\n", curr->id);
    printf("Book's title : %s\n", curr->title);
    printf("author : %s\n", curr->author);
    printf("price : %d\n\n", curr->price);
    curr = curr->next;
  }
}
