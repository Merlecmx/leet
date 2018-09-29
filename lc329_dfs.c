int max(int a,int b)
{
    return a > b ? a : b;
}
int dfs_Longest_Path(int** matrix,int row,int col,int** flag,int i,int j)
{
    int len = 1,temp;
    if (flag[i][j] != 0)
        return flag[i][j];
    if (i > 0 && matrix[i][j] > matrix[i-1][j]){
        temp = 1 + dfs_Longest_Path(matrix,row,col,flag,i-1,j);
        len = max(len,temp);
    }
    if (i < row-1 && matrix[i][j] > matrix[i+1][j]){
        temp = 1 + dfs_Longest_Path(matrix,row,col,flag,i+1,j);
        len = max(len,temp);
    }
    if (j > 0 && matrix[i][j] > matrix[i][j-1]){
        temp = 1 + dfs_Longest_Path(matrix,row,col,flag,i,j-1);
        len = max(len,temp);
    }
    if (j < col-1 && matrix[i][j] > matrix[i][j+1]){
        temp = 1 + dfs_Longest_Path(matrix,row,col,flag,i,j+1);
        len = max(len,temp);
    }
    flag[i][j] = len;
    return len;
}
int longestIncreasingPath(int** matrix, int matrixRowSize, int matrixColSize)
{
    int row = matrixRowSize,col = matrixColSize;
    if (row == 0 || col == 0)
        return 0;
    int maxlen = 0,temp = 0;
    int** flag = (int**)malloc(sizeof(int*) * row);
    for (int i = 0;i < row;i++){
		flag[i] = (int*)malloc(sizeof(int) * col);
        memset(flag[i],0,sizeof(int) * col);
    }
    int i,j;
    for (i = 0;i < row;i++)
    {
        for (j = 0;j < col;j++)
        {
            temp = dfs_Longest_Path(matrix,row,col,flag,i,j);
            maxlen = max(maxlen,temp);
        }
    }
    free(flag);
    return maxlen;
}
