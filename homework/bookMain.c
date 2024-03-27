/*
     File: bookMain.c

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

void main()
{
    headNode* h = createHead();

    while (true)
    {
        showMenu();
        int select = selectMenu();

        if (select == 1) {
            printf("\n****** 도서 등록 ******\n");
            addBook(h);
        }
        else if (select == 2) {
            printf("\n****** 도서 검색 ******\n");
            if (h->head == NULL) {
                printf("현재 도서가 없습니다.\n");
            }
            else {
                book* findBook = searchBook(h);     // 찾는 도서 반환
                if (findBook) {
                    printf("<%s>를 찾았습니다.\n", findBook->title);
                    if (findBook->borrow == 'y') {
                        char ans = 'x';
                        printf("해당 도서는 대여가 가능합니다. 대여하시겠습니까? (y/n) > ");
                        scanf("%s", &ans);

                        if (ans == 'y') {
                            findBook->borrow = 'n';     // 대여중인 상태로 바꾸기
                            printf("도서 대출이 완료되었습니다.\n");
                        }
                    }
                    else if (findBook->borrow == 'n') {
                        char ans = 'x';
                        printf("해당 도서는 대출 중입니다. 반납하시겠습니까? (y/n) > ");
                        scanf("%s", &ans);

                        if (ans == 'y') {
                            findBook->borrow = 'y';
                            printf("반납이 완료되었습니다.\n");
                        }
                    }
                }
                else {
                    printf("해당 도서가 없습니다.\n");
                }
            }
        }
        else if (select == 3) {
            printf("\n****** 도서 삭제 ******\n");
            if (h->head == NULL) {
                printf("현재 도서가 없습니다.\n");
            }
            else {
                book* delBook = searchBook(h);
                if (delBook == NULL) printf("해당 도서가 없습니다.\n");
                else deleteBook(h, delBook);
            }
        }
        else if (select == 4) {
            printf("\n****** 도서 목록 ******\n");
            if (h->head == NULL) {
                printf("현재 도서가 없습니다.\n");
            }
            printBook(h);
        }
        else if (select == 5) {
            printf("\n****** 도서 반납 ******\n");
            returnBook(h);
        }
        else if (select == 0)
        {
            printf("프로그램 종료!\n");
            break;
        }
        else
            printf("0 - 5 사이의 정수를 다시 입력해주세요\n");
    }
}