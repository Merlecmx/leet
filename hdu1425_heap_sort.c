#include<stdio.h>
#include<stdlib.h>
void exchange(int* a,int* b)
{
     int temp = *a;
     *a = *b;
     *b = temp;
}
void HeapAdjust(int* ar,int left,int right)
{
     int rc = ar[left];
     int i;
     for (i = 2* left;i <= right;i *= 2)
     {
         if (i < right && ar[i] > ar[i+1])
            i++;
         if (rc < ar[i])
             break;
         ar[left] = ar[i];
         left = i;
     }
     ar[left] = rc;
}
void HeapSort(int* ar,int n)
{
     int i;
     for (i = n/2;i > 0;i--)
         HeapAdjust(ar,i,n);
     for (i = n;i > 1;i--)
     {
         exchange(&ar[1],&ar[i]);
         HeapAdjust(ar,1,i-1);
     }
}
int main()
{
    int i,n,m;
    while (scanf("%d%d",&n,&m) != EOF)
    {
        int *ar = (int*)malloc(sizeof(int)* (n+1));
        int *ct = (int*)malloc(sizeof(int)* (n+1));
        for (i = 1;i <= n;i++)
        {
            scanf("%d",&ar[i]);
        }
        HeapSort(ar,n);
        for (i = 1;i <= m;i++)
        {
            printf("%d",ar[i]);
            if (i < m)
                printf(" ");
            else
                printf("\n");
        }
        free(ar);
        free(ct);
    }
    return 0;
}
