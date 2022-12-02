//
// Created by lshy1 on 2022/12/3.
// 改进了3.5当中愚蠢的计算括号的问题，这里直接先全部转为后缀表达式，然后再计算
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXSIZE 100

typedef struct {
    int data[MAXSIZE];
    int top;
} Stack;

void InitStack(Stack *S) {
    S->top = -1;
}

int IsEmpty(Stack *S) {
    return S->top == -1;
}

int IsFull(Stack *S) {
    return S->top == MAXSIZE - 1;
}

void Push(Stack *S, int x) {
    if (IsFull(S)) {
        printf("Stack is full!");
        return;
    }
    S->data[++S->top] = x;
}

int Pop(Stack *S) {
    if (IsEmpty(S)) {
        printf("Stack is empty!");
        return -1;
    }
    return S->data[S->top--];
}

int Top(Stack *S) {
    if (IsEmpty(S)) {
        printf("Stack is empty!");
        return -1;
    }
    return S->data[S->top];
}

int Priority(char op) {
    switch (op) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case '(':
            return 0;
        default:
            return -1;
    }
}

int main() {
    // 通过字符串输入，直接将中缀表达式转为后缀表达式
    char input[MAXSIZE];
    scanf("%s", input);
    int len = strlen(input);
    char modifiedInput[MAXSIZE];
    int modifiedLen = 0;
    Stack *opStack = (Stack *) malloc(sizeof(Stack));
    InitStack(opStack);
    for (int i = 0; i < len; i++) {
        if (input[i] >= '0' && input[i] <= '9') {
            modifiedInput[modifiedLen++] = input[i];
        } else {
            modifiedInput[modifiedLen++] = ' ';
            if (input[i] == '(') {
                Push(opStack, input[i]);
            } else if (input[i] == ')') {
                while (Top(opStack) != '(') {
                    modifiedInput[modifiedLen++] = ' ';
                    modifiedInput[modifiedLen++] = Pop(opStack);
                }
                Pop(opStack);
            } else {
                while (!IsEmpty(opStack) && Priority(input[i]) <= Priority(Top(opStack))) {
                    modifiedInput[modifiedLen++] = ' ';
                    modifiedInput[modifiedLen++] = Pop(opStack);
                }
                Push(opStack, input[i]);
            }
        }
    }
    while (!IsEmpty(opStack)) {
        modifiedInput[modifiedLen++] = ' ';
        modifiedInput[modifiedLen++] = Pop(opStack);
    }
    modifiedInput[modifiedLen++] = ' ';
    modifiedInput[modifiedLen] = '\0';
    printf("%s\n", modifiedInput);
    // 计算后缀表达式
    Stack *numStack = (Stack *) malloc(sizeof(Stack));
    InitStack(numStack);
    int tmpNum = 0;
    for (int i = 0; i < modifiedLen; i++) {
        if (modifiedInput[i] >= '0' && modifiedInput[i] <= '9') {
            tmpNum = tmpNum * 10 + modifiedInput[i] - '0';
        } else {
            if (modifiedInput[i] == ' ') {
                if (tmpNum != 0xfffffff) {
                    Push(numStack, tmpNum);
                    tmpNum = 0xfffffff;
                }
            } else {
                int num2 = Pop(numStack);
                int num1 = Pop(numStack);
                switch (modifiedInput[i]) {
                    case '+':
                        Push(numStack, num1 + num2);
                        break;
                    case '-':
                        Push(numStack, num1 - num2);
                        break;
                    case '*':
                        Push(numStack, num1 * num2);
                        break;
                    case '/':
                        Push(numStack, num1 / num2);
                        break;
                    default:
                        break;
                }
            }
        }
    }
    printf("%d", Pop(numStack));
    return 0;
}