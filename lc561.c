int Partition(int* nums,int left,int right)
{
    int key = nums[left];
    while (left < right)
    {
        while (left < right && nums[right] >= key) right--;
        nums[left] = nums[right];
        while (left < right && nums[left] <= key) left++;
        nums[right] = nums[left];
    }
    nums[left] = key;
    return left;
}
void Qsort(int* nums,int low,int high)
{
    if (low < high)
    {
        int k = Partition(nums,low,high);
        Qsort(nums,low,k-1);
        Qsort(nums,k+1,high);
    }
}
int arrayPairSum(int* nums, int numsSize)
{
    Qsort(nums,0,numsSize-1);
    int sum = 0;
    for (int i = 0;i < numsSize;i += 2)
    {
        sum += nums[i];
    }
    return sum;
}
