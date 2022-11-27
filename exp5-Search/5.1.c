/**
* ### Ex5-1:
1）编写顺序查找函数
2）编写二分查找函数
3）在主程序中输入关键字（43和5），分别调用两种查找函数，输出结果。
*/
#include <stdio.h>
#include <stdlib.h>

typedef int DataType;
#define MAX_Length 100
typedef struct seqList {
    DataType data[100];
    int length;
} SeqList;

// 顺序查找函数
int seqSearch(SeqList seqList, DataType data) {
    for (int i = 0; i < seqList.length; i++) {
        if (seqList.data[i] == data) {
            return i;
        }
    }
    return seqList.length + 1;
}

// 折中查找函数
int halfSearch(SeqList seqList, int head, int tail, int middle, DataType data) {
    if (seqList.data[middle] > data) {
        // 向后移动
        halfSearch(seqList, middle, tail, (middle + tail) / 2, data);
    } else if (seqList.data[middle] < data) {
        halfSearch(seqList, head, middle, (head + middle) / 2, data);
    } else if (seqList.data[middle] == data) {
        return middle;
    } else {
        return seqList.length + 1;
    }
}

// 初始化顺序表
SeqList *InitSeqList(int length) {
    SeqList *seqList = (SeqList *) malloc(sizeof(DataType) * length + sizeof(int));
    for (int i = 0; i < length; i++) {
        seqList->data[i] = (DataType) (length - i);
    }
    seqList->length = length;
    return seqList;
}

int main() {
    SeqList *seqList = InitSeqList(100);
    printf("顺序查找：%d\n", seqSearch(*seqList, 43));
    printf("对半查找：%d", halfSearch(*seqList, 0, seqList->length, seqList->length / 2, 5));
    return 0;
}