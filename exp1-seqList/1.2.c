#pragma clang diagnostic push
#pragma ide diagnostic ignored "cert-err34-c"
//
// Created by malossov on 22-11-12.
//
#include <stdio.h>
#include "stdlib.h"
#include "1.1.c"

#ifndef EXP1_SEQLIST_1_2_C
#define EXP1_SEQLIST_1_2_C

/**
 *Ex1-2：
1. 在已经创建的元素为整数的顺序表中，从键盘输入一个整数，按照元素值大小，将新输入的元素插入到顺序表中
   注意该题中没有提供插入元素的具体位置，要根据元素值大小寻找合适的位置。
2. 输入一组数，建立顺序表，包括多个负数，编写算法删除其中所有的负数
   本题的特点是优化：怎样在一轮循环中删除，而不是每删除一个，都把后续元素搬移一次。
 */

// 对列表进行排序,使用归并排序的算法，时间复杂度为O(nlogn)，从小到大排序
void sortList(SeqList *L) {
    int i, j, k;
    for (i = 1; i < L->length; i *= 2) {
        for (j = 0; j < L->length - i; j += 2 * i) {
            int low = j, mid = j + i - 1, high = j + 2 * i - 1;
            if (high >= L->length) {
                high = L->length - 1;
            }
            int *temp = (int *) malloc((high - low + 1) * sizeof(int));
            int start1 = low, end1 = mid;
            int start2 = mid + 1, end2 = high;
            int m = 0;
            while (start1 <= end1 && start2 <= end2) {
                temp[m++] = L->data[start1] < L->data[start2] ? L->data[start1++] : L->data[start2++];
            }
            while (start1 <= end1) {
                temp[m++] = L->data[start1++];
            }
            while (start2 <= end2) {
                temp[m++] = L->data[start2++];
            }
            for (k = 0; k < high - low + 1; k++) {
                L->data[low + k] = temp[k];
            }
            free(temp);
        }
    }
}

// 按照元素值大小，将新输入的元素插入到顺序表中
void InsertByOrder(SeqList *L) {
    int i;
    DataTye x;
    printf("从键盘读入需插入的元素值:");
    scanf("%d", &x);

    if (L->length == MAX_LENGTH) {
        printf("线性表已满，无法插入！\n");
        return;
    }
    sortList(L);
    int j;
    for (j = 0; j < L->length; j++) {
        if (L->data[j] > x) {
            break;
        }
    }
    for (i = L->length; i > j; i--) {
        L->data[i] = L->data[i - 1];
    }
    L->data[j] = x;
    L->length++;
    printList(L);
}

// 删除负数,使用双指针的算法，时间复杂度为O(n)
void DeleteNegative(SeqList *L) {
    int i, j;
    for (i = 0, j = 0; i < L->length; i++) {
        if (L->data[i] >= 0) {
            L->data[j++] = L->data[i];
        }
    }
    L->length = j;
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
            default:
                break;
        }
        while (getchar() != '\n');
        printf("i:插入元素\td:删除元素\tq:退出\tp:打印\tI:顺序插入\tS:排序数组\tD:删除负数\n");
    }
}

#endif
#endif
#pragma clang diagnostic pop
