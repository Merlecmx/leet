#include<stdio.h>
#include<stdlib.h>
void Merge(int* ar,int* ct,int low,int mid,int high)
{
     int i = low,j = mid+1;
     //int i,j = mid+1;
     int k = low;
     while (i <= mid && j <= high)
     {
         if (ar[i] > ar[j])
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
int main()
{
    int i,n,m;
    while (scanf("%d%d",&n,&m) != EOF)
    {
        int *ar = (int*)malloc(sizeof(int)* n);
        int *ct = (int*)malloc(sizeof(int)* n);
        for (i = 0;i < n;i++)
        {
            scanf("%d",&ar[i]);
        }
        Msort(ar,ct,0,n-1);
        for (i = 0;i < m;i++)
        {
            printf("%d",ct[i]);
            if (i < m-1)
                printf(" ");
            else
                printf("\n");
        }
        free(ar);
        free(ct);
    }
    return 0;
}
