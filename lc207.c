typedef struct ArcNode{
        int adjvex;
        struct ArcNode *nextarc;
}ArcNode;
typedef struct VNode{
        int v;
        ArcNode *firstarc;
}VNode;
typedef struct{
        int vexnum;
        VNode* List;
}Graph;
typedef struct {
    int *base;
    int *top;
}Stack;

void Push(Stack* obj, int x) {
    *(obj->top++) = x;
}
int Pop(Stack* obj) {
    return *(--obj->top);
}

Graph* CreateGraph(int n){
    Graph* G = (Graph*)malloc(sizeof(Graph));
    G->vexnum = n;
    G->List = (VNode*)malloc(n * sizeof(VNode));
    for (int i= 0;i < n;i++){
        G->List[i].v = i;
        G->List[i].firstarc = NULL;
    }
    return G;
}

bool canFinish(int numCourses, int** prerequisites, int prerequisitesRowSize, int *prerequisitesColSizes)
{
    Graph* G = CreateGraph(numCourses);
    int i;
    int *indegree = (int*)malloc(sizeof(int)* numCourses);       //各顶点的入度
    memset(indegree,0,numCourses*sizeof(int));
    for (i = 0;i < prerequisitesRowSize;i++)
    {
        ArcNode* new = (ArcNode*)malloc(sizeof(ArcNode));
        new->adjvex = prerequisites[i][0];
        indegree[prerequisites[i][0]]++; 
        int k = prerequisites[i][1];
        new->nextarc =  G->List[k].firstarc;
        G->List[k].firstarc = new;
    }
    
    Stack* S = (Stack*)malloc(sizeof(Stack));
    S->base = (int*)malloc(numCourses*sizeof(int));
    S->top = S->base;
    int count = 0;      //跑过的顶点计数
    for (i = 0;i < numCourses;i++)
    {
        if (!indegree[i])
            Push(S,i);
    }
    ArcNode* p;
    while (S->top != S->base)
    {
        i = Pop(S);
        count++;
        for (p = G->List[i].firstarc; p ;p = p->nextarc)
        {
            int k = p->adjvex;
            if (!(--indegree[k]))
                Push(S,k);
        }
    }
    return (count ==numCourses);
        //return true;
    //else
        //return false;
}
