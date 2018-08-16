void Merge(int* ar,int* ct,int low,int mid,int high)
{
     int i = low,j = mid+1;
     int k = low;
     while (i <= mid && j <= high)
     {
         if (ar[i] < ar[j])
             ct[k++] = ar[i++];
         else
             ct[k++] = ar[j++];
     }
     while (i <= mid)
         ct[k++] = ar[i++];
     while (j <= high)
         ct[k++] = ar[j++];
     for (i = low;i <= high;i++)
         ar[i] = ct[i];
}
void Msort(int* ar,int* ct,int low,int high)
{
     if (low < high)
     {
         int mid = (low + high)/2;
         Msort(ar,ct,low,mid);
         Msort(ar,ct,mid+1,high);
         Merge(ar,ct,low,mid,high);
     }
}

bool containsDuplicate(int* nums, int numsSize)
{
    int* ct = (int*)malloc(sizeof(int)* numsSize);
    Msort(nums,ct,0,numsSize-1);
    for (int i = 1;i < numsSize;i++)
    {
        if (nums[i] == nums[i-1])
            return true;
    }
    return false;   
}
