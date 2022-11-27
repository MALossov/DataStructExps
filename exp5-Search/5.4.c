/**
* ### Ex5-4：
1）两个有序的顺序表，共用1个空间，存放时两个表是连续的，即表A先存放，接着是表B，编写合并函数，合并成一个有序的顺序表，在原表上完成。
2）编写归并排序函数，先以每个元素为子表，两两归并——调用合并函数，然后继续把新表两两合并，直到最后合并成一个大表，完成归并排序
3）main函数中输入一组无序数，调用归并排序函数，进行排序，并显示排序结果。
*/

#include "stdio.h"
#include "stdlib.h"
#include "time.h"

#define DataType int
#define MAX_Length 300

typedef struct seqList {
    DataType data[MAX_Length];
    int lengthLow, lengthHigh;
} SeqList;

// 合并两个有序顺序表
void merge(SeqList *list, int low, int mid, int high) {
    // 使用插入排序的方法在原表进行合并
    for (int i = mid + 1; i <= high; i++) {
        DataType temp = list->data[i];
        int j = i - 1;
        while (j >= low && list->data[j] > temp) {
            list->data[j + 1] = list->data[j];
            j--;
        }
        list->data[j + 1] = temp;
    }
}

// 归并排序
void mergeSort(SeqList *list, int low, int high) {
    if (low < high) {
        int mid = (low + high) / 2;
        mergeSort(list, low, mid);
        mergeSort(list, mid + 1, high);
        merge(list, low, mid, high);
    }
}

void init2Tables(SeqList *list, int n) {
    // Inited by random
    srand((unsigned) time(NULL));
    list->lengthLow = n;
    list->lengthHigh = n;
    for (int i = 0; i < n; i++) {
        list->data[i] = rand() % 100;
    }
    for (int i = n; i < 2 * n; i++) {
        list->data[i] = rand() % 100;
    }
}

void printList(SeqList *list, int lengthLow, int lengthHigh) {
    for (int i = lengthLow; i < lengthHigh; i++) {
        printf("%d ", list->data[i]);
    }
    printf("\n");
}

int main() {
    SeqList list;
    int n;
    printf("Input the length of two tables: ");
    scanf("%d", &n);
    init2Tables(&list, n);
    printf("Before merge sort: ");
    printList(&list, 0, list.lengthLow + list.lengthHigh);
    mergeSort(&list, 0, list.lengthLow - 1);
    mergeSort(&list, list.lengthLow, list.lengthLow + list.lengthHigh - 1);
    printf("After merge sort: ");
    printf("\n LowPart:");
    printList(&list, 0, list.lengthLow);
    printf(" HighPart:");
    printList(&list, list.lengthLow, list.lengthLow + list.lengthHigh);
    merge(&list, 0, list.lengthLow - 1, list.lengthLow + list.lengthHigh - 1);
    printf("After merge: ");
    printList(&list, 0, list.lengthLow + list.lengthHigh);

    return 0;
}