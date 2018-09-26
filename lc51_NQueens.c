/**
 * Return an array of arrays of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
bool place(int level,int* board)
{
    for (int i = 0;i < level;i++)
    {
        if (abs(level - i) == abs(board[i] - board[level]) || board[i] == board[level])
            return false;
    }
    return true;
}
void dfs_nqueens(char*** ar,int n,int* returnSize,int level,int* board)
{
    if (level == n)
    {
        //ar[*returnSize] == (char(*)[n+1])malloc(sizeof(char) * n * (n+1));
        //char (*temp)[n+1] = (char(*)[n+1])malloc(sizeof(char) * n * (n+1));
        /*for (int i = 0;i < n;i++)
        {
            for (int j = 0;j < n;j++)
            {
                temp[i][j] = '.';
            }
            temp[i][n] = '\0';
        }*/
        for (int k = 0;k < n;k++)
        {
            ar[*returnSize][k][board[k]] = 'Q';
            ar[*returnSize][k][n] = '\0';
        }
        //ar[*returnSize] = temp;
        
        (*returnSize)++;
    }
    else
    {
        for (int i = 0;i < n;i++)
        {
            board[level] = i;
            if (place(level,board))
                dfs_nqueens(ar,n,returnSize,level+1,board);
        }
    }
}
char*** solveNQueens(int n, int* returnSize)
{
    *returnSize = 0;
    int* board = (int*)malloc(sizeof(int) * n);
    memset(board,0,sizeof(int) * n);
    
    char*** ar = (char(***))malloc(sizeof(char**) * 400);
    for (int i = 0;i < 400;i++)
    {
        ar[i] = (char(**))malloc(sizeof(char*) * n);
        for (int j = 0;j < n;j++)
        {
            ar[i][j] = (char*)malloc(sizeof(char) * (n+1));
            memset(ar[i][j],'.',sizeof(char) * n);
        }
    }
        
    dfs_nqueens(ar,n,returnSize,0,board);
    ar = (char***)realloc(ar,sizeof(char**) * (*returnSize));
    free(board);

    return ar;
}
