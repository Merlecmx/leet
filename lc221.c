int min(int a,int b, int c)
{
    if (a < b){
        if (c < a)
            return c;
        else
            return a;
    }
    else{
        if (c < b)
            return c;
        else
            return b;
    }
}
int maximalSquare(char** matrix, int matrixRowSize, int matrixColSize)
{
    if (matrixRowSize == 0) return 0;
    int(*ar)[matrixColSize] = (int(*)[matrixColSize])malloc(sizeof(int)* matrixRowSize* matrixColSize);
    memset(ar,0,sizeof(int)* matrixRowSize* matrixColSize);
    int i,j;
    int max = 0;
    for (i = 0;i < matrixRowSize;i++)
    {
        for (j = 0;j < matrixColSize;j++)
        {
            if (matrix[i][j] == '1')
            {
                ar[i][j] = 1;
                if (i > 0 && j > 0)
                    ar[i][j] += min(ar[i-1][j],ar[i][j-1],ar[i-1][j-1]);
            }
            if (ar[i][j] > max)
                max = ar[i][j];
        }
    }
    return max*max;
}
