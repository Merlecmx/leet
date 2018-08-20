int countRangeSum(int* nums, int numsSize, int lower, int upper)
{
    long *ar = (long*)malloc(sizeof(long)* numsSize);
    int i,j;
    int count = 0;
    for (i = 0;i < numsSize;i++)
    {
        for (j = i;j < numsSize;j++)
        {
            if (i == j)
                ar[j] = nums[j];
            else
                ar[j] = nums[j] + ar[j-1];
            if (ar[j] <= upper && ar[j] >= lower)
                count++;
        }
    }
    free(ar);
    return count;
}
