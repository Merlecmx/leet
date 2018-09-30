int Partition(int* ar,int low,int high)
{
    int pivotkey = ar[low];
    while (low < high)
    {
        while (low < high && pivotkey <= ar[high])  high--;
        ar[low] = ar[high];
        while (low < high && pivotkey >= ar[low])  low++;
        ar[high] = ar[low];
    }
    ar[low] = pivotkey;
    return low;
}
void Qsort(int* ar,int low,int high)
{
     if (low < high)
     {
         int k = Partition(ar,low,high);
         Qsort(ar,low,k-1);
         Qsort(ar,k+1,high);
     }
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
        if (i > 0 && nums[i] == nums[i-1] && !flag[i-1])
            continue;
        if (!flag[i]){
            temp[idex] = nums[i];
            flag[i] = 1;
            dfs_backtrack(nums,numsSize,returnSize,ar,temp,idex+1,flag);
            flag[i] = 0;
        }
    }
}
int** permuteUnique(int* nums, int numsSize, int* returnSize)
{
    Qsort(nums,0,numsSize-1);
    *returnSize = 0;
    int** ar = (int**)malloc(sizeof(int*) * 10000);
    int* temp = (int*)malloc(sizeof(int) * numsSize);
    int* flag = (int*)malloc(sizeof(int) * numsSize);
    memset(flag,0,sizeof(int) * numsSize);
    
    dfs_backtrack(nums,numsSize,returnSize,ar,temp,0,flag);
    ar = (int**)realloc(ar,sizeof(int*) * (*returnSize));
    free(temp);
    free(flag);
    
    return ar;
}
bool dfs_game(double* ct,int size)
{
    if (size == 1){
        if (fabs(ct[0] - 24.0) <= 0.0001)
            return true;
        return false;
    }
    for (int i = 0;i < size;i++)
    {
        for (int j = i+1;j < size;j++)
        {
            double a = ct[i];
            double b = ct[j];
            ct[j] = ct[size-1];
            
            ct[i] = a + b;
            if (dfs_game(ct,size-1)) return true;
            
            ct[i] = a - b;
            if (dfs_game(ct,size-1)) return true;
            
            ct[i] = a * b;
            if (dfs_game(ct,size-1)) return true;
            
            if (b != 0){
                ct[i] = a / b;
                if (dfs_game(ct,size-1)) return true;
            }
            
            ct[i] = a;
            ct[j] = b;
        }
    }
    return false;
}
bool judgePoint24(int* nums, int numsSize)
{
    int i,j;
    int size = 0;
    int** ar = permuteUnique(nums,numsSize,&size);
    double* ct = (double*)malloc(sizeof(double) * numsSize);
    for (i = 0;i < size;i++)
    {
        for (j = 0;j < numsSize;j++)
            ct[j] = (double)ar[i][j];
        if (dfs_game(ct,numsSize))
        {
            free(ar);
            free(ct);
            return true;
        }
    }
    free(ar);
    free(ct);
    return false;
}
