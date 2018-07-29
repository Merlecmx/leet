/**
 * #define NEIGHBORS_MAX_SIZE 100
 * struct UndirectedGraphNode {
 *     int label;
 *     struct UndirectedGraphNode *neighbors[NEIGHBORS_MAX_SIZE];
 *     int neighborsCount;
 * };
 */
#define POS  10000

struct UndirectedGraphNode * dfs(struct UndirectedGraphNode *graph, int *has, struct UndirectedGraphNode ** save)
{
    if (has[graph->label + POS]) return save[graph->label + POS];
    struct UndirectedGraphNode *nd = malloc(sizeof(struct UndirectedGraphNode));
    has[graph->label + POS] = 1;
    save[graph->label + POS] = nd;

    nd->label = graph->label;
    nd->neighborsCount = graph->neighborsCount;
    for(int i= 0; i < graph->neighborsCount; i++){

        if (graph->neighbors[i] == graph) {
            nd->neighbors[i] = nd;
        }
        else {
             nd->neighbors[i] = dfs(graph->neighbors[i], has, save);
        }
    }
    return nd;
}

struct UndirectedGraphNode *cloneGraph(struct UndirectedGraphNode *graph) {
    if (!graph) return NULL;
    int *has  = (int *) malloc(4* 20000);
    memset(has, 0, 4*20000);
    struct UndirectedGraphNode ** save = (struct UndirectedGraphNode **) malloc(20000*4);
    
    return dfs(graph, has, save);
}
