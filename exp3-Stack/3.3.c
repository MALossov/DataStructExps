#pragma clang diagnostic push
#pragma ide diagnostic ignored "cert-err34-c"
/**
 *
1. 两个栈共用一个数组空间，它们的栈底分别在数组两端，栈顶相向而行。编写入栈和出栈函数，实现两个栈元素分别的（但共用）入栈和出栈。
2. main中函数完成以下测试：
    1. 能否在共用空间上实现两个独立的栈：即能否向两个栈分别输入元素；能否分别从两个栈取出元素，每个栈取出的元素的顺序符合各自栈的特点
    2. 能否在共用空间用满时，及时制止新的入栈行为。
*/

#include "stdio.h"
#include "stdlib.h"

#define SUCCESS 0
#define ERROR 1
// 使用数组建立一个头尾相向的栈
#define MAXSIZE 10
typedef struct {
    int data[MAXSIZE];
    int top1;
    int top2;
} Stack;

Stack* InitStack(Stack* s) {
    s = (Stack*)malloc(sizeof(Stack));
    s->top1 = -1;
    s->top2 = MAXSIZE;
    return s;
}

// 入栈
int Push(Stack* s, int e, int stackNumber) {
    if (s->top1 + 1 == s->top2) {
        printf("栈已满，无法入栈");
        return ERROR;
    }
    else {
        if (stackNumber == 1) {
            s->data[++s->top1] = e;
        }
        else if (stackNumber == 2) {
            s->data[--s->top2] = e;
        }
        else {
            printf("请输入正确的栈号");
            return ERROR;
        }
        return SUCCESS;
    }
}

// 出栈
int Pop(Stack* s, int stackNumber, int* e) {
    if (stackNumber == 1) {
        if (s->top1 == -1) {
            printf("栈1已空，无法出栈");
            return ERROR;
        }
        else {
            *e = s->data[s->top1--];
            return SUCCESS;
        }
    }
    else if (stackNumber == 2) {
        if (s->top2 == MAXSIZE) {
            printf("栈2已空，无法出栈");
            return ERROR;
        }
        else {
            *e = s->data[s->top2++];
            return SUCCESS;
        }
    }
    else {
        printf("请输入正确的栈号");
        return ERROR;
    }
}

int PrintStack(Stack* s) {
    printf("Stack1:");
    for (int i = 0; i < s->top1 + 1; i++) {
        printf("%d ", s->data[i]);
    }
    putchar('\n');
    printf("Stack2:");
    for (int i = MAXSIZE - 1; i > s->top2 - 1; i--) {
        printf("%d ", s->data[i]);
    }
    putchar('\n');
}

#define HAVE_MAIN
#ifdef HAVE_MAIN

int main() {
    Stack* s;
    s = InitStack(s);
    char ch;
    int data, StackNum;
    printf("Input i:push,p:pop,q:quit,d:display.");
    for (int i = 0; i < 8; i++)
        Push(s, i, i % 2 ? 1 : 2);
    while (ch = (char)getchar()) {
        switch (ch) {
        case 'i':
            printf("Input data&Stack:");
            scanf("%d %d", &data, &StackNum);
            Push(s, data, StackNum);
            break;
        case 'p':
            printf("Input StackNum:");
            scanf("%d", &StackNum);
            Pop(s, StackNum, &data);
            break;
        case 'q':
            return SUCCESS;
        case 'd':
            PrintStack(s);
            break;
        }
        while (getchar() != '\n');
        printf("Input i:push,p:pop,q:quit,d:display.");
    }
}

#endif
#pragma clang diagnostic pop