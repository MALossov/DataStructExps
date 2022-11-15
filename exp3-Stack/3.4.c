#pragma clang diagnostic push
#pragma ide diagnostic ignored "cert-err34-c"
//
// Created by malossov on 22-11-15.
//
/**
*
1. 实现一种扩展的循环队列，
    1. 使得全部的数组空间都能使用，基本思路是当传统循环队列放满时：即`(rear+1)%MAXNUM ==front`为真时，可以再入队一个元素，
    2. 接着`rear = (rear+1)%MAXNUM`后就会与front相等，此时将另外一个变量flag设置为1，表示此时的rear==front不是为空，而是满。
    3. 否则flag为0时，如果出现rear==front，则表示队列为空。
2. main()函数实现以下测试：
    1. 能否实现全部“装满”，即装入元素个数为MAXNUM
    2. 能否按照循环队列那样绕着存放空间循环存放。
    3. 能否在装满后，拒绝再装。
    4. 能否在装满后，不会变成“空”的——即可以还可正常出队。
    5. 能否在全部出空后，不会变成“满”的——即可还可正常入队。
*/
//
#include <memory.h>
#include "stdio.h"
#include "stdlib.h"

#define N 10
typedef struct {
    int data[N];
    int front, rear, flag;
} queue_type;

queue_type *InitQueue() {
    queue_type *newQueue = (queue_type *) malloc(sizeof(queue_type));
    newQueue->flag = newQueue->rear = newQueue->front = 0;
    memset(newQueue->data, 0, sizeof(int) * N);
    return newQueue;
}

void enqueue(queue_type *queue, int data) {
    if (queue->flag == 1) {
        printf("队列已满！");
        return;
    }
    if ((queue->rear + 1) % N == queue->front) {
        queue->flag = 1;
    }
    queue->rear = ((queue->rear) + 1) % N;
    queue->data[queue->rear] = data;
}

int dequeue(queue_type *queue) {
    if (queue->flag == 1) {
        queue->flag = 0;
//        return queue->data[queue->front];
    }
    int tmp = queue->data[queue->front];
    queue->front = ((queue->front) + 1) % N;
    return tmp;
}

void printQueue(queue_type *queue) {

    printf("DataNum:%d\n", queue->flag == 1 ? N : ((queue->rear + N) - queue->front) % (1 + N));
    int tmpFlg = 0;
    if (queue->flag == 1) {
        tmpFlg = 1;
    }
    for (int i = queue->front; tmpFlg || i != queue->rear; i++, i %= N) {
        printf("%d ", queue->data[i]);
        tmpFlg = 0;
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
    int data;
    while (1) {
        switch (getchar()) {
            case 'q':
                printf("Quit!");
                return 0;
            case 'd':
                printf("Dequeue:");
                data = dequeue(Queue);
                printf("Dequed data:%d\n", data);
                break;
            case 'e':
                printf("Input Data:");
                scanf("%d", &data);
                enqueue(Queue, data);
                break;
            case 'p':
                printQueue(Queue);
                break;

        }
        while (getchar() != '\n');
        printf("q:Quit,d:Deque,e:Enque,p:Print\n");

    }
}

#pragma clang diagnostic pop