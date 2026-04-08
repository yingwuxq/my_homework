#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef int ElemType;

typedef struct LNode {
    ElemType data;
    struct LNode *next;
} LNode, *LinkList;

bool ListInsert(LinkList &L, int i, ElemType e) {
    if (i < 1) {
        return false;
    }
    LNode *p;
    int j = 0;
    p = L;
    while (p != NULL && j < i-1) {
        p = p->next;
        j++;
    }
    if (p == NULL) {
        return false;
    }
    LNode *s = (LNode *)malloc(sizeof(LNode));
    s->data = e;
    s->next = p->next;
    p->next = s;
    return true;
}

bool InsertNextNode(LNode *p, ElemType e) {
    if (p == NULL) {
        return false;
    }
    LNode *s = (LNode *)malloc(sizeof(LNode));
    if (s == NULL) {
        return false;
    }
    s->data = e;
    s->next = p->next;
    p->next = s;
    return true;
}

bool InsertPriorNode(LNode *p, ElemType e) {
    if (p == NULL) {
        return false;
    }
    LNode *s = (LNode *)malloc(sizeof(LNode));
    if (s == NULL) {
        return false;
    }
    s->next = p->next;
    p->next = s;
    s->data = p->data;
    p->data = e;
    return true;
}

bool ListDelete(LinkList &L, int i, ElemType &e) {
    if (i < 1) {
        return false;
    }
    LNode *p;
    int j = 0;
    p = L;
    while (p != NULL && j < i-1) {
        p = p->next;
        j++;
    }
    if (p == NULL || p->next == NULL) {
        return false;
    }
    LNode *q = p->next;
    e = q->data;
    p->next = q->next;
    free(q);
    return true;
}

bool DeleteNode(LNode *p) {
    if (p == NULL) {
        return false;
    }
    LNode *q = p->next;
    if (q == NULL) {
        return false;
    }
    p->data = q->data;
    p->next = q->next;
    free(q);
    return true;
}

LNode *LocateElem(LinkList L, ElemType e) {
    LNode *p = L->next;
    while (p != NULL && p->data != e) {
        p = p->next;
    }
    return p;
}

int Length(LinkList L) {
    int len = 0;
    LNode *p = L;
    while (p != NULL) {
        p = p->next;
        len++;
    }
    return len;
}

bool InitList(LinkList &L) {
    L = (LNode *)malloc(sizeof(LNode));
    if (L == NULL) {
        return false;
    }
    L->next = NULL;
    return true;
}

LinkList List_TailInsert(LinkList &L) {
    int x;
    L = (LNode *)malloc(sizeof(LNode));
    LNode *s, *r = L;
    scanf("%d", &x);
    while (x != 9999) {
        s = (LNode *)malloc(sizeof(LNode));
        s->data = x;
        r->next = s;
        r = s;
        scanf("%d", &x);
    }
    r->next = NULL;
    return L;
}

LinkList List_HeadInsert(LinkList &L) {
    LNode *s;
    int x;
    L = (LNode *)malloc(sizeof(LNode));
    L->next = NULL; // 初始化位空链表，有可能指向某一个神秘的地方 所以要养成好习惯 总是要初始化链表
    scanf("%d", &x);
    while (x != 9999) {
        s = (LNode *)malloc(sizeof(LNode));
        s->data = x;
        s->next = L->next;
        L->next = s;
        scanf("%d", &x);
    }
    return L;
}

