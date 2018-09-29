bool place(char** board,int count,char ch)
{
    /*int i = count / 9;
    int j = count % 9;
    for (int k = 0;k < 9;k++)
    {
        int x = i / 3 * 3 + k / 3;
        int y = j / 3 * 3 + k % 3;
        if (board[i][k] == ch && i != k || board[k][j] == ch && j != k || board[x][y] == ch && x != i && y != j)
            return false;
    }*/
    int row = count / 9;
    int col = count % 9;
    for (int k = 0;k < 9;k++)
    {
        if (ch == board[row][k] && k != col|| ch == board[k][col] && k != row)
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
void dfs_Sodoku(char** board,int count)
{
    if (count == 80)
        return ;
    int i = count / 9;
    int j = count % 9;
    if (board[i][j] == '.')
    {
        for (char ch = '1';ch <= '9';ch++)
        {
            board[i][j] = ch;
            if (place(board,count,ch)){
                dfs_Sodoku(board,count+1);
            }
            board[i][j] == '.';
        }
    }
    else
    {
        dfs_Sodoku(board,count+1);
    }
}
void solveSudoku(char** board, int boardRowSize, int boardColSize)
{
    //int row = boardRowSize,col = boardColSize;
    int count = 0;

    dfs_Sodoku(board,count);
    
}
