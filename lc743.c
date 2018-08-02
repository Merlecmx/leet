int networkDelayTime(int** times, int timesRowSize, int timesColSize, int N, int K)
{
    int (*arcs)[N+1] = (int(*)[N+1])malloc(sizeof(int)*(N+1)*(N+1));
    int i,j;
    for (i = 1;i <= N;i++)
        for (j = 1;j <= N;j++)
            arcs[i][j] = INT_MAX;
    for (i = 1;i < timesRowSize;i++)
        arcs[times[i][1]][times[i][2]] = times[i][3];
    
    int *minlength = (int*)malloc(sizeof(int)*(N+1));       //V->Vi 最短路径
    int *visited = (int*)malloc(sizeof(int)*(N+1));         //访问过的点
    for (i = 1;i <= N;i++){
        minlength[i] = arcs[K][i];
        visited[i] = 0;
    }
    minlength[K] = 0;
    visited[K] = 1;
    //int count = 1;
    for (i = 1;i < N;i++)         //剩下N-1 个点
    {
        int min = INT_MAX;
        int v;
        for (j = 1;j <= N;j++)
        {
            if (!visited[j] && minlength[j] < min){
                min = minlength[j];
                v = j;
            }    
        }
        visited[v] = 1;
        //count++;
        for (j = 1;j <= N;j++)
        {
            if (!visited[j] && (min+arcs[v][j]) < minlength[j])
                minlength[j] = min+arcs[v][j];
        }
    }
    int tol = 0;
    int flag = 0;
    for (i = 1;i <= N;i++)
    {
        if (tol < minlength[i])
            tol = minlength[i];
        if (minlength[i] == INT_MAX){
            flag = 1;
            break;
        }
    }
    //free(arcs);
    free(minlength);
    free(visited);
    
    //return count==N? tol : -1;
    return flag==1? tol : -1;
}
