

#define MAX_TREE_SIZE 100

typedef int ElemType;

typedef struct {
    ElemType data;
    int parent;
} PTNode;

typedef struct {
    PTNode nodes[MAX_TREE_SIZE];
    int n;
} PTree;

struct CTNode {
    int child;
    struct CTNode *next;
};

typedef struct {
    ElemType data;
    struct CTNode *firstchild;
} CTBox;

typedef struct {
    CTBox nodes[MAX_TREE_SIZE];
    int n, r;
} CTree;

typedef struct CSNode {
    ElemType data;
    struct CSNode *firstchild, *nextchild;
} CSNode, *CSTree;

