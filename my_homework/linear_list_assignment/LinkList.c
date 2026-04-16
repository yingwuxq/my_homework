#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;

typedef struct LNode {
    ElemType data;
    struct LNode *next;
} LNode, *LinkList;

// 初始化单链表

void InitLinkList(LinkList *L) {
    *L = (LinkList)malloc(sizeof(LNode));
    if (*L == NULL) {
        exit(1);
    }
    (*L)->next = NULL;
}

// 尾插法创建单链表

void CreateLinkList(LinkList *L, ElemType arr[], int n) {
    InitLinkList(L);
    LNode *p = *L;
    for (int i = 0; i < n; i++) {
        LNode *q = (LNode *)malloc(sizeof(LNode));
        if (q == NULL) {
            exit(1);
        }
        q->data = arr[i];
        q->next = NULL;
        p->next = q;
        p = q;
    }
}

// 打印单链表

void PrintLinkList(LinkList L) {
    LNode *p = L->next;
    if (p == NULL) {
        printf("LinkList is empty.\n");
        return;
    }
    while (p != NULL) {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

// 获取单链表长度

int LinkListLength(LinkList L) {
    int length = 0;
    LNode *p = L->next;
    while (p != NULL) {
        length++;
        p = p->next;
    }
    return length;
}

// 销毁单链表

void DestroyLinkList(LinkList *L) {
    LNode *p = *L;
    while (p != NULL) {
        LNode *q = p->next;
        free(p);
        p = q;
    }
    *L = NULL;
}

// (1) 删除给定元素算法

int DeleteByValue(LinkList *L, ElemType e) {
    LNode *p = *L;
    LNode *q = (*L)->next;
    while (q != NULL && q->data != e) {
        p = q;
        q = q->next;
    }
    if (q == NULL) {
        return 0;
    }
    p->next = q->next;
    free(q);
    return 1;
}

// (2) 删除已排序链表中所有重复元素

void DeleteDuplicates(LinkList *L) {
    LNode *p = (*L)->next;
    if (p == NULL) {
        return;
    }
    while (p->next != NULL) {
        if (p->data == p->next->data) {
            LNode *temp = p->next;
            p->next = temp->next;
            free(temp);
        } else {
            p = p->next;
        }
    }
}

// (3) 单链表逆置算法

void ReverseLinkList(LinkList *L) {
    LNode *p = (*L)->next;
    LNode *q;
    (*L)->next = NULL;
    while (p != NULL) {
        q = p->next;
        p->next = (*L)->next;
        (*L)->next = p;
        p = q;
    }
}

// (4) 循环左移k位算法

void Left(LinkList *L, int k) {
    int len = LinkListLength(*L);
    if (len == 0 || k == 0) {
        return;
    }
    k = k % len;
    if (k == 0) {
        return;
    }
    LNode *a = *L;
    for (int i = 0; i <= k; i++) {
        a = a->next;
    }
    LNode *b = a;
    while (b->next != NULL) {
        b = b->next;
    }
    LNode *c = (*L)->next;
    for (int i = 1; i < k; i++) {
        c = c->next;
    }
    
    b->next = (*L)->next;
    (*L)->next = a;
    c->next = NULL;
}

// (5) 循环右移k位算法

void Right(LinkList *L, int k) {
    int len = LinkListLength(*L);
    if (len == 0 || k == 0) {
        return;
    }
    k = k % len;
    if (k == 0) {
        return;
    }
    Left(L, len - k);
}

// (6) 合并两个已排序单链表算法

void Merge(LinkList L1, LinkList L2, LinkList *L) {
    InitLinkList(L);
    
    LNode *a = L1->next;
    LNode *b = L2->next;
    LNode *c = *L;
    while (a != NULL && b != NULL) {
        if (a->data < b->data) {
            c->next = a;
            a = a->next;
        } else {
            c->next = b;
            b = b->next;
        }
        c = c->next;
    }
    if (a != NULL) {
        c->next = a;
    }
    if (b != NULL) {
        c->next = b;
    }
}

// main函数验证

int main() {
    LinkList L;
    ElemType arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    InitLinkList(&L);
    CreateLinkList(&L, arr, n);
    
    // (1) 删除给定元素
    printf("Test Algotithm1:\n");
    printf("Before: ");
    PrintLinkList(L);
    DeleteByValue(&L, 5);
    printf("After:  ");
    PrintLinkList(L);
    
    // (2) 删除重复元素
    printf("Test Algotithm2:\n");
    ElemType Arr2[] = {1, 2, 2, 3, 3, 3, 4, 5, 5, 6};
    int m = sizeof(Arr2) / sizeof(Arr2[0]);
    CreateLinkList(&L, Arr2, m);
    printf("Before: ");
    PrintLinkList(L);
    DeleteDuplicates(&L);
    printf("After:  ");
    PrintLinkList(L);
    
    // (3) 逆置
    printf("Test Algotithm3:\n");
    printf("Before: ");
    PrintLinkList(L);
    ReverseLinkList(&L);
    printf("After:  ");
    PrintLinkList(L);
    
    // (4) 循环左移k位
    printf("Test Algotithm4:\n");
    printf("Before: ");
    PrintLinkList(L);
    Left(&L, 3);
    printf("After:  ");
    PrintLinkList(L);
    
    // (5) 循环右移k位
    printf("Test Algotithm5:\n");
    printf("Before: ");
    PrintLinkList(L);
    Right(&L, 2);
    printf("After:  ");
    PrintLinkList(L);
    
    // (6) 合并两个有序顺序表
    printf("Test Algotithm6:\n");
    LinkList L1, L2, L3;
    ElemType arrA[] = {1, 3, 5, 7, 9};
    ElemType arrB[] = {2, 4, 6, 8, 10};
    CreateLinkList(&L1, arrA, 5);
    CreateLinkList(&L2, arrB, 5);
    printf("List 1: ");
    PrintLinkList(L1);
    printf("List 2: ");
    PrintLinkList(L2);
    Merge(L1, L2, &L3);
    printf("Merged: ");
    PrintLinkList(L3);
    
    return 0;
}

