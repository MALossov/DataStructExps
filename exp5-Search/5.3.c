/**
* ### Ex5-3:【排序】
1）编写简单选择法函数
2）编写直接插入法函数
3）编写冒泡法排序函数
4）编写快速排序函数
5）在主程序中输入一组数据元素，如513，87，512，61，908，170，897，275，653，462，分别调用三种排序函数，输出每趟排序结果。
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef int DataType;
#define MAX_Length 300

// 简单选择排序
void simpleSelectSort(DataType *data, int length) {
    for (int i = 0; i < length; i++) {
        int min = i;
        for (int j = i + 1; j < length; j++) {
            if (data[j] < data[min]) {
                min = j;
            }
        }
        if (min != i) {
            DataType temp = data[i];
            data[i] = data[min];
            data[min] = temp;
        }
    }
}

// 直接插入排序
void directInsertSort(DataType *data, int length) {
    for (int i = 1; i < length; i++) {
        DataType temp = data[i];
        int j = i - 1;
        while (j >= 0 && data[j] > temp) {
            data[j + 1] = data[j];
            j--;
        }
        data[j + 1] = temp;
    }
}

// 冒泡排序
void bubbleSort(DataType *data, int length) {
    for (int i = 0; i < length; i++) {
        for (int j = 0; j < length - i - 1; j++) {
            if (data[j] > data[j + 1]) {
                DataType temp = data[j];
                data[j] = data[j + 1];
                data[j + 1] = temp;
            }
        }
    }
}

// 快速排序
void quickSort(DataType *data, int left, int right) {
    if (left < right) {
        int i = left;
        int j = right;
        DataType temp = data[left];
        while (i < j) {
            while (i < j && data[j] >= temp) {
                j--;
            }
            if (i < j) {
                data[i] = data[j];
                i++;
            }
            while (i < j && data[i] < temp) {
                i++;
            }
            if (i < j) {
                data[j] = data[i];
                j--;
            }
        }
        data[i] = temp;
        quickSort(data, left, i - 1);
        quickSort(data, i + 1, right);
    }
}

// 打印数组
void printArray(DataType *data, int length) {
    for (int i = 0; i < length; i++) {
        printf("%d ", data[i]);
    }
    printf("\n");
}

void countTimeCost(void (*sort)(DataType *, int), DataType *data, int length) {
    clock_t start = clock();
    sort(data, length);
    clock_t end = clock();
    printf("Time cost: %f\n", (double) (end - start));
}

void arrCpy(DataType *src, DataType *dest, int length) {
    for (int i = 0; i < length; i++) {
        dest[i] = src[i];
    }
}

int main() {
    int arr[] = {513, 87, 512, 61, 908, 170, 897, 275, 653, 462, 514, 88, 513, 62, 909, 171, 898, 276, 654, 463, 515,
                 89, 514, 63, 910, 172, 899, 277, 655, 464, 516, 90, 515, 64, 911, 173, 900, 278, 656, 465, 517, 91,
                 516, 65, 912, 174, 901, 279, 657, 466, 518, 92, 517, 66, 913, 175, 902, 280, 658, 467, 519, 93, 518,
                 67, 914, 176, 903, 281, 659, 468, 520, 94, 519, 68, 915, 177, 904, 282, 660, 469, 521, 95, 520, 69,
                 916, 178, 905, 283, 661, 470, 522, 96, 521, 70, 917, 179, 906, 284, 662, 471, 523, 97, 522, 71, 918,
                 180, 907, 285, 663, 472, 524, 98, 523, 72, 919, 181, 908, 286, 664, 473, 525, 99, 524, 73, 920, 182,
                 909, 287, 665, 474, 526, 100, 525, 74, 921, 183, 910, 288, 666, 475, 527, 101, 526, 75, 922, 184, 911,
                 289, 667, 476, 528, 102, 527, 76, 923, 185, 912, 290, 668, 477, 529, 103, 528, 77, 924, 186, 913, 291,
                 669, 478, 530, 104, 529, 78, 925, 187, 914, 292, 670, 479, 531, 105, 530, 79, 926, 188, 915, 293, 671,
                 480, 532, 106, 531, 80, 927, 189, 916, 294, 672, 481, 533, 107, 532, 81, 928, 190, 917, 295, 673, 482,
                 534, 108, 533, 82, 929, 191, 918, 296, 674, 483, 535, 109, 534, 83, 930, 192, 919, 297, 675, 484, 536,
                 110, 535, 84, 931, 193, 920, 298, 676, 485, 537, 111, 536, 85, 932, 194, 921, 299, 677, 486, 538, 112,
                 537, 86, 933, 195, 922, 300, 678, 487, 539, 113};
    int length = sizeof(arr) / sizeof(int);
    DataType data[MAX_Length];
    arrCpy(arr, data, length);
    printArray(arr, length);
    printf("Before sort: ");
    printArray(data, length);
    arrCpy(arr, data, length);
    printf("After simple select sort: ");
    countTimeCost(simpleSelectSort, data, length);
    printArray(data, length);
    arrCpy(arr, data, length);
    printf("After direct insert sort: ");
    countTimeCost(directInsertSort, data, length);
    printArray(data, length);
    arrCpy(arr, data, length);
    printf("After bubble sort: ");
    countTimeCost(bubbleSort, data, length);
    printArray(data, length);
    arrCpy(arr, data, length);
    printf("After quick sort: ");
//    countTimeCost(quickSort, data, length);
    clock_t start, end;
    start = clock();
    quickSort(arr, 0, length);
    end = clock();
    printf("time cost:%f\n", (double) (end - start));
    printArray(data, length);
    return 0;
}