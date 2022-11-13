//
// Created by malossov on 22-11-13.
// 创建一个双向链表，按照冒泡排序的思路对这个双向链表进行排序，打印排序结果。注意，本算法在交换元素时是将链点整个交换而不是将链点中的元素值交换。
//

#include "stdio.h"
#include "stdlib.h"

typedef struct node {
    int data;
    struct node *prior;
    struct node *next;
} Node;

Node *createList(int n) {
    Node *head = NULL, *p = NULL, *q = NULL;
    int i;
    for (i = 0; i < n; i++) {
        p = (Node *) malloc(sizeof(Node));
        scanf("%d", &p->data);
        p->prior = NULL;
        p->next = NULL;
        if (head == NULL) {
            head = p;
        } else {
            q->next = p;
            p->prior = q;
        }
        q = p;
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

void sortList(Node *head) {
    Node *p = head, *q = NULL;
    int temp;
    while (p != NULL) {
        q = p->next;
        while (q != NULL) {
            if (p->data > q->data) {
                temp = p->data;
                p->data = q->data;
                q->data = temp;
            }
            q = q->next;
        }
        p = p->next;
    }
}

int main() {
    Node *head = NULL;
    head = createList(5);
    sortList(head);
    printList(head);
    return 0;
}