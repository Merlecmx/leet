int maxCoins(int* nums, int numsSize)
{
    int n = numsSize+2;
    int* ct = (int*)malloc(sizeof(int)* n);
    int i,k,left,right;
    for (i = 0;i < numsSize;i++)
        ct[i+1] = nums[i];
    ct[0] = ct[n-1] = 1;
    
    int (*ar)[n]=(int(*)[n])malloc(sizeof(int)* n* n);
    memset(ar,0,sizeof(int)* n* n);
    
    for (i = 2;i < n;i++) 
    {
        for (left = 0;left < n-i;left++)
        {
            right = left+i;
            for (k = left+1;k < right;k++)
            {
                int sum = ar[left][k] + ar[k][right] + ct[left] * ct[k] * ct[right];
                if (sum > ar[left][right])
                    ar[left][right] = sum;
            }
        }
    }
    return ar[0][n-1];
}
