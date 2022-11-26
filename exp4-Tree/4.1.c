#pragma clang diagnostic push
#pragma ide diagnostic ignored "misc-no-recursion"
/**
1. 二叉树结点类型定义为：
typedef struct bnode
{
    int data;
    struct bnode *lchild, *rchild;
}bnode_type;
2. 编写二叉树的创建函数，可以是排序二叉树的创建思路（见教材），或者以先序遍历为框架。
3. 编写中序遍历函数；
4. 编写后序遍历函数；
5. 编写先序遍历函数；
*/

#include <stdio.h>
#include "stdlib.h"

typedef struct bnode {
    int data;
    struct bnode *lchild, *rchild;
} bnode_type;

// 2. 编写二叉树的创建函数，以先序遍历为框架。
bnode_type *create_btree() {
    bnode_type *p;
    int ch;
    ch = getchar();
    if (ch == '#') {
        p = NULL;
    } else {
        p = (bnode_type *) malloc(sizeof(bnode_type));
        p->data = ch;
        p->lchild = create_btree();
        p->rchild = create_btree();
    }
    return p;
}

// 3. 编写中序遍历函数；
void in_order(bnode_type *p) {
    if (p != NULL) {
        in_order(p->lchild);
        printf("%c", p->data);
        in_order(p->rchild);
    }
}

// 4. 编写后序遍历函数；
void post_order(bnode_type *p) {
    if (p != NULL) {
        post_order(p->lchild);
        post_order(p->rchild);
        printf("%c", p->data);
    }
}

// 5. 编写先序遍历函数；
void pre_order(bnode_type *p) {
    if (p != NULL) {
        printf("%c", p->data);
        pre_order(p->lchild);
        pre_order(p->rchild);
    }
}

int main() {
    bnode_type *root;
    printf("请输入二叉树的先序遍历序列，以#表示空结点：");
    root = create_btree();
    printf("分别对二叉树进行遍历，顺序为：中序，后序，先序：");
    putchar('\n');
    in_order(root);
    putchar('\n');
    post_order(root);
    putchar('\n');
    pre_order(root);
    putchar('\n');
}
// EXAMPLE-INPUTS:ABC##DE#G##F###
// 顺序为根、左、右，#表示空结点
#pragma clang diagnostic pop