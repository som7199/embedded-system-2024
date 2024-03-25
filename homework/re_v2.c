#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#define SIZE 100

static int id;
typedef struct BOOK {
  int id;
  char title[SIZE];
  char author[SIZE];
  char publisher[SIZE];
  int* price;
  char borrow;    // 'y'이면 대출 가능
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
void deleteBook(headNode*);
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
    else if(select == 3)
      deleteBook(h);
    else if(select == 4) {
      printf("\n****** 도서 목록 ******\n");
      printBook(h);
    }
    else if(select == 0)
    {
      printf("프로그램 종료!\n");
      break;
    }
    else
      printf("0 - 4 사이의 정수를 다시 입력해주세요\n");
  }
}

void showMenu()
{
  printf("****** 메 뉴 ******\n");
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
  while(getchar() != '\n');   // 버퍼를 비우는 역할! 문자열 입력 시 무한루프에 빠지는 거 방지용!
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
  id++;
  newBook->id = id;
  printf("Book's ID : %d\n", newBook->id);
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
  char ans = 'x';
  book* curr = pnode->head;
  while(curr != NULL) {
    if(strcmp(curr->title, data) == 0) {
      a++;
      if (curr->borrow == 'y')
      {
        printf("찾으시는 <%s>이(가) 있습니다.\n", curr->title);
        printf("해당 도서를 대여하시겠습니까?(y/n)\n");
        scanf("%s", &ans);

        if(ans == 'y')
        {
          curr->borrow = 'n';
          printf("대여 완료!\n");
        }
      }
      else
      {
        printf("해당 도서는 현재 대출 중입니다.\n");
      }
    }
    curr = curr->next;
  }
  if (a == 0) printf("찾으시는 책이 없습니다.\n\n");
}

void deleteBook(headNode* pnode)
{
  char data[SIZE];
  printf("삭제하고 싶은 도서명 : ");
  scanf("%s", data);

  book* curr = pnode->head;   // 첫 번째 노드를 curr이 가리킴
  book* curr_prev = NULL;     // 아직 아무것도 안가리킴

  if(curr == NULL) {
    printf("삭제할 도서가 없습니다.\n");
  }
  else if (curr->next == NULL) {
    // 등록된 도서가 하나밖에 없는 경우
    if(strcmp(data, curr->title) == 0) {
      pnode->head = curr->next;
      printf("%s를 삭제하였습니다.\n", curr->title);
      free(curr);
    }
    else printf("삭제할 도서가 없습니다.\n");
  }
  else {
    while(curr->next->title != data) {
      curr = curr->next;
      //curr_prev = curr->next;
    }
    curr_prev = curr->next;
    curr->next = curr->next->next;
    free(curr_prev);
  }
}

void printBook(headNode* pnode)
{
  book* curr = pnode->head;
  //while(curr->next != NULL) {     // 제일 마지막 노드는 curr->next가 NULL이라서 출력이 안됨!
  while(curr != NULL) {             // curr(노드를 가리키니까)을 통해 curr의 값들을 출력하기!
    printf("\n");
    printf("도서 ID : %d\n", curr->id);
    printf("도서명 : %s\n", curr->title);
    printf("저자 : %s\n", curr->author);
    printf("출판사 : %s\n", curr->publisher);
    printf("가격 : %d\n", curr->price);
    printf("대여 여부 (%c)\n\n", curr->borrow);
    curr = curr->next;
  }
}
