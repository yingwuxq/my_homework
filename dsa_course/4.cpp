#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef int ElemType;

typedef struct LinkNode {
    ElemType data;
    struct LinkNode *next;
} LinkNode;

typedef struct {
    LinkNode *front, *rear;
} LinkQueue;

void InitQueue(LinkQueue &Q) {
    Q.front = Q.rear = (LinkNode *)malloc(sizeof(LinkNode));
    Q.front->next = NULL;
}

bool QueueEmpty(LinkQueue Q) {
    if (Q.front == Q.rear) {
        return true;
    }
    return false;
}

void EnQueue(LinkQueue &Q, ElemType x) {
    LinkNode *s = (LinkNode *)malloc(sizeof(LinkNode));
    s->data = x;
    s->next = NULL;
    Q.rear->next = s;
    Q.rear = s;
}

bool DeQueue(LinkQueue &Q, ElemType &x) {
    if (Q.front == Q.rear) {
        return false;
    }
    LinkNode *p = Q.front->next;
    x = p->data;
    Q.front->next = p->next;
    if (Q.rear == p) {
        Q.rear = Q.front;
    }
    free(p);
    return true;
}

int main() {
    LinkQueue Q;
    InitQueue(Q);
    EnQueue(Q, 1);
    EnQueue(Q, 2);
    EnQueue(Q, 3);
    ElemType x;
    while (DeQueue(Q, x)) {
        printf("%d ", x);
    }
    return 0;
}