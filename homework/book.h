#pragma once
/*
     File: book.h

     Created: 24-03-27
     Author: ±Ëº“πŒ
  */

#define _CRT_SECURE_NO_WARNINGS
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
    char borrow;    // 'y'¿Ã∏È ¥Î√‚ ∞°¥…
    struct BOOK* next;
} book;

typedef struct {
    book* head;
} headNode;

void showMenu();
int selectMenu();
headNode* createHead();
void addBook(headNode*);
book* searchBook(headNode*);
void returnBook(headNode*);
void deleteBook(headNode*, book*);
void printBook(headNode*);