/*
     File: bookFunc.c

     Created: 24-03-27
     Author: 김소민
  */

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "book.h"
#define SIZE 100

void showMenu()
{
    printf("\n****** 메 뉴 ******\n");
    printf("1. 도서 등록\n");
    printf("2. 도서 검색/대여\n");
    printf("3. 도서 삭제\n");
    printf("4. 도서 출력\n");
    printf("5. 도서 반납\n");
    printf("0. 종료\n");
}

int selectMenu()
{
    int select = 0;
    printf("선택 > ");
    scanf("%d", &select);
    while (getchar() != '\n');   // 버퍼를 비우는 역할! 문자열 입력 시 무한루프에 빠지는 거 방지용!
    return select;
}

headNode* createHead()
{
    headNode* headnode = (headNode*)malloc(sizeof(headNode));
    if (headnode == NULL) printf("NULL\n");
    headnode->head = NULL;
    return headnode;
}

// 후위 삽입
void addBook(headNode* pnode)
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
    scanf("%d", &(newBook->price));
    printf("\n");

    newBook->borrow = 'y';
    newBook->next = NULL;

    book* curr = pnode->head;
    // 한 권도 등록 안 된 경우
    if (curr == NULL) {
        pnode->head = newBook;
    }
    // 책들이 등록되어 있을 경우
    else {
        while (curr->next != NULL) {
            curr = curr->next;
        }
        curr->next = newBook;
    }
}

book* searchBook(headNode* pnode)
{
    book* curr = pnode->head;
    if (curr != NULL) {
        char data[SIZE];
        printf("도서명을 입력하세요 > ");
        scanf("%s", data);

        while (curr != NULL) {
            if (strcmp(curr->title, data) == 0) {
                return curr;
            }
            curr = curr->next;
        }
    }
    return NULL;
}

void returnBook(headNode* pnode)
{
    book* curr = pnode->head;
    if (curr != NULL) {
        char data[SIZE];
        printf("반납할 도서명을 입력하세요 > ");
        scanf("%s", data);

        while (curr != NULL) {
            if (strcmp(curr->title, data) == 0) {
                if (curr->borrow == 'n') {
                    curr->borrow = 'y';
                    printf("반납이 완료되었습니다.\n");
                }
                else {
                    printf("해당 도서는 대출중이 아닙니다.\n");
                }
            }
            curr = curr->next;
        }
    }
    else printf("현재 도서가 없습니다.\n");
}

void deleteBook(headNode* pnode, book* pbook)
{
    int search = 0;
    book* curr = pnode->head;
    book* curr2;

    if (curr == pbook) {
        pnode->head = pbook->next;
        free(pbook);
    }
    else {
        while (curr->next != pbook) {           // 삭제할 도서를 찾을 때까지만 순회!
            curr = curr->next;
        }
        curr->next = pbook->next;
        free(pbook);
    }
    /*
    // 노드가 하나일 경우
    if (curr->next == NULL) {
        if (curr == pbook) {
            free(curr);
            pnode = NULL;
        }
    }
    // 첫번째 노드 삭제할 경우
    if (pnode->head == pbook) {
        pnode->head = pbook->next;
        free(pbook);
    }
    */
    
    /*
    // 두번째부터의 노드 삭제할 경우
    else {
        while (curr != NULL) {
            curr2 = curr->next;
            if (curr2 == pbook) {
                if (curr2->borrow == 'n') {
                    printf("해당 도서는 대출중입니다. 삭제가 불가합니다.\n");
                }
                else {
                    curr->next = curr2->next;
                    free(curr2);
                    printf("해당 도서가 삭제되었습니다.\n");
                }
            }
            curr = curr->next;
        }
    }
    */
}

void printBook(headNode* pnode)
{
    book* curr = pnode->head;
    //while(curr->next != NULL) {       // 제일 마지막 노드는 curr->next가 NULL이라서 출력이 안됨!
    while (curr != NULL) {              // curr(노드를 가리키니까)을 통해 curr의 값들을 출력하기!
        printf("\n");
        printf("도서 ID : %d\t", curr->id);
        printf("도서명 : %s\t", curr->title);
        printf("저자 : %s\t", curr->author);
        printf("출판사 : %s\t", curr->publisher);
        printf("가격 : %d\t", curr->price);
        printf("대여 여부 (%c)\t", curr->borrow);
        printf("\n");
        curr = curr->next;
    }
}