int networkDelayTime(int** times, int timesRowSize, int timesColSize, int N, int K)
{
    int (*arcs)[N+1] = (int(*)[N+1])malloc(sizeof(int)*(N+1)*(N+1));
    int i,j,k;
    for (i = 1;i <= N;i++)
        for (j = 1;j <= N;j++)
            arcs[i][j] = INT_MAX;
    for (i = 0;i < timesRowSize;i++)
        arcs[times[i][0]][times[i][1]] = times[i][2];
    
    for (i = 1;i <= N;i++)
        arcs[i][i] = 0;
    
    for (k = 1;k <= N;k++)
        for (i = 1;i <= N;i++)
            for (j = 1;j <= N;j++)
            {
                if (arcs[i][k]!= INT_MAX && arcs[k][j]!= INT_MAX && arcs[i][k]+arcs[k][j] < arcs[i][j])
                    arcs[i][j] = arcs[i][k]+arcs[k][j];
            }
    int tol = 0;
    int flag = 0;
    for (i = 1;i <= N;i++)
    {
        if (tol < arcs[K][i])
            tol = arcs[K][i];
        if (arcs[K][i] == INT_MAX)
        {
            flag = 1;
            //break;
        }
    }
    return flag == 0? tol : -1;
}
