#define SIZE 1000001
int smallestDistancePair(int* nums, int numsSize, int k)
{
    int* distance = (int*)malloc(sizeof(int) * SIZE);
    memset(distance,0,sizeof(int) * SIZE);
    int i,j;
    for (i = 0;i < numsSize-1;i++)
    {
        for (j = i+1;j < numsSize;j++)
        {
            int t = nums[i] - nums[j];
            t = t > 0 ? t : -t;
            distance[t]++;
        }
    }
    for (i = 0;i < SIZE;i++)
    {
        if (distance[i] >= k)
             break;
        else
            k -= distance[i];
    }
    return i;
}
