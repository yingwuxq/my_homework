// 图的邻接表存储结构
#include <stdio.h>
#include <stdlib.h>

#define MAX_VEX 100
#define INFINITY 65535

typedef char VertexType;

typedef struct ArcNode {
    int adjvex;           
    struct ArcNode *nextarc;
} ArcNode;

typedef struct VNode {
    VertexType data;  
    ArcNode *firstarc; 
} VNode;

typedef struct {
    VNode vertices[MAX_VEX];
    int numVertexes;
    int numEdges;
} ALGraph;

int visited[MAX_VEX];
int dfsNum[MAX_VEX];
int bfsNum[MAX_VEX];
int dfsCount = 0;
int bfsCount = 0;

// 创建无向图的邻接表
/*
 * 时间复杂度: O(n+e)，其中n为顶点数，e为边数
 * 空间占用: O(n+e) - n个顶点结点 + 2e个边结点（无向图每边存两次）
 * 适合：稀疏图（边数远小于n^2）
 */
void CreateALGraph(ALGraph *G) {
    int i, j, k;
    ArcNode *p;

    printf("Please input vertex number and edge number: ");
    scanf("%d %d", &G->numVertexes, &G->numEdges);

    printf("Please input vertex info (e.g. A B C ...): ");
    for (i = 0; i < G->numVertexes; i++) {
        scanf(" %c", &G->vertices[i].data);
        G->vertices[i].firstarc = NULL;
    }

    printf("Please input edges (format: i j, vertex indices 0 to n-1):\n");
    for (k = 0; k < G->numEdges; k++) {
        scanf("%d %d", &i, &j);

        // 边 i->j
        p = (ArcNode *)malloc(sizeof(ArcNode));
        p->adjvex = j;
        p->nextarc = G->vertices[i].firstarc;
        G->vertices[i].firstarc = p;

        // 边 j->i
        p = (ArcNode *)malloc(sizeof(ArcNode));
        p->adjvex = i;
        p->nextarc = G->vertices[j].firstarc;
        G->vertices[j].firstarc = p;
    }
}

// 打印邻接表
void PrintALGraph(ALGraph G) {
    int i;
    ArcNode *p;
    printf("\nAdjacency List:\n");
    for (i = 0; i < G.numVertexes; i++) {
        printf("Vertex %c: ", G.vertices[i].data);
        p = G.vertices[i].firstarc;
        while (p) {
            printf("-> %c ", G.vertices[p->adjvex].data);
            p = p->nextarc;
        }
        printf("\n");
    }
}

// DFS深度优先搜索（递归）
/*
 * 时间复杂度: O(n+e)
 * 空间复杂度: O(n) - 递归栈深度
 */
void DFS_AL_Recursive(ALGraph G, int v) {
    ArcNode *p;
    visited[v] = 1;           // 标记已访问
    dfsNum[v] = ++dfsCount;   // DFS编号
    printf("Visit vertex %c (DFS No.%d)\n", G.vertices[v].data, dfsNum[v]);

    // 遍历边链表
    p = G.vertices[v].firstarc;
    while (p) {
        if (!visited[p->adjvex]) {
            DFS_AL_Recursive(G, p->adjvex);
        }
        p = p->nextarc;
    }
}

// DFS遍历整图（递归）
void DFSTraverse_AL_Recursive(ALGraph G) {
    int v;
    // 初始化
    for (v = 0; v < G.numVertexes; v++) {
        visited[v] = 0;
        dfsNum[v] = 0;
    }
    dfsCount = 0;
    printf("\n--- DFS Recursive (Adjacency List) ---\n");

    // 对每个未访问顶点调用DFS（处理非连通图）
    for (v = 0; v < G.numVertexes; v++) {
        if (!visited[v]) {
            printf("Starting from vertex %c:\n", G.vertices[v].data);
            DFS_AL_Recursive(G, v);
        }
    }
}

// 栈结构 用于DFS非递归
typedef struct {
    int data[MAX_VEX];
    int top;
} SqStack;

void InitStack(SqStack *S) {
    S->top = -1;
}

int StackEmpty(SqStack S) {
    return S.top == -1;
}

void Push(SqStack *S, int v) {
    S->data[++S->top] = v;
}

int Pop(SqStack *S) {
    return S->data[S->top--];
}

// DFS深度优先搜索（非递归）
/*
 * 使用栈模拟递归
 * 时间复杂度: O(n+e)
 * 空间复杂度: O(n) - 栈深度
 */
void DFS_AL_NonRecursive(ALGraph G, int v) {
    SqStack S;
    InitStack(&S);
    ArcNode *p;
    int first;

    visited[v] = 1;
    dfsNum[v] = ++dfsCount;
    printf("Visit vertex %c (DFS No.%d)\n", G.vertices[v].data, dfsNum[v]);
    Push(&S, v);

    while (!StackEmpty(S)) {
        v = S.data[S.top];  // 取栈顶元素（不弹出）
        p = G.vertices[v].firstarc;
        first = 1;  // 标记是否找到未访问邻接点

        // 遍历边链表找第一个未访问邻接点
        while (p) {
            if (!visited[p->adjvex]) {
                visited[p->adjvex] = 1;
                dfsNum[p->adjvex] = ++dfsCount;
                printf("Visit vertex %c (DFS No.%d)\n",
                       G.vertices[p->adjvex].data, dfsNum[p->adjvex]);
                Push(&S, p->adjvex);
                first = 0;
                break;  // 找到后跳出，继续深度搜索
            }
            p = p->nextarc;
        }

        // 若没有未访问的邻接点，弹出栈顶
        if (first) {
            Pop(&S);
        }
    }
}

// DFS遍历整图（非递归）
void DFSTraverse_AL_NonRecursive(ALGraph G) {
    int v;
    for (v = 0; v < G.numVertexes; v++) {
        visited[v] = 0;
        dfsNum[v] = 0;
    }
    dfsCount = 0;
    printf("\n--- DFS Non-Recursive (Adjacency List) ---\n");

    for (v = 0; v < G.numVertexes; v++) {
        if (!visited[v]) {
            printf("Starting from vertex %c:\n", G.vertices[v].data);
            DFS_AL_NonRecursive(G, v);
        }
    }
}

// 队列结构 用于BFS
typedef struct {
    int data[MAX_VEX];
    int front;
    int rear;
} SqQueue;

void InitQueue(SqQueue *Q) {
    Q->front = Q->rear = 0;
}

int QueueEmpty(SqQueue Q) {
    return Q.front == Q.rear;
}

void EnQueue(SqQueue *Q, int v) {
    Q->data[Q->rear++] = v;
}

int DeQueue(SqQueue *Q) {
    return Q->data[Q->front++];
}

//BFS算法
/*
 * 时间复杂度: O(n+e)
 * 空间复杂度: O(n) - 队列长度
 */
void BFS_AL(ALGraph G, int v) {
    SqQueue Q;
    InitQueue(&Q);
    ArcNode *p;

    visited[v] = 1;
    bfsNum[v] = ++bfsCount;
    printf("Visit vertex %c (BFS No.%d)\n", G.vertices[v].data, bfsNum[v]);
    EnQueue(&Q, v);

    while (!QueueEmpty(Q)) {
        v = DeQueue(&Q);
        p = G.vertices[v].firstarc;
        // 遍历边链表
        while (p) {
            if (!visited[p->adjvex]) {
                visited[p->adjvex] = 1;
                bfsNum[p->adjvex] = ++bfsCount;
                printf("Visit vertex %c (BFS No.%d)\n",
                       G.vertices[p->adjvex].data, bfsNum[p->adjvex]);
                EnQueue(&Q, p->adjvex);
            }
            p = p->nextarc;
        }
    }
}

// BFS遍历整图
void BFSTraverse_AL(ALGraph G) {
    int v;
    for (v = 0; v < G.numVertexes; v++) {
        visited[v] = 0;
        bfsNum[v] = 0;
    }
    bfsCount = 0;
    printf("\n--- BFS (Adjacency List) ---\n");

    for (v = 0; v < G.numVertexes; v++) {
        if (!visited[v]) {
            printf("Starting from vertex %c:\n", G.vertices[v].data);
            BFS_AL(G, v);
        }
    }
}

// 显示DFS/BFS结果
void ShowDFSResult(ALGraph G) {
    int i;
    printf("\nDFS Sequence: ");
    for (i = 0; i < G.numVertexes; i++) {
        printf("%c ", G.vertices[i].data);
    }
    printf("\nDFS Numbers:  ");
    for (i = 0; i < G.numVertexes; i++) {
        printf("%d ", dfsNum[i]);
    }
    printf("\n");
}

void ShowBFSResult(ALGraph G) {
    int i;
    printf("\nBFS Sequence: ");
    for (i = 0; i < G.numVertexes; i++) {
        printf("%c ", G.vertices[i].data);
    }
    printf("\nBFS Numbers:  ");
    for (i = 0; i < G.numVertexes; i++) {
        printf("%d ", bfsNum[i]);
    }
    printf("\n");
}

// 邻接表转邻接矩阵
typedef struct {
    VertexType vexs[MAX_VEX];
    int arc[MAX_VEX][MAX_VEX];
    int numVertexes;
    int numEdges;
} MGraph;

/*
 * 时间复杂度: O(n+e)
 */
void ListToMatrix(ALGraph L, MGraph *M) {
    int i, j;
    ArcNode *p;

    M->numVertexes = L.numVertexes;
    M->numEdges = L.numEdges;

    // 初始化顶点
    for (i = 0; i < L.numVertexes; i++) {
        M->vexs[i] = L.vertices[i].data;
    }

    // 初始化矩阵
    for (i = 0; i < L.numVertexes; i++) {
        for (j = 0; j < L.numVertexes; j++) {
            M->arc[i][j] = INFINITY;
        }
    }

    // 遍历邻接表填充矩阵
    for (i = 0; i < L.numVertexes; i++) {
        p = L.vertices[i].firstarc;
        while (p) {
            M->arc[i][p->adjvex] = 1;
            p = p->nextarc;
        }
    }
}

// 打印邻接矩阵
void PrintMGraph(MGraph G) {
    int i, j;
    printf("\nAdjacency Matrix:\n");
    printf("Vertices: ");
    for (i = 0; i < G.numVertexes; i++) {
        printf("%c ", G.vexs[i]);
    }
    printf("\n\nMatrix:\n");
    for (i = 0; i < G.numVertexes; i++) {
        for (j = 0; j < G.numVertexes; j++) {
            if (G.arc[i][j] == INFINITY) {
                printf(" INF");
            } else {
                printf("%4d", G.arc[i][j]);
            }
        }
        printf("\n");
    }
}

// 计算顶点度
/*
 * 时间复杂度: O(n+e)，其中n为顶点数，e为边数
 * 说明：无向图中，顶点的度等于其边链表中结点数
 */
void CalculateDegree(ALGraph G) {
    int i, degree;
    ArcNode *p;

    printf("\n--- Vertex Degrees (Adjacency List) ---\n");
    for (i = 0; i < G.numVertexes; i++) {
        degree = 0;
        p = G.vertices[i].firstarc;
        while (p) {
            degree++;
            p = p->nextarc;
        }
        printf("Vertex %c: degree = %d\n", G.vertices[i].data, degree);
    }
}

int main() {
    ALGraph G;
    MGraph M;

    // 1. 建立邻接表
    CreateALGraph(&G);
    PrintALGraph(G);

    // 2. DFS递归搜索
    DFSTraverse_AL_Recursive(G);
    ShowDFSResult(G);

    // 3. DFS非递归搜索
    DFSTraverse_AL_NonRecursive(G);
    ShowDFSResult(G);

    // 4. BFS搜索
    BFSTraverse_AL(G);
    ShowBFSResult(G);

    // 5. 转换为邻接矩阵
    printf("\n--- Convert Adjacency List to Adjacency Matrix ---\n");
    ListToMatrix(G, &M);
    PrintMGraph(M);

    // 6. 计算顶点度
    CalculateDegree(G);
    return 0;
}