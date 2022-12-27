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
 * ����һ����������˳�����д�㷨���������Ԫ��ȫ�������š�������һ��Ԫ�طŵ���󡭡���
 * ������ص����Ż���������ԭ���ϣ�ֱ��ʵ�ַ��򡪡���������ʹ��һ���±�
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
                printf("�˳�����\n");
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
        printf("i:����Ԫ��\td:ɾ��Ԫ��\tq:�˳�\tp:��ӡ\tI:˳�����\tS:�����\tD:ɾ������\tR:��ת��\n");
    }
}

#endif

#pragma clang diagnostic pop
