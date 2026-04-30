// 图的邻接矩阵存储结构
#include <stdio.h>
#include <stdlib.h>

#define MAX_VEX 100
#define INFINITY 65535

typedef char VertexType;
typedef int EdgeType;

typedef struct {
    VertexType vexs[MAX_VEX];   // 顶点表
    EdgeType arc[MAX_VEX][MAX_VEX]; // 邻接矩阵（边表）
    int numVertexes;            // 当前顶点数
    int numEdges;               // 当前边数
} MGraph;

int visited[MAX_VEX];
int dfsNum[MAX_VEX];
int bfsNum[MAX_VEX];
int dfsCount = 0;
int bfsCount = 0;

// 创建无向图的邻接矩阵
/*
 * 时间复杂度: O(n^2)，其中n为顶点数
 * 空间占用: O(n^2) - 无论边数多少，矩阵占用n^2空间
 * 适合：稠密图（边数接近n^2）
 */
void CreateMGraph(MGraph *G) {
    int i, j, k;
    printf("Please input vertex number and edge number: ");
    scanf("%d %d", &G->numVertexes, &G->numEdges);

    // 输入顶点信息
    printf("Please input vertex info (e.g. A B C ...): ");
    for (i = 0; i < G->numVertexes; i++) {
        scanf(" %c", &G->vexs[i]);
    }

    // 初始化邻接矩阵
    for (i = 0; i < G->numVertexes; i++) {
        for (j = 0; j < G->numVertexes; j++) {
            G->arc[i][j] = INFINITY;  // 初始无边
        }
    }

    // 输入边信息（无向图，对称矩阵）
    printf("Please input edges (format: i j, vertex indices 0 to n-1):\n");
    for (k = 0; k < G->numEdges; k++) {
        scanf("%d %d", &i, &j);
        G->arc[i][j] = 1;  // 边权值设为1
        G->arc[j][i] = 1;  // 无向图对称
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

// DFS深度优先搜索（递归）
/*
 * 时间复杂度: O(n^2)
 * 空间复杂度: O(n) - 递归栈深度
 */
void DFS_AM_Recursive(MGraph G, int v) {
    int j;
    visited[v] = 1;           // 标记已访问
    dfsNum[v] = ++dfsCount;   // DFS编号
    printf("Visit vertex %c (DFS No.%d)\n", G.vexs[v], dfsNum[v]);

    // 遍历所有邻接点
    for (j = 0; j < G.numVertexes; j++) {
        if (G.arc[v][j] != INFINITY && !visited[j]) {
            DFS_AM_Recursive(G, j);
        }
    }
}

// DFS遍历整图（递归）
void DFSTraverse_AM_Recursive(MGraph G) {
    int v;
    // 初始化
    for (v = 0; v < G.numVertexes; v++) {
        visited[v] = 0;
        dfsNum[v] = 0;
    }
    dfsCount = 0;
    printf("\n--- DFS Recursive (Adjacency Matrix) ---\n");

    // 对每个未访问顶点调用DFS（处理非连通图）
    for (v = 0; v < G.numVertexes; v++) {
        if (!visited[v]) {
            printf("Starting from vertex %c:\n", G.vexs[v]);
            DFS_AM_Recursive(G, v);
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
 * 时间复杂度: O(n^2)
 * 空间复杂度: O(n) - 栈深度
 */
void DFS_AM_NonRecursive(MGraph G, int v) {
    SqStack S;
    InitStack(&S);
    int j, first;

    visited[v] = 1;
    dfsNum[v] = ++dfsCount;
    printf("Visit vertex %c (DFS No.%d)\n", G.vexs[v], dfsNum[v]);
    Push(&S, v);

    while (!StackEmpty(S)) {
        v = S.data[S.top];  // 取栈顶元素（不弹出）
        first = 1;  // 标记是否找到第一个未访问邻接点

        // 寻找第一个未访问的邻接点
        for (j = 0; j < G.numVertexes; j++) {
            if (G.arc[v][j] != INFINITY && !visited[j]) {
                visited[j] = 1;
                dfsNum[j] = ++dfsCount;
                printf("Visit vertex %c (DFS No.%d)\n", G.vexs[j], dfsNum[j]);
                Push(&S, j);
                first = 0;
                break;  // 找到后跳出，继续深度搜索
            }
        }

        // 若没有未访问的邻接点，弹出栈顶
        if (first) {
            Pop(&S);
        }
    }
}

// DFS遍历整图（非递归）
void DFSTraverse_AM_NonRecursive(MGraph G) {
    int v;
    for (v = 0; v < G.numVertexes; v++) {
        visited[v] = 0;
        dfsNum[v] = 0;
    }
    dfsCount = 0;
    printf("\n--- DFS Non-Recursive (Adjacency Matrix) ---\n");

    for (v = 0; v < G.numVertexes; v++) {
        if (!visited[v]) {
            printf("Starting from vertex %c:\n", G.vexs[v]);
            DFS_AM_NonRecursive(G, v);
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
 * 时间复杂度: O(n^2)
 * 空间复杂度: O(n) - 队列长度
 */
void BFS_AM(MGraph G, int v) {
    SqQueue Q;
    InitQueue(&Q);
    int j;

    visited[v] = 1;
    bfsNum[v] = ++bfsCount;
    printf("Visit vertex %c (BFS No.%d)\n", G.vexs[v], bfsNum[v]);
    EnQueue(&Q, v);

    while (!QueueEmpty(Q)) {
        v = DeQueue(&Q);
        // 遍历所有邻接点
        for (j = 0; j < G.numVertexes; j++) {
            if (G.arc[v][j] != INFINITY && !visited[j]) {
                visited[j] = 1;
                bfsNum[j] = ++bfsCount;
                printf("Visit vertex %c (BFS No.%d)\n", G.vexs[j], bfsNum[j]);
                EnQueue(&Q, j);
            }
        }
    }
}

// BFS遍历整图
void BFSTraverse_AM(MGraph G) {
    int v;
    for (v = 0; v < G.numVertexes; v++) {
        visited[v] = 0;
        bfsNum[v] = 0;
    }
    bfsCount = 0;
    printf("\n--- BFS (Adjacency Matrix) ---\n");

    for (v = 0; v < G.numVertexes; v++) {
        if (!visited[v]) {
            printf("Starting from vertex %c:\n", G.vexs[v]);
            BFS_AM(G, v);
        }
    }
}

// 显示DFS/BFS结果
void ShowDFSResult(MGraph G) {
    int i;
    printf("\nDFS Sequence: ");
    for (i = 0; i < G.numVertexes; i++) {
        printf("%c ", G.vexs[i]);
    }
    printf("\nDFS Numbers:  ");
    for (i = 0; i < G.numVertexes; i++) {
        printf("%d ", dfsNum[i]);
    }
    printf("\n");
}

void ShowBFSResult(MGraph G) {
    int i;
    printf("\nBFS Sequence: ");
    for (i = 0; i < G.numVertexes; i++) {
        printf("%c ", G.vexs[i]);
    }
    printf("\nBFS Numbers:  ");
    for (i = 0; i < G.numVertexes; i++) {
        printf("%d ", bfsNum[i]);
    }
    printf("\n");
}

// 邻接矩阵转邻接表
typedef struct ArcNode {
    int adjvex;             // 邻接点下标
    struct ArcNode *nextarc; // 指向下一边结点
} ArcNode;

typedef struct VNode {
    VertexType data;        // 顶点信息
    ArcNode *firstarc;      // 指向第一条边
} VNode;

typedef struct {
    VNode vertices[MAX_VEX];
    int numVertexes;
    int numEdges;
} ALGraph;

/*
 * 时间复杂度: O(n^2)
 */
void MatrixToList(MGraph M, ALGraph *L) {
    int i, j;
    ArcNode *p;

    L->numVertexes = M.numVertexes;
    L->numEdges = M.numEdges;

    // 初始化顶点
    for (i = 0; i < M.numVertexes; i++) {
        L->vertices[i].data = M.vexs[i];
        L->vertices[i].firstarc = NULL;
    }

    // 遍历矩阵建立边
    for (i = 0; i < M.numVertexes; i++) {
        for (j = 0; j < M.numVertexes; j++) {
            if (M.arc[i][j] != INFINITY) {
                // 创建边结点
                p = (ArcNode *)malloc(sizeof(ArcNode));
                p->adjvex = j;
                p->nextarc = L->vertices[i].firstarc;
                L->vertices[i].firstarc = p;
            }
        }
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
    MGraph G;
    ALGraph L;

    // 1. 建立邻接矩阵
    CreateMGraph(&G);
    PrintMGraph(G);

    // 2. DFS递归搜索
    DFSTraverse_AM_Recursive(G);
    ShowDFSResult(G);

    // 3. DFS非递归搜索
    DFSTraverse_AM_NonRecursive(G);
    ShowDFSResult(G);

    // 4. BFS搜索
    BFSTraverse_AM(G);
    ShowBFSResult(G);

    // 5. 转换为邻接表
    printf("\n--- Convert Adjacency Matrix to Adjacency List ---\n");
    MatrixToList(G, &L);
    PrintALGraph(L);

    // 6. 计算顶点度
    CalculateDegree(L);
    return 0;
}