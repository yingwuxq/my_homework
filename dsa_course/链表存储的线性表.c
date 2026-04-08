#include <limits.h>
#include <stdio.h>
#include <malloc.h>

typedef int ElemType;

typedef struct LNode {
    ElemType data;
    struct LNode *next;
} LNode, *LinkList;

LinkList L;

LinkList MakeEmpty();
int Length(LinkList L);
LinkList FindKth(int K, LinkList L);
LinkList Find(ElemType X, LinkList L);
LinkList Insert(ElemType X, int i, LinkList L);
LinkList Delete(int i, LinkList L);
void Print(LinkList L);

LinkList MakeEmpty() {
    LinkList L = (LinkList)malloc(sizeof(LNode));
    L = NULL;
    return L;
}

int Length(LinkList L) {
    LinkList p = L;
    int len = 0;
    while (p != NULL) {
        p = p->next;
        len++;
    }
    return len;
}

LinkList FindKth(int K, LinkList L) {
    LinkList p = L;
    int i = 1;
    while (p != NULL && i < K) {
        p = p->next;
        i++;
    }
    if (p == NULL) {
        return NULL;
    }
    return p;
}

LinkList Find(ElemType X, LinkList L) {
    LinkList p = L;
    while (p != NULL && p->data != X) {
        p = p->next;
    }
    return p;
}

LinkList Insert(ElemType X, int i, LinkList L) {
    LinkList s, p;
    if (i == 1) {
        s = (LinkList)malloc(sizeof(LNode));
        s->data = X;
        s->next = L;
        L = s;
        return L;
    }
    p = FindKth(i - 1, L);
    if (p == NULL) {
        return NULL;
    } else {
        s = (LinkList)malloc(sizeof(LNode));
        s->data = X;
        s->next = p->next;
        p->next = s;
        return L;
    }
}

LinkList Delete(int i, LinkList L) {
    LinkList p, s;
    if (i == 1) {
        s = L;
        if (L != NULL) {
            L = L->next;
        } else {
            return NULL;
        }
        free(s);
        return L;
    }
    p = FindKth(i - 1, L);
    if (p == NULL || p->next == NULL) {
        return NULL;
    } else {
        s = p->next;
        p->next = s->next;
        free(s);
        return L;
    }
}

void Print(LinkList L) {
    LinkList t;
    int flag = 1;
    for (t = L; t != NULL; t = t->next) {
        printf("%d->", t->data);
        flag = 0;
    }
    if (flag) {
        printf("NULL");
    }
    printf("\n");
}

int main(){
	L = MakeEmpty();
	Print(L);
	L = Insert(11,1,L);
	L = Insert(25,1,L);
	L = Insert(33,2,L);
	L = Insert(77,3,L);
	Print(L);
	printf("length:%d\n",Length(L));
	printf("the second node is:%d\n",FindKth(2,L)->data);
	printf("find 22:");
	if(Find(22,L))
		printf("Yes!\n");
	else
		printf("No!\n");
	printf("find 33:");
	if(Find(33,L))
		printf("Yes!\n");
	else
		printf("No!\n");
	L = Delete(1,L);
	L = Delete(3,L);
	printf("----------After Delete-----\n"); 
	Print(L);
	return 0;
} 