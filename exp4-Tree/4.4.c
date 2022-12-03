/**
## Ex4-4:
1. 输入一组数（权值），编写建立哈夫曼树的函数
2. 以先序遍历为框架，输出每个权值对应的二进制编码
*/

#include "stdio.h"
#include "stdlib.h"
#include "string.h"

typedef struct HuffNode {
    int weight;
    struct HuffNode *parent, *lchild, *rchild;
} HuffNode;

HuffNode *newNode(int weight) {
    HuffNode *node = (HuffNode *) malloc(sizeof(HuffNode));
    node->weight = weight;
    node->parent = node->lchild = node->rchild = NULL;
    return node;
}

HuffNode connectNode(HuffNode *lchild, HuffNode *rchild) {
    HuffNode node;
    node.weight = lchild->weight + rchild->weight;
    node.parent = NULL;
    node.lchild = lchild;
    node.rchild = rchild;
    return node;
}

HuffNode createHuffmanTree(int *arr, int length) {
    HuffNode *nodes = (HuffNode *) malloc(sizeof(HuffNode) * length);
    int tmpLength = length;
    for (int i = 0; i < length; i++) {
        nodes[i] = *newNode(arr[i]);
    }

    for (int i = 0; i < length; i++) {
        int min1 = 0, min2 = 0;
        for (int j = 0; j < tmpLength + 1; j++) {
            if (nodes[j].parent == NULL) {
                min1 = j;
                break;
            }
        }
        for (int j = 0; j < tmpLength + 1; j++) {
            if (nodes[j].parent == NULL && j != min1) {
                min2 = j;
                break;
            }
        }
        for (int j = 0; j < tmpLength + 1; j++) {
            if (nodes[j].parent == NULL && j != min1 && j != min2) {
                if (nodes[j].weight < nodes[min1].weight) {
                    min2 = min1;
                    min1 = j;
                } else if (nodes[j].weight < nodes[min2].weight) {
                    min2 = j;
                }
            }
        }
        nodes[min1].parent = &nodes[length + i];
        nodes[min2].parent = &nodes[length + i];
        nodes[length + i] = connectNode(&nodes[min1], &nodes[min2]);
        tmpLength = length + i;
    }
    return nodes[length * 2 - 2];
}

void printHuffmanCode(HuffNode root) {
    if (root.lchild == NULL && root.rchild == NULL) {
        printf("%d ", root.weight);
        return;
    }
    printf("%d ", root.weight);
    printHuffmanCode(*root.lchild);
    printHuffmanCode(*root.rchild);
}

// 按照树状结构从第一层开始输出, 每一层多一个\t
void printHuffmanTree(HuffNode root, int level, char *code) {
    char code1[100], code2[100];
    strcpy(code1, code);
    strcpy(code2, code);
    if (root.lchild == NULL && root.rchild == NULL) {
        for (int i = 0; i < level; i++) {
            printf("\t");
        }
        printf("%d(%s)\n", root.weight, code);
        return;
    }
    printHuffmanTree(*root.lchild, level + 1, strcat(code1, "1"));
    for (int i = 0; i < level; i++) {
        printf("\t");
    }
    printf("%d(%s)\n", root.weight, code);
    printHuffmanTree(*root.rchild, level + 1, strcat(code2, "0"));
}

int main() {
    int arr[] = {89, 77, 53, 21, 9, 5, 3, 1};
    HuffNode root = createHuffmanTree(arr, 8);
    printHuffmanCode(root);
    putchar('\n');
    char code[] = "1";
    printHuffmanTree(root, 0, code);
    return 0;
}
