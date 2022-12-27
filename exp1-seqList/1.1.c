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

/**��ĿҪ�����һ�����Ա��˳��洢�ṹ��ʵ�����Ա�Ļ���������
1. ���ȴ���һ��˳����Ӽ��̶���һ������������С�ڵ���20����������˳�����˳��������ԣ�1������ע�⣭1���ŵ�˳����ڣ����������õ�˳���Ԫ�������������Ļ�ϡ�
2. ���Ѵ����õ�˳����в���һ��Ԫ�أ��Ӽ��̶���������Ԫ��ֵ�Ͳ���λ�ã����ò��뺯����ɲ��������Ȼ��˳���Ԫ�������������Ļ�ϡ�
3. ���Ѵ����õ�˳�����ɾ��һ��Ԫ�أ��Ӽ��̶�����ɾ����Ԫ��λ�ã���ţ�������ɾ���������ɾ��������Ȼ��˳���Ԫ�������������Ļ�ϡ�
 */
// ���Ա�ṹ��
typedef struct {
    DataTye data[MAX_LENGTH];
    int length;
} SeqList;

// ��ӡ���Ա�
void printList(SeqList *list) {
    if (list->length == 0) {
        printf("���Ա�Ϊ�գ�\n");
        return;
    }
    printf("���Ա���Ϊ%d��", list->length);
    int i;
    for (i = 0; i < list->length; i++) {
        printf("%d ", list->data[i]);
    }
    putchar('\n');
}

// ��ʼ�����Ա�
void InitList(SeqList *L) {
    printf("�Ӽ��̶���һ������������С�ڵ���20����������˳�����˳��������ԣ�1����:");
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

// ����Ԫ��
void InsertList(SeqList *L) {
    int i;
    DataTye x;
    printf("�Ӽ��̶���������Ԫ��ֵ�Ͳ���λ��:");
    scanf("%d%d", &x, &i);

    if (L->length == MAX_LENGTH) {
        printf("���Ա��������޷����룡\n");
        return;
    }
    if (i < 1 || i > L->length + 1) {
        printf("����λ�ò��Ϸ���\n");
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

// ɾ��Ԫ��
void DeleteList(SeqList *L) {
    int i;
    printf("�Ӽ��̶�����ɾ����Ԫ��λ�ã���ţ�:");
    scanf("%d", &i);
    if (i < 1 || i > L->length) {
        printf("ɾ��λ�ò��Ϸ���\n");
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
                printf("�˳�����\n");
                return 0;
            case 'p':
                printList(&list);
                break;
            default:
                break;
        }
        while (getchar() != '\n');
        printf("i:����Ԫ��\td:ɾ��Ԫ��\tq:�˳�\tp:��ӡ\n");
    }
}

#endif
#endif
#pragma clang diagnostic pop