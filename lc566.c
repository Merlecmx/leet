/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *columnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** matrixReshape(int** nums, int numsRowSize, int numsColSize, int r, int c, int** columnSizes, int* returnSize)
{
    int row = numsRowSize,col = numsColSize;
    if (row * col != r * c)
    {
        printf("Hello World!");
        *returnSize = row;
        *columnSizes = (int*)malloc(sizeof(int) * row);
        for (int k = 0;k < row;k++)
            (*columnSizes)[k] = col;
        return nums;
    }
    *columnSizes = (int*)malloc(sizeof(int) * r);
    *returnSize = r;
    int i,j;
    int** ar = (int**)malloc(sizeof(int*) * r);
    for (i = 0;i < r;i++)
    {
        ar[i] = (int*)malloc(sizeof(int) * c);
        (*columnSizes)[i] = c;
    }
    int m = 0,n = 0;
    for (i = 0;i < row;i++)
    {
        for (j = 0;j < col;j++)
        {
            if (n == c){
                m++;
                n = 0;
            }
            ar[m][n++] = nums[i][j];
        }
    }
    return ar;
}
