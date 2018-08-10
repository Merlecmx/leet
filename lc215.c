int Partition(int* ar,int low,int high)
{
    int pivotkey = ar[low];
    while (low < high)
    {
        while (low < high && pivotkey >= ar[high])  high--;
        ar[low] = ar[high];
        while (low < high && pivotkey <= ar[low])  low++;
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
int findKthLargest(int* nums, int numsSize, int k)
{
    Qsort(nums,0,numsSize-1);
    return nums[k-1];
}
