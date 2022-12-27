#pragma clang diagnostic push
#pragma ide diagnostic ignored "cert-err34-c"
//
// Created by malossov on 22-11-13.
// 链表实验2.1
//
#ifndef EXP2_LINKLIST_2_1_C
#define EXP2_LINKLIST_2_1_C

#include <malloc.h>
#include "stdio.h"

/**
## Ex2-1:
1. 首先创建一个单链表：从键盘读入五个整数，按输入顺序形成单链表。将创建好的链表元素依次输出到屏幕上。
2. 在已创建好的链表中插入一个元素：从键盘读入元素值和插入位置，调用插入函数完成插入操作。然后将链表元素依次输出到屏幕上。
*/
typedef struct node {
    int data;
    struct node *next;
} Node;

Node *createList(int n) {
    Node *head = NULL, *p = NULL, *q = NULL;
    int i;
    for (i = 0; i < n; i++) {
        p = (Node *) malloc(sizeof(Node));
        scanf("%d", &p->data);
        p->next = NULL;
        if (head == NULL) {
            head = p;
        } else {
            q->next = p;
        }
        q = p;
    }
    return head;
}

// 从键盘读入元素值和插入位置，调用插入函数完成插入操作
Node *insertList(Node *head, int data, int pos) {
    Node *p = NULL, *q = NULL;
    int i;
    p = (Node *) malloc(sizeof(Node));
    p->data = data;
    p->next = NULL;
    if (pos == 1) {
        p->next = head;
        head = p;
    } else {
        q = head;
        for (i = 1; i < pos - 1; i++) {
            q = q->next;
        }
        p->next = q->next;
        q->next = p;
    }
    return head;
}

void printList(Node *head) {
    Node *p = head;
    while (p != NULL) {
        printf("%d ", p->data);
        p = p->next;
    }
    putchar('\n');
}

//#define HAVE_MAIN
#ifdef HAVE_MAIN

int main() {
    Node *head = NULL;
    int n, data, pos;
    printf("请输入链表元素：");
    head = createList(5);
    printf("链表元素为：");
    printList(head);
    printf("请输入插入元素：");
    scanf("%d", &data);
    printf("请输入插入位置：");
    scanf("%d", &pos);
    head = insertList(head, data, pos);
    printf("插入后链表元素为：");
    printList(head);
    return 0;
}

#endif
#endif
#pragma clang diagnostic pop