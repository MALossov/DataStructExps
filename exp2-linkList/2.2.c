//
// Created by malossov on 22-11-13.
//
#ifndef EXP2_LINKLIST_2_2_C
#define EXP2_LINKLIST_2_2_C

#include "2.1.c"

//#define HAVE_MAIN

/**
1. ����һ��������������Ԫ��Ϊ�������Ӽ������룬����0������ע��0���ŵ������ڣ���
2. �Ӽ�����������һ���������ڵ������в�ѯ������������������Ѿ�������������͵���ɾ��������ɾ����Ԫ�����ڽ�㣬������������ɾ��ǰ�������Ԫ�������������Ļ�ϣ�
   ����������в�������������͵��ò��뺯��������������뵽������β�������������ڲ���ǰ�������Ԫ�������������Ļ�ϡ�
3. ���Ѿ�������Ԫ��Ϊ�����������У��Ӽ�������һ������������Ԫ��ֵ��С�����������Ԫ�ز��뵽�����С�
 */
Node *Add2Tail(Node *List, int data) {
    Node *p = List;
    while (p != NULL && p->next != NULL) {
        p = p->next;
    }
    if (p == NULL) {
        p = (Node *) malloc(sizeof(Node));
        p->data = data;
        p->next = NULL;
        return p;
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
 * �Ӽ������룬����0������ע��0���ŵ������ڣ�
 * @param List
 * @return List ����ͷָ��
 */
Node *InputList(Node *List) {
    // �Ӽ������룬����0������ע��0���ŵ������ڣ�
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
 * ��ѯ����
 * @param List ͷָ��
 * @param data ����ѯ����
 * @return ָ��ڵ��NULL
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
 * �ڵ������в�ѯ������������������Ѿ�������������͵���ɾ��������ɾ����Ԫ�����ڽ�㣬������������ɾ��ǰ�������Ԫ�������������Ļ�ϣ�
 * ����������в�������������͵��ò��뺯��������������뵽������β�������������ڲ���ǰ�������Ԫ�������������Ļ�ϡ�
 * @param List ͷָ��
 * @param data �������
 * @return ͷ�ڵ�
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
        printf("�ҵ���%d��ɾ����\n", data);
        printf("ɾ��ǰ��");
        printList(List);
        List = DeleteNode(List, p);
        printf("ɾ����");
        printList(List);
    } else {
        printf("û�ҵ�%d��������\n", data);
        printf("����ǰ��");
        printList(List);
        List = Add2Tail(List, data);
        printf("�����");
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
 * ����Ԫ��ֵ��С�����������Ԫ�ز��뵽������
 * @param List ͷָ��
 * @param data ��ѯ����
 * @return ͷָ���գ��޷��ҵ���
 */
Node *InsertByOrder(Node *List, int data) {
    Node *p = List;
    if (p == NULL) {
        List = Add2Tail(List, data);
        printf("���б�����");
        printList(List);
        return List;
    }
    if (CheckListOrder(List)) {
        while (p != NULL && p->next != NULL && p->next->data < data) {
            p = p->next;
        }
        if (data < p->data && p == List)    //�Բ���ͷ�ڵ��������
        {
            Node *q = (Node *) malloc(sizeof(Node));
            q->data = data;
            q->next = p;
            List = q;
        } else {
            // �м����
            Node *q = (Node *) malloc(sizeof(Node));
            q->data = data; // p->data;
            q->next = p->next;
            p->next = q;
        }
        printf("�����");
        printList(List);
        return List;
    } else {
        printf("���������޷�����\n");
        return NULL;
    }
}

#define HAVE_MAIN
#ifdef HAVE_MAIN

int main() {
    Node *head = NULL;
    int n, data, pos;
    printf("�����������ݣ���0������");
    head = InputList(head);
    char ch;
    printf("�б�Ϊ��");
    printList(head);
    while ((ch = (char) getchar())) {
        switch (ch) {
            case 's':
                printf("����Ҫ��ѯ������");
                scanf("%d", &data);
                head = PrintBeforeAndAfter(head, data);
                break;
            case 'q':
                printf("�˳�����\n");
                return 0;
            case 'p':
                printList(head);
                break;
            case 'i':
                printf("����Ҫ���������");
                scanf("%d", &data);
                head = InsertByOrder(head, data);
                break;
            default:
                break;
        }
        while (getchar() != '\n');
        printf("i:˳�����Ԫ��\ts:����Ԫ��\tq:�˳�\tp:��ӡ\n");
    }
    return 0;
}

#endif
#endif