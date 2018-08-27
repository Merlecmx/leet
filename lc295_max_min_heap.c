typedef struct {
    int* ar;
    int n;
}heap;
typedef struct {
    heap* maxheap;
    heap* minheap;
} MedianFinder;

void maxheap_swim(heap* hh)
{
     int p = hh->n;
     int q = p/2;
     int temp = hh->ar[p];
     while (q && temp > hh->ar[q])
     {
         hh->ar[p] = hh->ar[q];
         p = q;
         q = q/2;
     }
     hh->ar[p] = temp;
}
void minheap_swim(heap* hh) 
{
     int p = hh->n;
     int q = p/2;
     int temp = hh->ar[p];
     while (q && temp < hh->ar[q])
     {
         hh->ar[p] = hh->ar[q];
         p = q;
         q = q/2;
     }
     hh->ar[p] = temp;
}
void maxheap_sink(heap* hh)
{
     int num = hh->n, p = 1;
     int q = 2 * p;
     int temp = hh->ar[p];
     while (q <= num)
     {
         if (q < num && hh->ar[q] < hh->ar[q+1])
             q++;
         if (temp >= hh->ar[q])
             break;
         hh->ar[p] = hh->ar[q];
         p = q;
         q *= 2;
     }
     hh->ar[p] = temp;
}
void minheap_sink(heap* hh)
{
     int num = hh->n, p = 1;
     int q = 2 * p;
     int temp = hh->ar[p];
     while (q <= num)
     {
         if (q < num && hh->ar[q] > hh->ar[q+1])
             q++;
         if (temp <= hh->ar[q])
             break;
         hh->ar[p] = hh->ar[q];
         p = q;
         q *= 2;
     }
     hh->ar[p] = temp;
}
heap* creatheap(){
    heap* p = (heap*)malloc(sizeof(heap));
    p->ar = (int*)malloc(sizeof(int) * 10000);
    p->n = 0;
    return p;
}
/** initialize your data structure here. */
MedianFinder* medianFinderCreate() {
    MedianFinder* M = (MedianFinder*)malloc(sizeof(MedianFinder));
    M->minheap = creatheap();
    M->maxheap = creatheap();
    return M;
}

void insert(heap* hh,int num)
{
    hh->n++;
    hh->ar[hh->n] = num;
}
int pop(heap* hh)
{
    int t = hh->ar[1];
    hh->ar[1] = hh->ar[hh->n];
    hh->n--;
    return t;

}
void medianFinderAddNum(MedianFinder* obj, int num) {
    if (obj->maxheap->n == 0 && obj->minheap->n == 0)
    {
        insert(obj->maxheap,num);
        return ;
    }
    if (num > obj->maxheap->ar[1])
    {
        insert(obj->minheap,num);
        minheap_swim(obj->minheap);
        if (obj->minheap->n - obj->maxheap->n > 1)
        {
            
            int t = pop(obj->minheap);
            minheap_sink(obj->minheap);
            insert(obj->maxheap, t);
            maxheap_swim(obj->maxheap);
        }
    }
    else
    {
        insert(obj->maxheap,num);
        maxheap_swim(obj->maxheap);
        if (obj->maxheap->n - obj->minheap->n > 1)
        {
            int t = pop(obj->maxheap);
            maxheap_sink(obj->maxheap);
            insert(obj->minheap, t);
            minheap_swim(obj->minheap);
        }
    }
}
double medianFinderFindMedian(MedianFinder* obj) {
    if (obj->maxheap->n == obj->minheap->n){
        return (obj->maxheap->ar[1] + obj->minheap->ar[1]) / 2.0;
    }
    else{
        return obj->maxheap->n > obj->minheap->n ? obj->maxheap->ar[1] : obj->minheap->ar[1];
    }
}

void medianFinderFree(MedianFinder* obj) {
    free(obj->maxheap->ar);
    free(obj->minheap->ar);
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
