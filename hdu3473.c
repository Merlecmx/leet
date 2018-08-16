#include<stdio.h>
#include<stdlib.h>
int Partition(int* ar,int low,int high)
{
    int pivotkey = ar[low];
    while (low < high)
    {
        while (low < high && pivotkey <= ar[high])  high--;
        ar[low] = ar[high];
        while (low < high && pivotkey >= ar[low])  low++;
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
    int i,j,k,left,right;
    int T,n,m;
    int suml,sumr;
    scanf("%d",&T);
    for (i = 1;i <= T;i++)
    {
        scanf("%d", &n);
        int* ar = (int*)malloc(sizeof(int)* n);
        int* ct = (int*)malloc(sizeof(int)* n);
        for (j = 0;j < n;j++)
        {
            scanf("%d",&ar[j]);
        }
        scanf("%d",&m);
        for (j = 1;j <= m;j++)
        {
            suml = 0,sumr = 0;
            scanf("%d%d",&left,&right);
            for (k = left;k <= right;k++)
            {
                ct[k] = ar[k];
            }
            Qsort(ct,left,right);
            for (k = left;k <= right;k++)
            {
                if ((right - left + 1)%2 == 0){
                    if (k <= (left+right)/2)
                        suml += ct[k];
                    else
                        sumr += ct[k];
                }
                else{
                     if (k < (left+right)/2)
                         suml += ct[k];
                     else if( k == (left+right)/2)
                         continue;
                     else
                         sumr += ct[k];
                }
            }
            if (j == 1)
                printf("Case #%d\n",i);
            printf("%d\n",sumr-suml);
        }
        if (i < T)
            printf("\n");
        free(ar);
        free(ct);
    }
    return 0;
}
