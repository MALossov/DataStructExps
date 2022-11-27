/**
## Ex4-4:
1. 输入一组数（权值），编写建立哈夫曼树的函数
2. 以先序遍历为框架，输出每个权值对应的二进制编码
*/

#include "stdio.h"
#include "stdlib.h"

typedef struct HuffmanNode {
    int data;
    unsigned int weight;
    
};