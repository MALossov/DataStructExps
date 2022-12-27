#pragma clang diagnostic push
#pragma ide diagnostic ignored "cert-err34-c"
//
// Created by malossov on 22-11-13.
// ����ʵ��2.1
//
#ifndef EXP2_LINKLIST_2_1_C
#define EXP2_LINKLIST_2_1_C

#include <malloc.h>
#include "stdio.h"

/**
## Ex2-1:
1. ���ȴ���һ���������Ӽ��̶������������������˳���γɵ������������õ�����Ԫ�������������Ļ�ϡ�
2. ���Ѵ����õ������в���һ��Ԫ�أ��Ӽ��̶���Ԫ��ֵ�Ͳ���λ�ã����ò��뺯����ɲ��������Ȼ������Ԫ�������������Ļ�ϡ�
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

// �Ӽ��̶���Ԫ��ֵ�Ͳ���λ�ã����ò��뺯����ɲ������
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
    printf("����������Ԫ�أ�");
    head = createList(5);
    printf("����Ԫ��Ϊ��");
    printList(head);
    printf("���������Ԫ�أ�");
    scanf("%d", &data);
    printf("���������λ�ã�");
    scanf("%d", &pos);
    head = insertList(head, data, pos);
    printf("���������Ԫ��Ϊ��");
    printList(head);
    return 0;
}

#endif
#endif
#pragma clang diagnostic pop