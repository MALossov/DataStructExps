#pragma clang diagnostic push
#pragma ide diagnostic ignored "cert-err34-c"
//
// Created by malossov on 22-11-12.
//
#include <stdio.h>

#include "1.1.c"
#include "1.2.c"

#define HAVE_MAIN

/**
 * 输入一组数，建立顺序表，编写算法将整个表的元素全部反序存放——即第一个元素放到最后……。
 * 本题的特点在优化，怎样在原表上，直接实现反序——即不额外使用一张新表
 */

void reverseList(SeqList *L) {
    int i, j;
    for (i = 0, j = L->length - 1; i < j; i++, j--) {
        int temp = L->data[i];
        L->data[i] = L->data[j];
        L->data[j] = temp;
    }
    printList(L);
}

#ifdef HAVE_MAIN

int main() {
    SeqList list;
    InitList(&list);
    char ch;
    while ((ch = (char) getchar())) {
        switch (ch) {
            case 'I':
                InsertByOrder(&list);
                break;
            case 'D':
                DeleteNegative(&list);
                break;
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
            case 'S':
                sortList(&list);
                break;
            case 'R':
                reverseList(&list);
                break;
            default:
                break;
        }
        while (getchar() != '\n');
        printf("i:插入元素\td:删除元素\tq:退出\tp:打印\tI:顺序插入\tS:排序表\tD:删除负数\tR:翻转表\n");
    }
}

#endif

#pragma clang diagnostic pop
