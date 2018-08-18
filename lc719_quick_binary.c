int Partition(int* ar,int low,int high)
{
    int pivotkey = ar[low];
    while (low < high)
    {
        while (low < high && pivotkey <= ar[high])  high--;
        ar[low] = ar[high];
        while (low < high && pivotkey >= ar[low])  low++;
        ar[high] = ar[low];
    }
    ar[low] = pivotkey;
    return low;
}
void Qsort(int* ar,int low,int high)
{
     if (low < high)
     {
         int k = Partition(ar,low,high);
         Qsort(ar,low,k-1);
         Qsort(ar,k+1,high);
     }
}
int smallestDistancePair(int* nums, int numsSize, int k)
{
    Qsort(nums,0,numsSize-1);
    int i,j;
    int low = 0,high = nums[numsSize-1] - nums[0];
    while (low <= high)
    {
        int mid = (low+high) / 2;
        int j = 0,count = 0;
        for (i = 0;i < numsSize;i++)
        {
            while (j < numsSize && nums[j] - nums[i] <= mid)
            {
                j++;
            }
            count += j - 1 - i;
        }
        if (count < k)
            low = mid+1;
        else
            high = mid-1;
    }
    return low;
}
