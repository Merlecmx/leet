bool place(char** board,int row,int col,char ch)
{
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
void dfs_Sodoku(char** board,int i,int j)
{
    if (i == 8 && j == 9){
        //printf("Hello World!");
        flag = 1;
        return ;
    }
    if (j == 9){
        i++;
        j = 0;
    }
    if (board[i][j] == '.')
    {
        for (char ch = '1';ch <= '9';ch++)
        {
            board[i][j] = ch;
            if (place(board,i,j,ch)){
                dfs_Sodoku(board,i,j+1);
            }
            if (flag) return ;
            board[i][j] = '.';
        }
    }
    else
        dfs_Sodoku(board,i,j+1);
}
void solveSudoku(char** board, int boardRowSize, int boardColSize)
{
    //int row = boardRowSize,col = boardColSize;
    flag = 0;
    dfs_Sodoku(board,0,0);  
}
