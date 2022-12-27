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
 *Ex1-2��
1. ���Ѿ�������Ԫ��Ϊ������˳����У��Ӽ�������һ������������Ԫ��ֵ��С�����������Ԫ�ز��뵽˳�����
   ע�������û���ṩ����Ԫ�صľ���λ�ã�Ҫ����Ԫ��ֵ��СѰ�Һ��ʵ�λ�á�
2. ����һ����������˳������������������д�㷨ɾ���������еĸ���
   ������ص����Ż���������һ��ѭ����ɾ����������ÿɾ��һ�������Ѻ���Ԫ�ذ���һ�Ρ�
 */

// ���б��������,ʹ�ù鲢������㷨��ʱ�临�Ӷ�ΪO(nlogn)����С��������
void sortList(SeqList *L) {
    int i, j, k;
    //����2��forΪһ���򵥵Ķ�������ж��ַָ�ķ���
    for (i = 1; i < L->length; i *= 2) {
        for (j = 0; j < L->length - i; j += 2 * i) {
            //ѡ�����ֲ��ҵ��е�ͷβ���м�
            int low = j, mid = j + i - 1, high = j + 2 * i - 1;
            //����β�ڵ��ڶ���֮��
            if (high >= L->length) {
                high = L->length - 1;
            }
            //���ݵ�ǰ���ҷ�Χ���¿�������
            int *temp = (int *) malloc((high - low + 1) * sizeof(int));
            int start1 = low, end1 = mid;
            int start2 = mid + 1, end2 = high;
            int m = 0;
            // ��һ����ѡ��Сֵ
            while (start1 <= end1 && start2 <= end2) {
                temp[m++] = L->data[start1] < L->data[start2] ? L->data[start1++] : L->data[start2++];
            }
            //�鲢������㷨����
            //������3���ǽ�������ֵ�������뵽ԭʼ����
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

// ����Ԫ��ֵ��С�����������Ԫ�ز��뵽˳�����
void InsertByOrder(SeqList *L) {
    int i;
    DataTye x;
    printf("�Ӽ��̶���������Ԫ��ֵ:");
    scanf("%d", &x);

    if (L->length == MAX_LENGTH) {
        printf("���Ա��������޷����룡\n");
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

// ɾ������,ʹ��˫ָ����㷨��ʱ�临�Ӷ�ΪO(n)
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

//#define HAVE_MAIN
#ifdef HAVE_MAIN

int main() {
    SeqList list;
    InitList(&list);
    char ch;
    while ((ch = (char)getchar())) {
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
        default:
            break;
        }
        while (getchar() != '\n');
        printf("i:����Ԫ��\td:ɾ��Ԫ��\tq:�˳�\tp:��ӡ\tI:˳�����\tS:��������\tD:ɾ������\n");
    }
}

#endif
#endif
#pragma clang diagnostic pop
