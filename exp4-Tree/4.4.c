#pragma clang diagnostic push
#pragma ide diagnostic ignored "misc-no-recursion"
/**
* ## Ex4-4:
1. 输入一组数（权值），编写建立哈夫曼树的函数
2. 以先序遍历为框架，输出每个权值对应的二进制编码
*/

#include <stdio.h>
#include <stdlib.h>

// 哈夫曼树结构体
typedef unsigned int DataType;
typedef struct Huffman {
    DataType weight;
    struct Huffman *left, *right;
} Huffman;

// 建立哈夫曼树
Huffman *createHuffmanTree(const DataType *arr, int n) {
    Huffman *huff = (Huffman *) malloc(sizeof(Huffman) * n);
    DataType min1, min2;
    min1 = min2 = 0;
    Huffman *maxWeight = (Huffman *) malloc(sizeof(Huffman));
    maxWeight->weight = 0xffff;
    maxWeight->right = maxWeight->left = NULL;
    int i, j, k;
    // 初始化哈夫曼树
    for (i = 0; i < n; i++) {
        huff[i].weight = arr[i];
        huff[i].left = huff[i].right = NULL;
    }
    // 将这这个树集的地址存入数组当中
    Huffman **huffIndex = (Huffman **) malloc(sizeof(Huffman *) * n);
    for (i = 0; i < n; i++) {
        huffIndex[i] = &huff[i];
    }

    // 寻找最小的两个权值，合并，同时重新添加到数组中
    // min2取到最小值，min1取到次小值的指针
    for (j = 0; j < n - 1; j++) {
        for (i = 0; i < n; i++) {
            min2 = huffIndex[i]->weight < huffIndex[min2]->weight ? i : min2;
        }
        min1 = min2 + 1 >= n ? min2 - 1 : min2 + 1;
        for (i = 0; i < n; i++) {
            min1 = huffIndex[i]->weight < huffIndex[min1]->weight &&
                   i != min2 ? i : min1;
        }
        // 合并两棵树
        for (k = 0; k < n; k++) {
            if (min2 == k) {
                Huffman *NewNode = (Huffman *) malloc(sizeof(Huffman));
                NewNode->weight = huffIndex[min1]->weight + huffIndex[min2]->weight;
                NewNode->left = huffIndex[min1];
                NewNode->right = huffIndex[min2];
                // 将NewNode加入到huffIndex当中。
                huffIndex[min1] = NewNode;
                huffIndex[min2] = maxWeight;
            }
        }
    }

    return huffIndex[min1];
}

#pragma clang diagnostic push
#pragma ide diagnostic ignored "misc-no-recursion"

// 先序遍历一颗树
void preOrder(Huffman *Huff) {
    // 使用遍历二叉树的方式遍历哈夫曼树
    if (Huff != NULL) {
        preOrder(Huff->left);
        printf("%d ", Huff->weight);
        preOrder(Huff->right);
    }
}

#pragma clang diagnostic pop

// 将二叉树直接打印到终端上，用树的形式
void printTree(Huffman *Huff, int n) {
    if (Huff != NULL) {
        printTree(Huff->right, n + 1);
        for (int i = 0; i < n; i++) {
            printf("\t");
        }
        printf("%d\n", Huff->weight);
        printTree(Huff->left, n + 1);
    }
}

int main() {
    DataType arr[] = {2, 8, 7, 6, 5, 4};
    Huffman *huff = createHuffmanTree(arr, 6);
    printf("中序遍历:\t");
    preOrder(huff);
    putchar('\n');
    printTree(huff, 0);
    return 0;
}

#pragma clang diagnostic pop