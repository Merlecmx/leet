/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
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
int* intersection(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize)
{
    *returnSize = 0;
    Qsort(nums1,0,nums1Size-1);
    Qsort(nums2,0,nums2Size-1);
    int* ar = (int*)malloc(sizeof(int)* nums1Size);
    int i = 0, j = 0;
    while (i < nums1Size && j < nums2Size)
    {
        if (nums1[i] == nums2[j])
        {
            if (*returnSize == 0 || nums1[i] != ar[*returnSize-1])
                ar[(*returnSize)++] = nums1[i];
            i++;
            j++;
        }
        else if (nums1[i] < nums2[j])
            i++;
        else
            j++;
    }
    return ar;
}
