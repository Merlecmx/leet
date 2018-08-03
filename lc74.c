bool searchMatrix(int** matrix, int matrixRowSize, int matrixColSize, int target)
{
    int *ar = (int*)malloc(matrixRowSize* sizeof(int));
    int i;
    for (i = 0;i < matrixRowSize;i++)
    {
        ar[i] = matrix[i][matrixColSize-1];
    }
    for (i = 0;i < matrixRowSize;i++)
    {
        if (ar[i] == target)
            return true;
        else if (ar[i] > target)
            break;
    }
    int j;
    if (i == matrixRowSize)
        return false;
    for (j = 0;j < matrixColSize;j++)
    {
        if (matrix[i][j] == target)
            return true;
    }
    return false;
}
