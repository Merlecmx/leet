void swap(int* a,int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
void reverse(int* nums,int i,int j)
{
    while (i < j)
    {
        swap(&nums[i],&nums[j]);
        i++;
        j--;
    }
}
void nextPermutation(int* nums, int numsSize)
{
    int k = -1,right = 0;
    int i;
    for (i = numsSize-2;i >= 0;i--)
    {
        if (nums[i+1] > nums[i])
        {
            k = i;
            break;
        }
    }
    if (k == -1)
    {
        reverse(nums,0,numsSize-1);
        return ;
    }
    for (i = numsSize-1;i >= 0;i--)
    {
        if (nums[i] > nums[k])
        {
            right = i;
            break;
        }
    }
    swap(&nums[k],&nums[right]);
    reverse(nums,k+1,numsSize-1);
}
