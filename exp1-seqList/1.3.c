#pragma clang diagnostic push
#pragma ide diagnostic ignored "cert-err34-c"
//
// Created by malossov on 22-11-12.
//
#include <stdio.h>
#include <malloc.h>

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

#pragma clang diagnostic pop
