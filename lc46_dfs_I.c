/**
 * Return an array of arrays of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int count(int n)
{
    if (n == 1)
        return 1;
    else
        return n * count(n-1);
}
void swap(int* a,int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
void dfs_backtrack(int* nums,int numsSize,int* returnSize,int** ar,int idex)
{
    if (idex == numsSize)
    {
        ar[*returnSize] = malloc(sizeof(int) * numsSize);
        memcpy(ar[*returnSize],nums,sizeof(int) * numsSize);
        (*returnSize)++;
        return ;
    }
    for (int i = idex;i < numsSize;i++)
    {
        swap(&nums[idex],&nums[i]);
        dfs_backtrack(nums,numsSize,returnSize,ar,idex+1);
        swap(&nums[idex],&nums[i]);
    }
}
int** permute(int* nums, int numsSize, int* returnSize)
{
    int size = count(numsSize);
    *returnSize = 0;
    int** ar = (int**)malloc(sizeof(int*) * size);

    dfs_backtrack(nums,numsSize,returnSize,ar,0);

    return ar;
}
