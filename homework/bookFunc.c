/*
     File: bookFunc.c

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

void showMenu()
{
    printf("\n****** �� �� ******\n");
    printf("1. ���� ���\n");
    printf("2. ���� �˻�/�뿩\n");
    printf("3. ���� ����\n");
    printf("4. ���� ���\n");
    printf("5. ���� �ݳ�\n");
    printf("0. ����\n");
}

int selectMenu()
{
    int select = 0;
    printf("���� > ");
    scanf("%d", &select);
    while (getchar() != '\n');   // ���۸� ���� ����! ���ڿ� �Է� �� ���ѷ����� ������ �� ������!
    return select;
}

headNode* createHead()
{
    headNode* headnode = (headNode*)malloc(sizeof(headNode));
    if (headnode == NULL) printf("NULL\n");
    headnode->head = NULL;
    return headnode;
}

// ���� ����
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
    // �� �ǵ� ��� �� �� ���
    if (curr == NULL) {
        pnode->head = newBook;
    }
    // å���� ��ϵǾ� ���� ���
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
        printf("�������� �Է��ϼ��� > ");
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
        printf("�ݳ��� �������� �Է��ϼ��� > ");
        scanf("%s", data);

        while (curr != NULL) {
            if (strcmp(curr->title, data) == 0) {
                if (curr->borrow == 'n') {
                    curr->borrow = 'y';
                    printf("�ݳ��� �Ϸ�Ǿ����ϴ�.\n");
                }
                else {
                    printf("�ش� ������ �������� �ƴմϴ�.\n");
                }
            }
            curr = curr->next;
        }
    }
    else printf("���� ������ �����ϴ�.\n");
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
        while (curr->next != pbook) {           // ������ ������ ã�� �������� ��ȸ!
            curr = curr->next;
        }
        curr->next = pbook->next;
        free(pbook);
    }
    /*
    // ��尡 �ϳ��� ���
    if (curr->next == NULL) {
        if (curr == pbook) {
            free(curr);
            pnode = NULL;
        }
    }
    // ù��° ��� ������ ���
    if (pnode->head == pbook) {
        pnode->head = pbook->next;
        free(pbook);
    }
    */
    
    /*
    // �ι�°������ ��� ������ ���
    else {
        while (curr != NULL) {
            curr2 = curr->next;
            if (curr2 == pbook) {
                if (curr2->borrow == 'n') {
                    printf("�ش� ������ �������Դϴ�. ������ �Ұ��մϴ�.\n");
                }
                else {
                    curr->next = curr2->next;
                    free(curr2);
                    printf("�ش� ������ �����Ǿ����ϴ�.\n");
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
    //while(curr->next != NULL) {       // ���� ������ ���� curr->next�� NULL�̶� ����� �ȵ�!
    while (curr != NULL) {              // curr(��带 ����Ű�ϱ�)�� ���� curr�� ������ ����ϱ�!
        printf("\n");
        printf("���� ID : %d\t", curr->id);
        printf("������ : %s\t", curr->title);
        printf("���� : %s\t", curr->author);
        printf("���ǻ� : %s\t", curr->publisher);
        printf("���� : %d\t", curr->price);
        printf("�뿩 ���� (%c)\t", curr->borrow);
        printf("\n");
        curr = curr->next;
    }
}