//
// Created by malossov on 22-11-13.
//
#include <stdio.h>
#include <stdlib.h>

/**
2. 编写进栈函数push
3. 编写出栈函数pop
4. 编写main函数，
    1. 首先建立一空链栈；
    2. 调用进栈函数，将从键盘输入的数据元素逐个进栈，输入0结束；显示进栈后的数据元素；
    3. 调用两次出栈函数，显示出栈后的数据元素。
*/

typedef struct node {
    int data;
    struct node *next;
} node_type;

node_type *push(node_type *stack, int data) {
    node_type *new_node = (node_type *) malloc(sizeof(node_type));
    new_node->data = data;
    new_node->next = stack;
    return new_node;
}

node_type *pop(node_type *stack, int *data) {
    node_type *p = stack;
    stack = stack->next;
    *data = p->data;
    free(p);
    return stack;
}

void printStack(node_type *stack) {
    printf("栈中的元素为：");
    for (; stack->next != NULL; stack = stack->next)
        printf("%d ", stack->data);
    putchar('\n');
}


int main() {
    node_type *stack = (node_type *) malloc(sizeof(node_type));
    stack->next = NULL;
    int tmp = 1;
    printf("输入的数据元素逐个进栈，输入0结束:");
    while (tmp != 0) {
        scanf("%d", &tmp);
        stack = push(stack, tmp);
    }
    printStack(stack);
    printf("出栈元素为：");
    for (int i = 0; i < 2; i++) {
        stack = pop(stack, &tmp);
        printf("%d ", tmp);
    }
    putchar('\n');
    printStack(stack);

    return 0;
}