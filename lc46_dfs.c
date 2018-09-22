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
void dfs_backtrack(int* nums,int numsSize,int* returnSize,int** ar,int* temp,int idex,int* flag)
{
    if (idex == numsSize)
    {
        ar[*returnSize] = malloc(sizeof(int) * numsSize);
        memcpy(ar[*returnSize],temp,sizeof(int) * numsSize);
        (*returnSize)++;
        return ;
    }
    for (int i = 0;i < numsSize;i++)
    {
        if (!flag[i]){
            temp[idex] = nums[i];
            flag[i] = 1;
            dfs_backtrack(nums,numsSize,returnSize,ar,temp,idex+1,flag);
            flag[i] = 0;
        }
    }
}
int** permute(int* nums, int numsSize, int* returnSize)
{
    int size = count(numsSize);
    *returnSize = 0;
    int** ar = (int**)malloc(sizeof(int*) * size);
    int* temp = (int*)malloc(sizeof(int) * numsSize);
    int* flag = (int*)malloc(sizeof(int) * numsSize);
    memset(flag,0,sizeof(int) * numsSize);
    
    dfs_backtrack(nums,numsSize,returnSize,ar,temp,0,flag);
    
    free(temp);
    free(flag);
    
    return ar;
}
