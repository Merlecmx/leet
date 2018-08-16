struct list{
    int val;
    int id;
};
void Merge(struct list* ar,struct list* ct,int low,int mid,int high)
{
     int i = low,j = mid+1;
     int k = low;
     while (i <= mid && j <= high)
     {
         if (ar[i].val <= ar[j].val)
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
bool containsNearbyDuplicate(int* nums, int numsSize, int k)
{
    struct list* ar = (struct list*)malloc(sizeof(struct list) * numsSize);
    struct list* ct = (struct list*)malloc(sizeof(struct list) * numsSize);
    int i;
    for (i = 0;i < numsSize;i++)
    {
        ar[i].val = nums[i];
        ar[i].id = i;
    }
    Msort(ar,ct,0,numsSize-1);
    for (i = 0;i < numsSize;i++)
        printf("%d   %d\n",ar[i].val,ar[i].id);
    for (i = 1;i < numsSize;i++)
    {
        if (ar[i].val == ar[i-1].val && ar[i].id - ar[i-1].id <= k)
            return true;
    }
    return false;
}
