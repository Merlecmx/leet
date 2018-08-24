void change(int* nums,int low,int high,int key)
{
    while (low <= high)
    {
        int mid = (low+high) / 2;
        if (nums[mid] < key)
            low = mid+1;
        else
            high = mid-1;
    }
    nums[low] = key;
}
int lengthOfLIS(int* nums, int numsSize)
{
    if (numsSize == 0)
        return 0;
    int* ar = (int*)malloc(sizeof(int)* numsSize);
    ar[0] = nums[0];
    int count = 1;
    for (int i = 1;i < numsSize;i++)
    {
        if (nums[i] > ar[count-1])
            ar[count++] = nums[i];
        else
        {
           change(ar,0,count-1,nums[i]);
        }
    }
    free(ar);
    return count;
}
