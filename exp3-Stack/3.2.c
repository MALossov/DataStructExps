//
// Created by malossov on 22-11-13.
//
/**
1. 循环队列类型定义为：
2. 编写循环队列出队函数dequeue
3. 编写循环队列入队函数enqueue
*/
#include <memory.h>
#include "stdio.h"
#include "stdlib.h"

#define N 20
typedef struct {
    int data[N];
    int front, rear;
} queue_type;

queue_type *InitQueue() {
    queue_type *newQueue = (queue_type *) malloc(sizeof(queue_type));
    newQueue->rear = newQueue->front = 0;
    memset(newQueue->data, 0, sizeof(int) * N);
    return newQueue;
}

void enqueue(queue_type *queue, int data) {
    queue->data[queue->rear] = data;
    queue->rear = ((queue->rear) + 1) % (N + 1);
}

int dequeue(queue_type *queue) {
    int tmp = queue->data[queue->front];
    queue->front = ((queue->front) + 1) % (N + 1);
    return tmp;
}

/**
4. 编写函数：void aa(queue_type *q)；

> 其功能为，调用出队函数把队列q中的元素一一出队，如果是负数直接抛弃；如果是正数，则调用入队函数，插入到q的队尾。
*/
void aa(queue_type *q) {
    int tmpRear = q->rear;
    while (q->front != tmpRear) {
        static int tmp;
        if ((tmp = dequeue(q)) > 0)
            enqueue(q, tmp);
    }
}

// 输出队列的函数
void printQueue(queue_type *queue) {
    for (int i = queue->front; i != queue->rear; i++, i %= 1 + N) {
        printf("%d ", queue->data[i]);
    }
    putchar('\n');
}

/**
5. 编写main函数，首先建立一个队列，
    1. 其中的数据元素为：`{2, 3, -4, 6, -5, 8, -9, 7, -10, 20}`；
    2. 然后调用aa函数，并将aa函数调用前后队列的数据元素分别输出到屏幕上。
*/
int main() {
    int a[] = {2, 3, -4, 6, -5, 8, -9, 7, -10, 20};
    queue_type *Queue = InitQueue();
    int num = sizeof(a) / sizeof(int);
    for (int i = 0; i < num; i++)
        enqueue(Queue, a[i]);
    printf("原始队列：");
    printQueue(Queue);
    aa(Queue);
    printf("调用aa后：");
    printQueue(Queue);

    return 0;
}