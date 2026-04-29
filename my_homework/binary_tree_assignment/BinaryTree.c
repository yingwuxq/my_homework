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
    *p = Q->data[Q->front];
    Q->front = (Q->front + 1) % MAXSIZE;
    return 1;
}

// 创建二叉树（递归方式，按先序序列输入）
// 输入格式：按先序序列输入结点值，空结点用'#'表示
void CreateBiTree(BiTree *T) {
    ElemType ch;
    scanf("%c", &ch);
    
    if (ch == '#') {
        *T = NULL;
    } else {
        *T = (BiTree)malloc(sizeof(BiTNode));
        if (*T == NULL) {
            exit(1);
        }
        (*T)->data = ch;
        CreateBiTree(&(*T)->lchild);
        CreateBiTree(&(*T)->rchild);
    }
}

// 销毁二叉树
void DestroyBiTree(BiTree *T) {
    if (*T != NULL) {
        DestroyBiTree(&(*T)->lchild);
        DestroyBiTree(&(*T)->rchild);
        free(*T);
        *T = NULL;
    }
}

// 计算二叉树深度
int BiTreeDepth(BiTree T) {
    if (T == NULL) {
        return 0;
    }
    int left_depth = BiTreeDepth(T->lchild);
    int right_depth = BiTreeDepth(T->rchild);
    return (left_depth > right_depth ? left_depth : right_depth) + 1;
}

// 计算二叉树结点总数
int CountNodes(BiTree T) {
    if (T == NULL) {
        return 0;
    }
    return CountNodes(T->lchild) + CountNodes(T->rchild) + 1;
}

// 计算叶子节点数
int CountLeaves(BiTree T) {
    if (T ==NULL) {
        return 0;
    }
    if (T->lchild == NULL && T->rchild == NULL) {
        return 1;
    }
    return CountLeaves(T->lchild) + CountLeaves(T->rchild);
}

// 先序遍历（递归）
void PreOrderTraverse(BiTree T) {
    if (T != NULL) {
        printf("%c ", T->data);
        PreOrderTraverse(T->lchild);
        PreOrderTraverse(T->rchild);
    }
}

// 中序遍历（递归）
void InOrderTraverse(BiTree T) {
    if (T != NULL) {
        InOrderTraverse(T->lchild);
        printf("%c ", T->data);
        InOrderTraverse(T->rchild);
    }
}

// 后序遍历（递归）
void PostOrderTraverse(BiTree T) {
    if (T != NULL) {
        PostOrderTraverse(T->lchild);
        PostOrderTraverse(T->rchild);
        printf("%c ", T->data);
    }
}

// 先序遍历（非递归）
void PreOrderTraverseNonRecursive(BiTree T) {
    Stack S;
    InitStack(&S);
    BiTree p = T;
    while (p != NULL || !StackEmpty(S)) {
        if (p != NULL) {
            printf("%c ", p->data);
            Push(&S, p);
            p = p->lchild;
        } else {
            Pop(&S, &p);
            p = p->rchild;
        }
    }
}

// 中序遍历（非递归）
void InOrderTraverseNonRecursive(BiTree T) {
    Stack S;
    InitStack(&S);
    BiTree p = T;
    while (p != NULL || !StackEmpty(S)) {
        if (p != NULL) {
            Push(&S, p);
            p = p->lchild;
        } else {
            Pop(&S, &p);
            printf("%c ", p->data);
            p = p->rchild;
        }
    }
}

// 后序遍历（非递归）
void PostOrderTraverseNonRecursive(BiTree T) {
    Stack S;
    InitStack(&S);
    BiTree p = T;
    BiTree lastVisited = NULL;
    while (p != NULL || !StackEmpty(S)) {
        if (p != NULL) {
            Push(&S, p);
            p = p->lchild;
        } else {
            GetTop(S, &p);
            if (p->rchild != NULL && p->rchild != lastVisited) {
                p = p->rchild;
                Push(&S, p);
                p = p->lchild;
            } else {
                Pop(&S, &p);
                printf("%c ", p->data);
                lastVisited = p;
                p = NULL;
            }
        }
    }
}

// 层须遍历
void LevelOrderTraverse(BiTree T) {
    if (T == NULL) {
        return;
    }
    Queue Q;
    InitQueue(&Q);
    BiTree p;
    EnQueue(&Q, T);
    while (!QueueEmpty(Q)) {
        DeQueue(&Q, &p);
        printf("%c ", p->data);
        if (p->lchild != NULL) {
            EnQueue(&Q, p->lchild);
        }
        if (p->rchild != NULL) {
            EnQueue(&Q, p->rchild);
        }
    }
}

// 打印二叉树（缩进形式）
void PrintBiTree_Indented(BiTree T, int depth) {
    if (T == NULL) {
        return;
    }
    for (int i = 0; i < depth; i++) {
        if (i == depth - 1) {
            printf("|--");
        } else {
            printf("   ");
        }
    }

    printf("%c\n", T->data);

    PrintBiTree_Indented(T->lchild, depth + 1);
    PrintBiTree_Indented(T->rchild, depth + 1);
}

// 显示二叉树
void ShowBiTree(BiTree T) {
    if (T == NULL) {
        return;
    }
    printf("%c\n", T->data);
    PrintBiTree_Indented(T->lchild, 1);
    PrintBiTree_Indented(T->rchild, 1);
}

// 输出遍历序列
void PrintTraversal(BiTree T, char *name, void(*trverseFunc)(BiTree)) {
    printf("%s: ", name);
    trverseFunc(T);
    printf("\n");
}

int main() {
    BiTree T = NULL;
    printf("Please input tree nodes (preorder, use '#' for empty node):\n");
    printf("Your input: ");
    CreateBiTree(&T);
    ShowBiTree(T);
    printf("\nTree depth: %d\n", BiTreeDepth(T));
    printf("Total nodes: %d\n", CountNodes(T));
    printf("Leaf nodes: %d\n", CountLeaves(T));
    PrintTraversal(T, "Preorder (recursive)", PreOrderTraverse);
    PrintTraversal(T, "Inorder (recursive)", InOrderTraverse);
    PrintTraversal(T, "Postorder (recursive)", PostOrderTraverse);
    PrintTraversal(T, "Preorder (Non-recursive)", PreOrderTraverseNonRecursive);
    PrintTraversal(T, "Inorder (Non-recursive)", InOrderTraverseNonRecursive);
    PrintTraversal(T, "Postorder (Non-recursive)", PostOrderTraverseNonRecursive);
    PrintTraversal(T, "Levelorder", LevelOrderTraverse);
    DestroyBiTree(&T);
    return 0;
}