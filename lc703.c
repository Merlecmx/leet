typedef struct {
    int *ar;
    int num;
} KthLargest;
int cmp(const void* a,const void* b)
{
    return (*(int*)b - *(int*)a);
}
KthLargest* kthLargestCreate(int k, int* nums, int numsSize) {
    KthLargest* obj = (KthLargest*)malloc(sizeof(KthLargest));
    obj->ar = (int*)malloc(sizeof(int) * (k+1));
    obj->num = k;
    qsort(nums,numsSize,sizeof(nums[0]),cmp);
    int i,j;
    for (i = k,j = 0;i >= 1,j < numsSize;i--,j++)
    {
        obj->ar[i] = nums[j];
    }
    if (k > numsSize)
    {
        obj->ar[1] = INT_MIN;
    }
    return obj;
}
void HeapAdjust(KthLargest* obj,int left,int right)
{
    int key = obj->ar[1];
    int n = obj->num;
    int i,ct = left;
    for (i = 2* ct;i <= n ;i *= 2)
    {
        if (i < n && obj->ar[i] > obj->ar[i+1])
            i++;
        if (key < obj->ar[i])
            break;
        obj->ar[ct] = obj->ar[i];
        ct = i;
    }
    obj->ar[ct] = key;
}
int kthLargestAdd(KthLargest* obj, int val) {
    if (obj->ar[1] == INT_MIN || val > obj->ar[1])
    {
        obj->ar[1] = val;      //替换掉第一个元素
        HeapAdjust(obj,1,obj->num);       //维护堆
    }
    printf("%d\n",obj->ar[1]);
    return obj->ar[1];
}

void kthLargestFree(KthLargest* obj) {
    free(obj->ar);
    free(obj);
}

/**
 * Your KthLargest struct will be instantiated and called as such:
 * struct KthLargest* obj = kthLargestCreate(k, nums, numsSize);
 * int param_1 = kthLargestAdd(obj, val);
 * kthLargestFree(obj);
 */
