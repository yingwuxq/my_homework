#include <cstddef>
#include <stdio.h>

struct ElemType {
    int value;
};

typedef struct BiTNode {
    ElemType data;
    struct BiTNode *lchild, *rchild;
} BiTNode, *BiTree;

typedef struct ThreadNode {
    ElemType data;
    struct ThreadNode *lchild, *rchild;
    int ltag, rtag;
} ThreadNode, *ThreadTree;

void InThread(ThreadTree &p, ThreadTree &pre) {
    if (p != NULL) {
        InThread(p->lchild, pre);
        if (p->lchild == NULL) {
            p->lchild = pre;
            p->ltag = 1;
        }
        if (pre != NULL && pre->rchild == NULL) {
            pre->rchild = p;
            pre->rtag = 1;
        }
        pre = p;
        InThread(p->rchild, pre);
    }
}

void CreateInThread(ThreadTree T) {
    ThreadTree pre = NULL;
    if (T != NULL) {
        InThread(T, pre);
        pre->rchild = NULL;
        pre->rtag = 1;
    }
}   

ThreadNode *Firstnode(ThreadNode *p) {
    while (p->ltag == 0) {
        p = p->lchild;
    }
    return p;
}

ThreadNode *Nextnode(ThreadNode *p) {
    if (p->rtag == 0) {
        return Firstnode(p->rchild);
    } else {
        return p->rchild;
    }
}

void Inorder(ThreadNode *T) {
    for (ThreadNode *p = Firstnode(T); p != NULL; p = Nextnode(p)) {
        // visit(p);
    }
}

ThreadNode *Lastnode(ThreadNode *p) {
    while (p->rtag == 0) {
        p = p->rchild;
    }
    return p;
}

ThreadNode *Prenode(ThreadNode *p) {
    if (p->ltag == 0) {
        return Lastnode(p->lchild);
    } else {
        return p->lchild;
    }
}