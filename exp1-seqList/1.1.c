#pragma clang diagnostic push
#pragma ide diagnostic ignored "cert-err34-c"
//
// Created by malossov on 22-11-12.
//
#include <stdio.h>

#ifndef EXP1_SEQLIST_1_1_C
#define EXP1_SEQLIST_1_1_C

#define MAX_LENGTH 20
#define DataTye int

/**题目要求：设计一个线性表的顺序存储结构，实现线性表的基本操作。
1. 首先创建一个顺序表：从键盘读入一组整数（长度小于等于20），按输入顺序放入顺序表，输入以－1结束（注意－1不放到顺序表内）；将创建好的顺序表元素依次输出到屏幕上。
2. 在已创建好的顺序表中插入一个元素：从键盘读入需插入的元素值和插入位置，调用插入函数完成插入操作；然后将顺序表元素依次输出到屏幕上。
3. 在已创建好的顺序表中删除一个元素：从键盘读入欲删除的元素位置（序号），调用删除函数完成删除操作；然后将顺序表元素依次输出到屏幕上。
 */
// 线性表结构体
typedef struct {
    DataTye data[MAX_LENGTH];
    int length;
} SeqList;

// 打印线性表
void printList(SeqList *list) {
    if (list->length == 0) {
        printf("线性表为空！\n");
        return;
    }
    printf("线性表长度为%d：", list->length);
    int i;
    for (i = 0; i < list->length; i++) {
        printf("%d ", list->data[i]);
    }
    putchar('\n');
}

// 初始化线性表
void InitList(SeqList *L) {
    printf("从键盘读入一组整数（长度小于等于20），按输入顺序放入顺序表，输入以－1结束:");
    int i = 0;
    while (i < MAX_LENGTH) {
        scanf("%d", &L->data[i]);
        if (L->data[i] == -1) {
            break;
        }
        i++;
    }
    L->length = i;
    printList(L);
}

// 插入元素
void InsertList(SeqList *L) {
    int i;
    DataTye x;
    printf("从键盘读入需插入的元素值和插入位置:");
    scanf("%d%d", &x, &i);

    if (L->length == MAX_LENGTH) {
        printf("线性表已满，无法插入！\n");
        return;
    }
    if (i < 1 || i > L->length + 1) {
        printf("插入位置不合法！\n");
        return;
    }
    int j;
    for (j = L->length; j >= i; j--) {
        L->data[j] = L->data[j - 1];
    }
    L->data[i - 1] = x;
    L->length++;
    printList(L);
}

// 删除元素
void DeleteList(SeqList *L) {
    int i;
    printf("从键盘读入欲删除的元素位置（序号）:");
    scanf("%d", &i);
    if (i < 1 || i > L->length) {
        printf("删除位置不合法！\n");
        return;
    }
    int j;
    for (j = i; j < L->length; j++) {
        L->data[j - 1] = L->data[j];
    }
    L->length--;
    printList(L);
}

#ifdef HAVE_MAIN

int main() {
    SeqList list;
    InitList(&list);
    char ch;
    while ((ch = (char) getchar())) {
        switch (ch) {
            case 'i':
                InsertList(&list);
                break;
            case 'd':
                DeleteList(&list);
                break;
            case 'q':
                printf("退出程序！\n");
                return 0;
            case 'p':
                printList(&list);
                break;
            default:
                break;
        }
        while (getchar() != '\n');
        printf("i:插入元素\td:删除元素\tq:退出\tp:打印\n");
    }
}

#endif
#endif
#pragma clang diagnostic pop