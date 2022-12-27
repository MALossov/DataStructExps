//
// Created by malossov on 22-11-13.
// ����һ��˫����������ð�������˼·�����˫������������򣬴�ӡ��������ע�⣬���㷨�ڽ���Ԫ��ʱ�ǽ������������������ǽ������е�Ԫ��ֵ������
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
    // ӵ�ж�����ͷ���

    int i;
    for (i = 0; i < n; i++) {
        p = (Node *) malloc(sizeof(Node));
        scanf("%d", &p->data);
        p->prior = NULL;
        p->next = NULL;
        if (head == NULL) {
            head = (Node *) malloc(sizeof(Node));
            head->prior = NULL;
            p->prior = head;
            head->next = p;
        } else {
            q->next = p;
            p->prior = q;
        }
        q = p;
    }
    return head;
}

void printList(Node *head) {
    Node *p = head->next;
    while (p != NULL) {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}


void swap(Node *left, Node *right) {
    Node *temp;
    if (right->next == NULL) //t����Ƿ�Ϊβ���
    {
        if (left->next == right) //p,t����Ƿ�����
        {
            //��β������ڵĽ�����
            right->next = left;
            right->prior = left->prior;
            left->next = NULL;
            left->prior->next = right;
            left->prior = right;
        } else {
            //��β��㲻���ڵĽ�����
            right->next = left->next;
            right->prior->next = left;
            temp = right->prior;
            right->prior = left->prior;
            left->next->prior = right;
            left->next = NULL;
            left->prior->next = right;
            left->prior = temp;
        }
    } else {
        if (left->next == right) //p,t����Ƿ�����
        {
            //���ڵĽ�����
            right->next->prior = left;
            temp = right->next;
            right->next = left;
            right->prior = left->prior;
            left->next = temp;
            left->prior->next = right;
            left->prior = right;
        } else {
            //�����ڵĽ�����
            right->next->prior = left;
            temp = right->next;
            right->next = left->next;
            left->next->prior = right;
            left->next = temp;
            right->prior->next = left;
            temp = right->prior;
            right->prior = left->prior;
            left->prior->next = right;
            left->prior = temp;
        }
    }
}


void sortList(Node *head) {
    Node *p = head, *q = NULL;
    int temp;
    while (p != NULL) {
        Node *tmpQN;
        q = p->next;
        while (q != NULL) {
            printf("p->data=%d,q->data=%d:", p->data, q->data);
            if (p->data > q->data) {
                Node *tmpQ = q;
                tmpQN = q->next;
                printf("BeforeSwap:");
                printList(head);
                swap(p, q);
                printf("AfterSwap:");
                printList(head);
                q = tmpQN;
                p = tmpQ;
                continue;
            }
            q = q->next;
            printf("Normal:");
            printList(head);
        }
        p = p->next;
    }
}

int main() {
    Node *head = NULL;
    head = createList(4);
    sortList(head);
    printList(head);
    return 0;
}