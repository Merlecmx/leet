/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* sortArrayByParity(int* A, int ASize, int* returnSize)
{
    *returnSize = ASize;
    int* ar = (int*)malloc(sizeof(int) * ASize);
    int i,j,k;
    for (i = 0,j = ASize-1,k = 0;k < ASize;k++)
    {
        if (A[k] & 1)
            ar[j--] = A[k];
        else
            ar[i++] = A[k];
    }
    return ar;
}
