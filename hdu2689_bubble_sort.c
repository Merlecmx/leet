#include <stdio.h>
#include <stdlib.h>
void exchange(int* a,int* b)
{
     int temp = *a;
     *a = *b;
     *b = temp;
}
int main()
{
    int i,j,n;
    while (scanf("%d",&n) != EOF)
    {
        int count = 0;
        int *ar = (int*)malloc(sizeof(int)* n);
        for (i = 0;i < n;i++)
        {
            scanf("%d",&ar[i]);
        }
        for (i = 0;i < n-1;i++)       //Ã°ÅÝÅÅÐò 
        {
            for (j = i+1;j < n;j++)
            {
                if (ar[i] > ar[j])
                {
                    exchange(&ar[i],&ar[j]);
                    count++;
                }
            }
        }
                    
                    
        printf("%d\n",count);
        free(ar);
    }
    return 0;
}
