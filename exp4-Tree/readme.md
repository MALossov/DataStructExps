# 一、基本题

## Ex4-1:

1. 二叉树结点类型定义为：

```c
typedef struct bnode
{
int data;
struct bnode *lchild, *rchild;
}bnode_type;
```

2. 编写二叉树的创建函数，可以是排序二叉树的创建思路（见教材），或者以先序遍历为框架。
3. 编写中序遍历函数；
4. 编写后序遍历函数；
5. 编写先序遍历函数；

## Ex4-2:

编写main()函数，先调用create函数，建立一颗二叉排序树；然后分别调用中序、后序、先序遍历函数，将二叉树的先序、中序和后序遍历序列输出到屏幕上。

# 二、扩展题

## Ex4-3:

1. 实现二叉排序树的插入函数
2. main函数中，输入一组无序数，调用二叉排序树插入算法，将元素放入二叉树中
3. 中序遍历这颗二叉树，得到排序顺序。
4. 编写函数求一颗二叉树的深度
5. 求一颗二叉排序树的排序的反序结果，即将二叉排序树每个节点的左右子树交换，然后中序遍历之。

# 三、选作题

## Ex4-4:

1. 输入一组数（权值），编写建立哈夫曼树的函数
2. 以先序遍历为框架，输出每个权值对应的二进制编码