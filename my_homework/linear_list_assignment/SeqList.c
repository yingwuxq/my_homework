#include <stdio.h>
#define MAXSIZE 100

typedef int ElemType;

typedef struct {
    ElemType data[MAXSIZE];
    int length;
} SeqList;

// 初始化顺序表

void InitSeqList(SeqList *L) {
    L->length = 0;
}

// 创建顺序表

void CreateSeqList(SeqList *L, ElemType arr[], int n) {
    if (n > MAXSIZE) {
        printf("Error: n > MAXSIZE\n");
        return;
    }
    for (int i = 0; i < n; i++) {
        L->data[i] = arr[i];
    }
    L->length = n;   
}

// 打印顺序表

void PrintSeqList(SeqList L) {
    if (L.length == 0) {
        printf("SeqList is empty!\n");
        return;
    }
    for (int i = 0; i < L.length; i++) {
        printf("%d ", L.data[i]);
    }
    printf("\n");
}

// (1) 删除给定元素算法

int DeleteByValue(SeqList *L, ElemType e) {
    int pos = -1;
    for (int i = 0; i < L->length; i++) {
        if (L->data[i] == e) {
            pos = i;
            break;
        }
    }
    if (pos == -1) {
        return 0;
    }
    for (int i = pos; i < L->length - 1; i++) {
        L->data[i] = L->data[i + 1];
    }
    L->length--;
    return 1;
}

// (2) 删除已排序顺序表中所有重复元素算法

void DeleteDuplicates(SeqList *L) {
    if (L->length <= 1) {
        return;
    }
    int i = 0, j = 1;
    while (j < L->length) {
        if (L->data[i] != L->data[j]) {
            i++;
            L->data[i] = L->data[j];
        }
        j++;
    }
    L->length = i + 1;
}

// (3) 顺序表逆置算法

void ReverseSeqList(SeqList *L) {
    ElemType temp;
    for (int i = 0; i < L->length / 2; i++) {
        temp = L->data[i];
        L->data[i] = L->data[L->length - 1 - i];
        L->data[L->length - 1 - i] = temp;
    }
}

// 逆置指定范围的元素

void ReverseRange(SeqList *L, int start, int end) {
    ElemType temp;
    while (start < end) {
        temp = L->data[start];
        L->data[start] = L->data[end];
        L->data[end] = temp;
        start++;
        end--;
    }
}

// (4) 循环左移k位算法

void Left(SeqList *L, int k) {
    if (L->length == 0 || k == 0) {
        return;
    }
    k = k % L->length;
    if (k == 0) {
        return;
    }
    ReverseRange(L, 0, k - 1);
    ReverseRange(L, k, L->length - 1);
    ReverseSeqList(L);
}

// (5) 循环右移k位算法

void Right(SeqList *L, int k) {
    if (L->length == 0 || k == 0) {
        return;
    }
    k = k % L->length;
    if (k == 0) {
        return;
    }
    Left(L, L->length - k);
}

// (6) 合并两个已排序顺序表算法

void Merge(SeqList L1, SeqList L2, SeqList *L) {
    int i = 0, j = 0, k = 0;
    if (L1.length + L2.length > MAXSIZE) {
        return;
    }
    while (i < L1.length && j < L2.length) {
        if (L1.data[i] <= L2.data[j]) {
            L->data[k++] = L1.data[i++];
        } else {
            L->data[k++] = L2.data[j++];
        }
    }
    while (i < L1.length) {
        L->data[k++] = L1.data[i++];
    }
    while (j < L2.length) {
        L->data[k++] = L2.data[j++];
    }
    L->length = k;
}

// main函数验证

int main() {
    SeqList L;
    ElemType arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    InitSeqList(&L);
    CreateSeqList(&L, arr, n);
    
    // (1) 删除给定元素
    printf("Test Algotithm1:\n");
    printf("Before: ");
    PrintSeqList(L);
    DeleteByValue(&L, 5);
    printf("After:  ");
    PrintSeqList(L);
    
    // (2) 删除重复元素
    printf("Test Algotithm2:\n");
    ElemType Arr2[] = {1, 2, 2, 3, 3, 3, 4, 5, 5, 6};
    int m = sizeof(Arr2) / sizeof(Arr2[0]);
    CreateSeqList(&L, Arr2, m);
    printf("Before: ");
    PrintSeqList(L);
    DeleteDuplicates(&L);
    printf("After:  ");
    PrintSeqList(L);
    
    // (3) 逆置
    printf("Test Algotithm3:\n");
    printf("Before: ");
    PrintSeqList(L);
    ReverseSeqList(&L);
    printf("After:  ");
    PrintSeqList(L);
    
    // (4) 循环左移k位
    printf("Test Algotithm4:\n");
    printf("Before: ");
    PrintSeqList(L);
    Left(&L, 3);
    printf("After:  ");
    PrintSeqList(L);
    
    // (5) 循环右移k位
    printf("Test Algotithm5:\n");
    printf("Before: ");
    PrintSeqList(L);
    Right(&L, 2);
    printf("After:  ");
    PrintSeqList(L);
    
    // (6) 合并两个有序顺序表
    printf("Test Algotithm6:\n");
    SeqList L1, L2, L3;
    ElemType arrA[] = {1, 3, 5, 7, 9};
    ElemType arrB[] = {2, 4, 6, 8, 10};
    CreateSeqList(&L1, arrA, 5);
    CreateSeqList(&L2, arrB, 5);
    printf("List 1: ");
    PrintSeqList(L1);
    printf("List 2: ");
    PrintSeqList(L2);
    Merge(L1, L2, &L3);
    printf("Merged: ");
    PrintSeqList(L3);
    
    return 0;
}
