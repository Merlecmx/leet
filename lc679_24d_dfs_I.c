bool dfs_game(double* ct,int size)
{
    if (size == 1){
        if (fabs(ct[0] - 24) < 0.0001)
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
            
            ct[i] = b - a;
            if (dfs_game(ct,size-1)) return true;
            
            ct[i] = a * b;
            if (dfs_game(ct,size-1)) return true;
            
            if (b != 0){
                ct[i] = a / b;
                if (dfs_game(ct,size-1)) return true;
            }
            
            if (a != 0){
                ct[i] = b / a;
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
    double* ct = (double*)malloc(sizeof(double) * numsSize);
    for (i = 0;i < numsSize;i++)
    {
        ct[i] = nums[i];
    }
        if (dfs_game(ct,numsSize))
        {
            free(ct);
            return true;
        }
    free(ct);
    return false;
}
