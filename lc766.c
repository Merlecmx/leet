bool isToeplitzMatrix(int** matrix, int matrixRowSize, int *matrixColSizes)
{
    int temp[matrixColSizes[0]];
    int i,j;
    for (i = 1;i < matrixRowSize;i++)
    {
        for (j = 1;j < matrixColSizes[0];j++)
        {
            if (matrix[i][j] != matrix[i-1][j-1])
                return false;
        }
    }
    return true;
}
