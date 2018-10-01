void moveZeroes(int* nums, int numsSize)
{
    int low,high;
    for (low = 0,high = 0;high < numsSize;high++)
    {
        if (nums[high])
            nums[low++] = nums[high];
    }
    while (low < numsSize)
        nums[low++] = 0;
}
