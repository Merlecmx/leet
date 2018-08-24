int maxSubArray(int* nums, int numsSize)
{
    int max = nums[0];
    int temp = 0;
    int *sum = (int*)malloc(sizeof(int) * numsSize);
    sum[0] = nums[0];
    for (int i = 1;i < numsSize;i++)
    {
        if (nums[i] + sum[i-1] >= nums[i])
        {
            sum[i] = nums[i] + sum[i-1];
            temp = sum[i];
        }
        else
        {
            sum[i] = nums[i];
            temp = nums[i];
        }
        if (temp > max)
            max = temp;
    }
    free(sum);
    return max;
}
