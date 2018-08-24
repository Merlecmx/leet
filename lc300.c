int lengthOfLIS(int* nums, int numsSize)
{
    if (numsSize == 0)
        return 0;
    int* ar = (int*)malloc(sizeof(int)* numsSize);
    int i,j;
    int len = 1;
    for (i = 0;i < numsSize;i++){
        ar[i] = 1;
    }
    for (i = 1;i < numsSize;i++)
    {
        for (j = 0;j < i;j++)
        {
            if (nums[j] < nums[i] && ar[j]+1 > ar[i]){
                ar[i] = ar[j]+1;
            }
        }
        if (ar[i] > len)
            len = ar[i];
    }
    return len;
}
