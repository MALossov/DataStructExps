//
// Created by malossov on 22-11-13.
//
#ifndef EXP2_LINKLIST_2_2_C
#define EXP2_LINKLIST_2_2_C

#include "2.1.c"

#define HAVE_MAIN

/**
1. 创建一个单链表，其数据元素为整数，从键盘输入，输入0结束（注意0不放到链表内）；
2. 从键盘任意输入一个整数，在单链表中查询该数，如果单链表中已经存在这个数，就调用删除函数，删除该元素所在结点，并将单链表在删除前后的数据元素依次输出到屏幕上；
   如果单链表中不存在这个数，就调用插入函数，将这个数插入到单链表尾，并将单链表在插入前后的数据元素依次输出到屏幕上。
3. 在已经创建的元素为整数的链表中，从键盘输入一个整数，按照元素值大小，将新输入的元素插入到链表中。
 */
Node *Add2Tail(Node *List, int data) {
    Node *p = List;
    while (p != NULL && p->next != NULL) {
        p = p->next;
    }
    p->next = (Node *) malloc(sizeof(Node));
    p->next->data = data;
    p->next->next = NULL;
    return List;
}

Node *InitList(Node *List) {
    List = (Node *) malloc(sizeof(Node));
    List->next = NULL;
    return List;
}

/**
 * 从键盘输入，输入0结束（注意0不放到链表内）
 * @param List
 * @return List 链表头指针
 */
Node *InputList(Node *List) {
    // 从键盘输入，输入0结束（注意0不放到链表内）
    Node *head = List;
    int data;
    data = 1;
    while (data != 0) {
        scanf("%d", &data);
        if (data != 0) {
            List = Add2Tail(List, data);
        }
    }
    return List;
}

/**
 * 查询该数
 * @param List 头指针
 * @param data 被查询的数
 * @return 指针节点或NULL
 */
Node *SearchList(Node *List, int data) {
    Node *p = List;
    while (p != NULL) {
        if (p->data == data) {
            return p;
        }
        p = p->next;
    }
    return NULL;
}

/**
 * 在单链表中查询该数，如果单链表中已经存在这个数，就调用删除函数，删除该元素所在结点，并将单链表在删除前后的数据元素依次输出到屏幕上；
 * 如果单链表中不存在这个数，就调用插入函数，将这个数插入到单链表尾，并将单链表在插入前后的数据元素依次输出到屏幕上。
 * @param List 头指针
 * @param data 插入的数
 * @return 头节点
 */
Node *DeleteNode(Node *List, Node *p) {
    Node *q = List;
    if (List == p) {
        List = List->next;
        free(p);
        return List;
    }
    while (q->next != p) {
        q = q->next;
    }
    q->next = p->next;
    free(p);
    return List;
}

Node *PrintBeforeAndAfter(Node *List, int data) {
    Node *p = SearchList(List, data);
    if (p != NULL) {
        printf("找到了%d，删除它\n", data);
        printf("删除前：");
        printList(List);
        List = DeleteNode(List, p);
        printf("删除后：");
        printList(List);
    } else {
        printf("没找到%d，插入它\n", data);
        printf("插入前：");
        printList(List);
        List = Add2Tail(List, data);
        printf("插入后：");
        printList(List);
    }
    return List;
}

int CheckListOrder(Node *List) {
    Node *p = List;
    if (p == NULL) {
        return 1;
    }
    while (p->next != NULL) {
        if (p->data > p->next->data) {
            return 0;
        }
        p = p->next;
    }
    return 1;
}

/**
 * 按照元素值大小，将新输入的元素插入到链表中
 * @param List 头指针
 * @param data 查询的数
 * @return 头指针或空（无法找到）
 */
Node *InsertByOrder(Node *List, int data) {
    Node *p = List;
    if (CheckListOrder(List)) {
        while (p != NULL && p->next != NULL && p->next->data < data) {
            p = p->next;
        }
        // 头部特判
        if (p == List) {
            Node *q = (Node *) malloc(sizeof(Node));
            q->data = data;
            q->next = List;
            List = q;
        }
            // 尾部特判
        else if (p->next == NULL) {
            Node *q = (Node *) malloc(sizeof(Node));
            q->data = data;
            q->next = NULL;
            p->next = q;
        } else {
            // 中间插入
            Node *q = (Node *) malloc(sizeof(Node));
            q->data = data;
            q->next = p->next;
            p->next = q;
        }

        printf("插入后：");
        printList(List);
        return List;
    } else {
        printf("链表无序，无法插入\n");
        return NULL;
    }
}

#ifdef HAVE_MAIN

int main() {
    Node *head = NULL;
    int n, data, pos;
    printf("输入链表数据，以0结束：");
    head = InputList(head);
    char ch;
    printf("列表为：");
    printList(head);
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
            default:
                break;
        }
        while (getchar() != '\n');
        printf("i:顺序插入元素\ts:搜索元素\tq:退出\tp:打印\n");
    }
    return 0;
}

#endif
#endif