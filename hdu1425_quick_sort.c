#include<stdio.h>
#include<stdlib.h>
int Partition(int* ar,int low,int high)
{
    int pivotkey = ar[low];
    while (low < high)
    {
        while (low < high && pivotkey >= ar[high])  high--;
        ar[low] = ar[high];
        while (low < high && pivotkey <= ar[low])  low++;
        ar[high] = ar[low];
    }
    ar[low] = pivotkey;
    return low;
}
void Qsort(int* ar,int low,int high)
{
     if (low < high)
     {
         int k = Partition(ar,low,high);
         Qsort(ar,low,k-1);
         Qsort(ar,k+1,high);
     }
}
int main()
{
    int i,n,m;
    while (scanf("%d%d",&n,&m) != EOF)
    {
        int *ar = (int*)malloc(sizeof(int)* (n+1));
        for (i = 0;i < n;i++)
        {
            scanf("%d",&ar[i]);
        }
        Qsort(ar,0,n-1);
        for (i = 0;i < m;i++)
        {
            printf("%d",ar[i]);
            if (i < m-1)
                printf(" ");
            else
                printf("\n");
        }
        free(ar);
    }
    return 0;
}
