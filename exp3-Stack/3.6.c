#pragma clang diagnostic push
#pragma ide diagnostic ignored "cert-err34-c"
/**
计算并输出二项展开式（a+b）n的各项系数，即求一个杨辉三角形的最下面一层所有元素。
本题算法难点在利用杨辉三角形计算原理，不断利用队列在上一层元素的基础上，求出下一层元素。
*/

#include "stdio.h"
#include "stdlib.h"

// 创建fifo队列
typedef struct node {
    int data;
    struct node *next;
} Node;

Node *createQueue() {
    Node *head = NULL, *p = NULL, *q = NULL;
    int i, n;
    scanf("%d", &n);
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

//
void createTopRow(Node *head) {
    // 创建杨辉三角形的第一行
    Node *p = head;
    while (p->next != NULL) {
        p = p->next;
    }
    p->next = (Node *) malloc(sizeof(Node));
    p->next->data = 1;
    p->next->next = NULL;
}

// 打印队列
void printQueue(Node *head) {
    Node *p = head;
    while (p != NULL) {
        printf("%d ", p->data);
        p = p->next;
    }
    putchar('\n');
}

// 从队列中取出一个元素
int dequeue(Node **head) {
    Node *p = *head;
    int data;
    if (p == NULL) {
        return -1;
    }
    data = p->data;
    *head = p->next;
    free(p);
    return data;
}

// 向队列中添加一个元素
void enqueue(Node **head, int data) {
    Node *p = *head, *q = NULL;
    while (p != NULL) {
        q = p;
        p = p->next;
    }
    p = (Node *) malloc(sizeof(Node));
    p->data = data;
    p->next = NULL;
    if (q == NULL) {
        *head = p;
    } else {
        q->next = p;
    }
}

// 计算并输出二项展开式（a+b）n的各项系数，即求一个杨辉三角形的最下面一层所有元素。
void printBinomialExpansion(int n) {
    Node *head = NULL;
    int i, j, data, temp;
//    head = createQueue();
    head = (Node *) malloc(sizeof(Node));
    head->data = 1;
    head->next = NULL;
//    createTopRow(head);
    for (i = 0; i < n; i++) {
        for (j = 0; j < i + 1; j++) {
            data = dequeue(&head);
            if (j == 0) {
                enqueue(&head, data);
            } else {
                enqueue(&head, data + temp);
            }
            temp = data;
        }
        enqueue(&head, 1);
    }
    printQueue(head);
}

int main() {
    int n;
    scanf("%d", &n);
    printBinomialExpansion(n);
    return 0;
}

#pragma clang diagnostic pop