//
// Created by malossov on 22-11-13.
//
#include "2.2.c"

#ifndef EXP2_LINKLIST_2_3_1_C
#define EXP2_LINKLIST_2_3_1_C
/**
* 1. 删除单链表中全部的负数
*/

//#define HAVE_MAIN

Node *DeleteNegative(Node *List) {
    Node *p = List;
    Node *q;
    while (p != NULL) {
        if (p->data < 0) {
            q = p;
            p = p->next;
            List = DeleteNode(List, q);
        } else {
            p = p->next;
        }
    }
    printList(List);
    return List;
}

#ifdef HAVE_MAIN

int main() {
    Node *head = NULL;
//    head = InitList(head);
    int n, data, pos;
    printf("输入链表数据，以0结束：");
    head = InputList(head);
    char ch;
    while ((ch = (char) getchar())) {
        switch (ch) {
            case 's':
                printf("输入要查询的数：");
                scanf("%d", &data);
                head = PrintBeforeAndAfter(head, data);
                break;
            case 'q':
                printf("退出程序！\n");
                return 0;
            case 'p':
                printList(head);
                break;
            case 'i':
                printf("输入要插入的数：");
                scanf("%d", &data);
                head = InsertByOrder(head, data);
                break;
            case 'D':
                head = DeleteNegative(head);
            default:
                break;
        }
        while (getchar() != '\n');
        printf("i:顺序插入元素\ts:搜索元素\tq:退出\tp:打印\tD:删除链表中的所有负数\n");
    }
    return 0;
}

#endif

#endif //EXP2_LINKLIST_2_3_1_C