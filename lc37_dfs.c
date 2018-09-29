bool place(char** board,int count,char ch)
{
    int row = count / 9;
    int col = count % 9;
    for (int k = 0;k < 9;k++)
    {
        if (ch == board[row][k] && k != col)
            return false;
    }
    for (int t = 0;t < 9;t++)
    {
        if (ch == board[t][col] && t != row)
            return false;
    }
    for (int i = row/3 * 3;i < row/3 * 3 + 3;i++)
    {
        for (int j = col/3 * 3;j < col/3 * 3 + 3;j++)
        {
            if (board[i][j] == ch && i != row && j != col)
                return false;
        }
    }
    return true;
}
int flag = 0;
void dfs_Sodoku(char** board,int count)
{
    int i = count / 9;
    int j = count % 9;
    if (count == 81){
        //printf("Hello World!");
        flag = 1;
        return ;
    }
    if (board[i][j] == '.')
    {
        for (char ch = '1';ch <= '9';ch++)
        {
            board[i][j] = ch;
            if (place(board,count,ch)){
                dfs_Sodoku(board,count+1);
            }
            if (flag) return ;
            board[i][j] = '.';
        }
    }
    else
        dfs_Sodoku(board,count+1);
}
void solveSudoku(char** board, int boardRowSize, int boardColSize)
{
    //int row = boardRowSize,col = boardColSize;
    int count = 0;
    flag = 0;
    dfs_Sodoku(board,count);   
}
