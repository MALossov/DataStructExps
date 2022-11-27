/**
* 1）一个班有30位同学，安排装进一个有30个元素的数组，以姓名作为关键字进行哈希存储，具体方法如下：将姓名字符串中的每个字节按ASCII码（中文也支持
的哦）加起来，除以30，取得的余数作为元素存放位置（数组下标）。冲突解决采用线性探查法。
2）输入少于30个学生姓名，按Hash方式存入表中。
3）验证能够按Hash方式找到表中学生，不在表中将提示错误
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "time.h"

#define MAX_Length 30

typedef struct student {
    char name[5];
    int age;
} Student;

typedef struct hashTable {
    Student data[MAX_Length];
    int length;
} HashTable;

// 初始化哈希表
HashTable *InitHashTable() {
    HashTable *hashTable = (HashTable *) malloc(sizeof(Student) * MAX_Length + sizeof(int));
    hashTable->length = 0;
    return hashTable;
}

// 哈希函数
int Hash(char *name) {
    int sum = 0;
    for (int i = 0; i < sizeof(name); i++) {
        sum += name[i];
    }
    return sum % MAX_Length;
}

// 插入数据
void Insert(HashTable *hashTable, Student student) {
    int index = Hash(student.name);
    if (hashTable->data[index].name[0] == '\0') {
        hashTable->data[index] = student;
        hashTable->length++;
    } else {
        for (int i = index; i < MAX_Length; i++) {
            if (hashTable->data[i].name[0] == '\0') {
                hashTable->data[i] = student;
                hashTable->length++;
                break;
            }
        }
    }
}

// 查找数据
int Search(HashTable *hashTable, char *name) {
    int index = Hash(name);
    if (hashTable->data[index].name[0] == '\0') {
        return -1;
    } else {
        for (int i = index; i < MAX_Length; i++) {
            if (hashTable->data[i].name[0] == '\0') {
                return -1;
            } else if (strcmp(hashTable->data[i].name, name) == 0) {
                return i;
            }
        }
    }
}

int randomInt(int min, int max) {
    return rand() % (max - min + 1) + min;
}

void randomString(char *str, int length) {
    for (int i = 0; i < length - 1; i++) {
        str[i] = randomInt(97, 122);
    }
    str[length - 1] = '\0';
}


HashTable *createRandomNames(int length) {
    HashTable *hashTable = InitHashTable();
    for (int i = 0; i < length; i++) {
        Student student;
        student.age = randomInt(10, 20);
        randomString(student.name, 5);
        Insert(hashTable, student);
    }
    return hashTable;
}

void printHash(HashTable *hashTable) {
    for (int i = 0; i < MAX_Length; i++) {
        if (hashTable->data[i].name[0] != '\0') {
            printf("index: %d, name: %s, age: %d\n", i, hashTable->data[i].name, hashTable->data[i].age);
        }
    }
}

int main() {
    srand((unsigned) time(NULL));
    HashTable *hashTable = InitHashTable();
    hashTable = createRandomNames(30);
    printf("hashTable length: %d", hashTable->length);
    printHash(hashTable);
    char name[5];
    puts("请输入要查找的姓名");
    gets(name);
    int index;
    index = Search(hashTable, name);
    printf("search index: %d", index);
    printf("\tname: %s, age: %d\n", hashTable->data[index].name, hashTable->data[index].age);

    return 0;
}
