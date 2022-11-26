/**
## Ex4-3:

1. 实现二叉排序树的插入函数
2. main函数中，输入一组无序数，调用二叉排序树插入算法，将元素放入二叉树中
3. 中序遍历这颗二叉树，得到排序顺序。
4. 编写函数求一颗二叉树的深度
5. 求一颗二叉排序树的排序的反序结果，即将二叉排序树每个节点的左右子树交换，然后中序遍历之。
*/

#include <stdio.h>
#include <stdlib.h>

// Binary Tree Node
typedef struct BiTNode {
    int data;
    struct BiTNode *lchild, *rchild;
} BiTNode, *BiTree;

// Create a new node
BiTNode *newNode(int data) {
    BiTNode *node = (BiTNode *) malloc(sizeof(BiTNode));
    node->data = data;
    node->lchild = node->rchild = NULL;
    return node;
}

// Insert a node into a binary tree
void insert(BiTree *root, int data) {
    if (*root == NULL) {
        *root = newNode(data);
        return;
    }
    if (data < (*root)->data) {
        insert(&(*root)->lchild, data);
    } else if (data > (*root)->data) {
        insert(&(*root)->rchild, data);
    }
}

// Inorder traversal
void inorder(BiTree root) {
    if (root == NULL) {
        return;
    }
    inorder(root->lchild);
    printf("%d ", root->data);
    inorder(root->rchild);
}

// Get the depth of a binary tree
int getDepth(BiTree root) {
    if (root == NULL) {
        return 0;
    }
    int ldepth = getDepth(root->lchild);
    int rdepth = getDepth(root->rchild);
    return ldepth > rdepth ? ldepth + 1 : rdepth + 1;
}

// Reverse the binary tree
void reverse(BiTree root) {
    if (root == NULL) {
        return;
    }
    BiTNode *temp = root->lchild;
    root->lchild = root->rchild;
    root->rchild = temp;
    reverse(root->lchild);
    reverse(root->rchild);
}

int main() {
    BiTree root = NULL;
    int n;
    printf("Please input the number of nodes: ");
    scanf("%d", &n);
    printf("Please input the data of nodes: ");
    for (int i = 0; i < n; i++) {
        int data;
        scanf("%d", &data);
        insert(&root, data);
    }
    printf("Inorder traversal: ");
    inorder(root);
    putchar('\n');
    printf("Depth Of tree: %d\n", getDepth(root));
    printf("Reverse Inorder traversal: ");
    reverse(root);
    inorder(root);
    putchar('\n');
}