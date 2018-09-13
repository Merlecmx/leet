bool canPartition(int* nums, int numsSize)
{
    int sum = 0;
    int i,j;
    for (i = 0;i < numsSize;i++)
    {
        sum += nums[i];
    }
    if (sum & 1)
        return false;
    int half = sum / 2;
    int (*ar)[half+1] = (int(*)[half+1])malloc(sizeof(int) * (numsSize+1) * (half+1));
    ar[0][0] = 1;
    for (i = 1;i <= half;i++)
        ar[0][i] = 0;
    for (i = 1;i <= numsSize;i++)
        ar[i][0] = 1;
    for (i = 1;i <= numsSize;i++)
    {
        for (j = 1;j <= half;j++)
        {
            ar[i][j] = ar[i-1][j];
            if (j >= nums[i-1])
                ar[i][j] = ar[i][j] || ar[i-1][j-nums[i-1]];
        }
    }
    return ar[numsSize][half];
}
