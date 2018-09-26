int dfs(int** grid,int Row,int Col,int i,int j)
{
    if (i < 0 || i >= Row || j < 0 || j >= Col)
        return 0;
    int t_area = 0;
    if (grid[i][j] == 1)
    {
        grid[i][j] = 0;
        t_area = 1 + dfs(grid,Row,Col,i-1,j) + dfs(grid,Row,Col,i+1,j) + 
                  dfs(grid,Row,Col,i,j-1) + dfs(grid,Row,Col,i,j+1);
    }
    return t_area;
}
int maxAreaOfIsland(int** grid, int gridRowSize, int gridColSize)
{
    int i,j;
    int area = 0,max = 0;
    for (i = 0;i < gridRowSize;i++)
    {
        for (j = 0;j < gridColSize;j++)
        {
            if (grid[i][j] == 1)
            {
                area = dfs(grid,gridRowSize,gridColSize,i,j);
                max = max < area ? area : max;
            }
        }
    }
    return max;
}
