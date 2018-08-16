typedef struct {
    int *ar;
    int num;
    int kn;
} KthLargest;

int cmp(const void* a,const void* b)
{
    return (*(int*)a - *(int*)b);
}

void swap(int* a,int* b)
{
     int temp = *a;
     *a = *b;
     *b = temp;
}

void swim(int* heap,int p)        //元素向上调整
{
     int q = p/2;
     int a = heap[p];
     while (q && a < heap[q])
     {
         heap[p] = heap[q];
         p = q;
         q = q/2;
     }
     heap[p] = a;
}

void sink(int* heap,int p,int n)         //元素向下调整
{
     int q = 2*p;
     int a = heap[p];
     while (q <= n)
     {
         if (q < n && heap[q] > heap[q+1])
             q++;
         if (a <= heap[q])
             break;
         heap[p] = heap[q];
         p = q;
         q *= 2;
     }
     heap[p] = a;
}

void build(int* heap,int n)          //建堆
{
     int i;
     for (i = n/2;i > 0;i--)
         sink(heap,i,n);
}

KthLargest* kthLargestCreate(int k, int* nums, int numsSize) {
    KthLargest* obj = (KthLargest*)malloc(sizeof(KthLargest));
    obj->ar = (int*)malloc(sizeof(int) * (k+1));
    obj->kn = k;
    obj->num = 0;
    if (numsSize == 0)
        return obj;
    int i,j;
    qsort(nums,numsSize,sizeof(nums[0]),cmp);
    int t  = numsSize - k;
    for (i = 1,j = t;j < numsSize;i++,j++)
    {
        while (j < 0) j++;
        obj->ar[i] = nums[j];
        obj->num++;
    }
    return obj;
}

int kthLargestAdd(KthLargest* obj, int val) {
    if (obj->num < obj->kn)
    {
        obj->ar[++(obj->num)] = val;
        swim(obj->ar,obj->num);         //加入到最后，并维护堆
        return obj->ar[1];
    }
    if (val > obj->ar[1])
    {
        swap(&(obj->ar[1]),&val);      //替换第一个元素
        sink(obj->ar,1,obj->kn);       //维护堆
    }
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
