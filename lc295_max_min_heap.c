typedef struct {
    int* maxheap;
    int* minheap;
    int max_n;
    int min_n;
} MedianFinder;

void swim(int* heap,int p)        //Ԫ�����ϵ���
{
     int q = p/2;
     int temp = heap[p];
     while (q && temp < heap[q])
     {
         heap[p] = heap[q];
         p = q;
         q = q/2;
     }
     heap[p] = temp;
}
void sink(int* heap,int p,int n)         //Ԫ�����µ���
{
     int q = 2*p;
     int temp = heap[p];
     while (q <= n)
     {
         if (q < n && heap[q] > heap[q+1])
             q++;
         if (temp <= heap[q])
             break;
         heap[p] = heap[q];
         p = q;
         q *= 2;
     }
     heap[p] = temp;
}
/** initialize your data structure here. */
MedianFinder* medianFinderCreate() {
    MedianFinder* M = (MedianFinder*)malloc(sizeof(MedianFinder));
    M->minheap = (int*)malloc(sizeof(int) * 10000);
    M->maxheap = (int*)malloc(sizeof(int) * 10000);
    M->min_n = 0;
    M->max_n = 0;
    return M;
}

void insert(int* heap,int* n,int num)
{
    *n++;
    heap[*n] = num;
}
int pop(int* heap,int* n)
{
    int t = heap[1];
    heap[1] = heap[*n];
    *n--;
    sink(heap,1,*n);
    return t;
    
}
void medianFinderAddNum(MedianFinder* obj, int num) {
    if (obj->max_n == 0 && obj->min_n == 0)
    {
        insert(obj->maxheap,&(obj->max_n),num);
        printf("%d\n",obj->maxheap[1]);
        printf("%d\n",obj->max_n);
    }
    if (num > obj->maxheap[1])
    {
        insert(obj->minheap,&obj->min_n,num);
        swim(obj->minheap,obj->min_n);
        if (obj->min_n - obj->max_n > 1)
        {
            int t = pop(obj->minheap,obj->min_n);
            insert(obj->maxheap,&obj->max_n,t);
            swim(obj->maxheap,obj->max_n);
        }
    }
    else
    {
        //obj->max_n++;
        insert(obj->maxheap,&obj->max_n,num);
        swim(obj->maxheap,obj->min_n);
        if (obj->max_n - obj->min_n > 1)
        {
            int t = pop(obj->maxheap,obj->max_n);
            insert(obj->minheap,&obj->minheap,t);
            swim(obj->minheap,obj->min_n);
        }
    }
    printf("%d\n",obj->maxheap[1]);
    printf("%d\n",obj->minheap[1]);
}

double medianFinderFindMedian(MedianFinder* obj) {
    if (obj->max_n == obj->min_n)
        return (obj->maxheap[obj->max_n] + obj->minheap[obj->min_n]) / 2.0;
    else
        return obj->max_n > obj->min_n ? obj->maxheap[1] : obj->minheap[1];
}

void medianFinderFree(MedianFinder* obj) {
    free(obj->maxheap);
    free(obj->minheap);
    free(obj);
}

/**
 * Your MedianFinder struct will be instantiated and called as such:
 * struct MedianFinder* obj = medianFinderCreate();
 * medianFinderAddNum(obj, num);
 * double param_2 = medianFinderFindMedian(obj);
 * medianFinderFree(obj);
 */
