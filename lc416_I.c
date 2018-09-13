int min(int a,int b)
{
    return a < b ? a : b;
}
bool canPartition(int* nums, int numsSize){
    int sum = 0;
    int i,j;
    for (i = 0;i < numsSize;i++)
    {
        sum += nums[i];
    }
    if (sum & 1)
        return false;
    int half = sum / 2;
    int* flag = (int*)malloc(sizeof(int) * (half+1));
    memset(flag,0,sizeof(int) * (half+1));
    flag[0] = 1;
    int cursum = 0;
    for (i = 0;i < numsSize;i++)
    {
        int tmax = min(cursum + nums[i],half);
        for (j = tmax;j >= nums[i];j--)
        {
            // j °üÀ¨nums[i], flag[j] = flag[j - nums[i]];
            // j ²»°üÀ¨nums[i], flag[j] = flag[j];
            flag[j] = flag[j] || flag[j - nums[i]];
        }
        if (flag[half]) 
            return true;
        cursum += nums[i];
    }
    return false;
}
