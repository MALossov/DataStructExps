/**
利用栈实现算术四则运算，即录入一个包含加减乘除运算的多项式，计算出结果。暂不考虑“括号”。
本题算法难点在如何利用栈，驱动运算过程。
> 本题程序难点在从输入的一个形如“3+4×16-4/3”的字符串中依次提取出各个数字和运算符。
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 100

typedef struct {
    int data[N];
    int top;
} stack_type;

stack_type *InitStack() {
    stack_type *newStack = (stack_type *) malloc(sizeof(stack_type));
    newStack->top = -1;
    memset(newStack->data, 0, sizeof(int) * N);
    return newStack;
}

void push(stack_type *stack, int data) {
    stack->data[++stack->top] = data;
}

int pop(stack_type *stack) {
    return stack->data[stack->top--];
}

int top(stack_type *stack) {
    return stack->data[stack->top];
}

int isEmpty(stack_type *stack) {
    return stack->top == -1;
}

int isFull(stack_type *stack) {
    return stack->top == N - 1;
}

void printStack(stack_type *stack) {
    for (int i = 0; i <= stack->top; i++) {
        printf("%d ", stack->data[i]);
    }
    putchar('\n');
}


int main() {
    stack_type *numStack = InitStack();
    stack_type *opStack = InitStack();
    char input[N];
    scanf("%s", input);
    int len = strlen(input);
    int tmpNum = 0;
    for (int i = 0; i < len; i++) {
        if (input[i] >= '0' && input[i] <= '9') {
            tmpNum = tmpNum * 10 + input[i] - '0';
        } else {
            if (input[i] != '(' && input[i] != ')') {
                push(numStack, tmpNum);
                tmpNum = 0;
            }
            if (input[i] == '+' || input[i] == '-') {
                while (!isEmpty(opStack) && top(opStack) != '(') {
                    int num2 = pop(numStack);
                    int num1 = pop(numStack);
                    int op = pop(opStack);
                    if (op == '+') {
                        push(numStack, num1 + num2);
                    } else if (op == '-') {
                        push(numStack, num1 - num2);
                    } else if (op == '*') {
                        push(numStack, num1 * num2);
                    } else if (op == '/') {
                        push(numStack, num1 / num2);
                    }
                }
                push(opStack, input[i]);
            } else if (input[i] == '*' || input[i] == '/') {
                while (!isEmpty(opStack) && (top(opStack) == '*' || top(opStack) == '/')) {
                    int num2 = pop(numStack);
                    int num1 = pop(numStack);
                    int op = pop(opStack);
                    if (op == '+') {
                        push(numStack, num1 + num2);
                    } else if (op == '-') {
                        push(numStack, num1 - num2);
                    } else if (op == '*') {
                        push(numStack, num1 * num2);
                    } else if (op == '/') {
                        push(numStack, num1 / num2);
                    }
                }
                push(opStack, input[i]);
            } else if (input[i] == '(') {
                push(opStack, input[i]);
            } else if (input[i] == ')') {
                while (top(opStack) != '(') {
                    int num2 = pop(numStack);
                    int num1 = pop(numStack);
                    int op = pop(opStack);
                    if (op == '+') {
                        push(numStack, num1 + num2);
                    } else if (op == '-') {
                        push(numStack, num1 - num2);
                    } else if (op == '*') {
                        push(numStack, num1 * num2);
                    } else if (op == '/') {
                        push(numStack, num1 / num2);
                    }
                }
                pop(opStack);
            }
        }
    }
    push(numStack, tmpNum);
    while (!isEmpty(opStack)) {
        int num2 = pop(numStack);
        int num1 = pop(numStack);
        int op = pop(opStack);
        if (op == '+') {
            push(numStack, num1 + num2);
        } else if (op == '-') {
            push(numStack, num1 - num2);
        } else if (op == '*') {
            push(numStack, num1 * num2);
        } else if (op == '/') {
            push(numStack, num1 / num2);
        }
    }
    printf("%d", pop(numStack));

    return 0;
}

