void Merge(long long* ar,long long* ct,int low,int mid,int high,int lower,int upper,int* count)
{
    if (low == high && ar[low] <= upper && ar[low] >= lower)  (*count)++;
    int i = low,j = mid+1,k = mid+1;
    for (i = low;i <= mid;i++)
    {
        while (j <= high && ar[j] - ar[i] < lower) j++; 
        while (k <= high && ar[k] - ar[i] <= upper) k++;
        *count += (k - j);
    }
     i = low,j = mid+1;
     k = low;
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
void Msort(long long* ar,long long* ct,int low,int high,int lower,int upper,int* count)
{
     if (low < high)
     {
         int mid = (low + high)/2;
         Msort(ar,ct,low,mid,lower,upper,count);
         Msort(ar,ct,mid+1,high,lower,upper,count);
         Merge(ar,ct,low,mid,high,lower,upper,count);
     }
}
int countRangeSum(int* nums, int numsSize, int lower, int upper)
{
    long long* sum = (long long*)malloc(sizeof(long long) * (numsSize+1));
    long long* ct = (long long*)malloc(sizeof(long long) * (numsSize+1));
    sum[0] = 0;
    for (int i = 0;i < numsSize;i++)
    {
        sum[i+1] = nums[i] + sum[i];
    }
    int count = 0;
    Msort(sum,ct,0,numsSize,lower,upper,&count);
    free(sum);
    free(ct);
    return count;
}
