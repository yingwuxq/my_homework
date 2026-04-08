#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MaxSize 10

typedef int ElemType;

typedef struct {
    ElemType data[MaxSize];
    int front, rear;
} SqQueue;

void InitQueue(SqQueue &Q) {
    Q.front = Q.rear = 0;
}

bool QueueEmpty(SqQueue Q) {
    if (Q.front == Q.rear) {
        return true;
    }
    return false;
}

bool EnQueue(SqQueue &Q, ElemType x) {
    if ((Q.rear + 1)%MaxSize == Q.front) {
        return false;
    }
    Q.data[Q.rear] = x;
    Q.rear = (Q.rear + 1)%MaxSize;
    return true;
}

bool DeQueue(SqQueue &Q, ElemType &x) {
    if (Q.rear == Q.front) {
        return false;
    }
    x = Q.data[Q.front];
    Q.front = (Q.front + 1)%MaxSize;
    return true;
}

int main() {
    SqQueue Q;
    InitQueue(Q);
    EnQueue(Q, 1);
    EnQueue(Q, 2);
    EnQueue(Q, 3);
    ElemType x;
    DeQueue(Q, x);
    printf("%d\n", x);
    return 0;
}