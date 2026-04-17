#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 100

typedef char ElemType;

typedef struct BiTNode {
    ElemType data;              
    struct BiTNode *lchild;    
    struct BiTNode *rchild;
} BiTNode, *BiTree;

// 栈结构定义，用于非递归序列
typedef struct {
    BiTree data[MAXSIZE];
    int top;
} Stack;

void InitStack(Stack *S) {
    S->top = -1;
}

int StackEmpty(Stack S) {
    return S.top == -1;
}

int Push(Stack *S, BiTree p) {
    if (S->top >= MAXSIZE - 1) {
        return 0;
    }
    S->data[++S->top] = p;
    return 1;
}

int Pop(Stack *S, BiTree *p) {
    if (StackEmpty(*S)) {
        return 0;
    }
    *p = S->data[S->top--];
    return 1;
}

int GetTop(Stack S, BiTree *p) {
    if (StackEmpty(S)) {
        return 0;
    }
    *p = S.data[S.top];
    return 1;
}

// 队列结构定义，用于层须遍历
typedef struct {
    BiTree data[MAXSIZE];
    int front, rear;
} Queue;

void InitQueue(Queue *Q) {
    Q->front = Q->rear = 0;
}

int QueueEmpty(Queue Q) {
    return Q.front == Q.rear;
}

int EnQueue(Queue *Q, BiTree p) {
    if ((Q->rear + 1) % MAXSIZE == Q->front) {
        return 0;
    }
    Q->data[Q->rear] = p;
    Q->rear = (Q->rear + 1) % MAXSIZE;
    return 1;
}

int DeQueue(Queue *Q, BiTree *p) {
    if (QueueEmpty(*Q)) {
        return 0;
    }
    *p = Q->data[Q->front++];
    Q->front = (Q->front + 1) % MAXSIZE;
    return 1;
}

// 创建二叉树
