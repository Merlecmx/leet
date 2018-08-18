int cumulative(int n)
{
    if (!n)
        return 0;
    return n + cumulative(n-1);
}
int missingNumber(int* nums, int numsSize)
{
    int total = cumulative(numsSize);
    int n = 0;
    for (int i = 0;i < numsSize;i++)
    {
        n += nums[i];
    }
    return total - n;
}
