/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *columnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** flipAndInvertImage(int** A, int ARowSize, int *AColSizes, int** columnSizes, int* returnSize)
{
    *returnSize = ARowSize;
    *columnSizes = (int*)malloc(sizeof(int) * ARowSize);
    int** ar = (int**)malloc(sizeof(int*) * ARowSize);
    int i,j,k;
    for (i = 0;i < ARowSize;i++)
    {
        k = AColSizes[i];
        (*columnSizes)[i] = k;
        ar[i] = (int*)malloc(sizeof(int) * k);
        for (j = 0;j < AColSizes[i];j++,k--)
        {
            if (A[i][j] & 1)
                ar[i][k-1] = 0;
            else
                ar[i][k-1] = 1;
        }
    }
    return ar;
}
