#include<stdio.h>
#include<stdlib.h>
void Merge(int* ar,int* ct,int low,int mid,int high)
{
     int i = low,j = mid+1;
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
    int i,j,m,n,P;
    scanf("%d",&P);
    while (P--)
    {
        scanf("%d%d",&m,&n);
        int* ar = (int*)malloc(sizeof(int)* (n+1));
        int* ct = (int*)malloc(sizeof(int)* (n+1));
        int* result = (int*)malloc(sizeof(int)* (n/2+2));    //存放每一个中位数 
        for (j = 1;j <= n;j++)
        {
            scanf("%d",&ar[j]);
            if (j%2 == 1)        //对每次j为奇数调用一次合并排序并将中位数存入result数组 
            {
               Msort(ar,ct,1,j);
               result[j/2+1] = ar[j/2+1];
            }
        }
        printf("%d %d\n",m,n/2+1);
        for (i = 1;i <= n/2+1;i++)
        {
            printf("%d",result[i]);
            if (i % 10 != 0 && i < n/2+1)
                printf(" ");
            else
                printf("\n");
        }
        free(ar);
        free(ct);
        free(result);
    }
    return 0;
}
