/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *columnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** transpose(int** A, int ARowSize, int *AColSizes, int** columnSizes, int* returnSize)
{
    int i,j;
    *returnSize = AColSizes[0];
    int** ar = (int**)malloc(sizeof(int*) * AColSizes[0]);
    *columnSizes = (int*)malloc(sizeof(int) * ARowSize);
    for (i = 0;i < AColSizes[0];i++)
    {
        ar[i] = (int*)malloc(sizeof(int) * ARowSize);
        (*columnSizes)[i] = ARowSize;
    }
    for (i = 0;i < ARowSize;i++)
    {
        for (j = 0;j < AColSizes[0];j++)
        {
            ar[j][i] = A[i][j];
        }
    }
    return ar;
}
