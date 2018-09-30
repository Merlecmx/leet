/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* findDisappearedNumbers(int* nums, int numsSize, int* returnSize)
{
    int* ar = (int*)malloc(sizeof(int) * 1);
    *returnSize = 0;
    int i;
    for (i = 0;i < numsSize;i++)
    {
        int k = abs(nums[i]) - 1;
        nums[k] = nums[k] > 0 ? -nums[k] : nums[k];
    }
    for (i = 0;i < numsSize;i++)
    {
        if (nums[i] > 0)
        {
            if (*returnSize != 0)
                ar = (int*)realloc(ar,((*returnSize)+1) * sizeof(int));
            ar[*returnSize] = i+1;
            (*returnSize)++;
        }
    }
    return ar;
}
