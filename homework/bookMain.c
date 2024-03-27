/*
     File: bookMain.c

     Created: 24-03-27
     Author: ��ҹ�
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
            printf("\n****** ���� ��� ******\n");
            addBook(h);
        }
        else if (select == 2) {
            printf("\n****** ���� �˻� ******\n");
            if (h->head == NULL) {
                printf("���� ������ �����ϴ�.\n");
            }
            else {
                book* findBook = searchBook(h);     // ã�� ���� ��ȯ
                if (findBook) {
                    printf("<%s>�� ã�ҽ��ϴ�.\n", findBook->title);
                    if (findBook->borrow == 'y') {
                        char ans = 'x';
                        printf("�ش� ������ �뿩�� �����մϴ�. �뿩�Ͻðڽ��ϱ�? (y/n) > ");
                        scanf("%s", &ans);

                        if (ans == 'y') {
                            findBook->borrow = 'n';     // �뿩���� ���·� �ٲٱ�
                            printf("���� ������ �Ϸ�Ǿ����ϴ�.\n");
                        }
                    }
                    else if (findBook->borrow == 'n') {
                        char ans = 'x';
                        printf("�ش� ������ ���� ���Դϴ�. �ݳ��Ͻðڽ��ϱ�? (y/n) > ");
                        scanf("%s", &ans);

                        if (ans == 'y') {
                            findBook->borrow = 'y';
                            printf("�ݳ��� �Ϸ�Ǿ����ϴ�.\n");
                        }
                    }
                }
                else {
                    printf("�ش� ������ �����ϴ�.\n");
                }
            }
        }
        else if (select == 3) {
            printf("\n****** ���� ���� ******\n");
            if (h->head == NULL) {
                printf("���� ������ �����ϴ�.\n");
            }
            else {
                book* delBook = searchBook(h);
                if (delBook == NULL) printf("�ش� ������ �����ϴ�.\n");
                else deleteBook(h, delBook);
            }
        }
        else if (select == 4) {
            printf("\n****** ���� ��� ******\n");
            if (h->head == NULL) {
                printf("���� ������ �����ϴ�.\n");
            }
            printBook(h);
        }
        else if (select == 5) {
            printf("\n****** ���� �ݳ� ******\n");
            returnBook(h);
        }
        else if (select == 0)
        {
            printf("���α׷� ����!\n");
            break;
        }
        else
            printf("0 - 5 ������ ������ �ٽ� �Է����ּ���\n");
    }
}