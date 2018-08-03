int minPathSum(int** grid, int gridRowSize, int gridColSize)
{
    int i,j;
    for (i = 1;i < gridColSize;i++)
    {
        grid[0][i] += grid[0][i-1];
    }
    for (i = 1;i < gridRowSize;i++)
    {
        grid[i][0] += grid[i-1][0];
    }
    int min;
    for (i = 1;i < gridRowSize;i++)
    {
        for (j = 1;j < gridColSize;j++)
        {
            min = grid[i-1][j] < grid[i][j-1]? grid[i-1][j] : grid[i][j-1];
            grid[i][j] += min;
        }
    }
    return grid[gridRowSize-1][gridColSize-1];
}
