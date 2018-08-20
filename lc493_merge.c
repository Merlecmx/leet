void Merge(int* ar,int* ct,int low,int mid,int high,int* count)
{
    int i = low,j = mid+1;
    while (i <= mid && j <= high)
    {
        if ((long)ar[i] > (long)2* ar[j])
        {
            *count += (mid-i+1);
            j++;
        }
        else
            i++;
    }
     i = low,j = mid+1;
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
void Msort(int* ar,int* ct,int low,int high,int* count)
{
     if (low < high)
     {
         int mid = (low + high)/2;
         Msort(ar,ct,low,mid,count);
         Msort(ar,ct,mid+1,high,count);
         Merge(ar,ct,low,mid,high,count);
     }
}
int reversePairs(int* nums, int numsSize) {
    int count = 0;
    int* ct = (int*)malloc(sizeof(int)* numsSize);
    Msort(nums,ct,0,numsSize-1,&count);
    free(ct);
    return count;
}
