#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int S_cmp(const void *a,const void *b)
{
    return strcmp(*(char**)a,*(char**)b);
}
char *ar[3002];  
int main()
{
    int i,j,n;
    int count,max;
    for (i = 0;i < 3002;i++)
    {
            ar[i] = (char*)malloc(32 * sizeof(char));
    }
    while (scanf("%d",&n) != EOF)
    {
        for (i = 0;i < n;i++)
        {
            scanf("%s",ar[i]);
            for (j = 0;ar[i][j] == '0';j++);
            strcpy(ar[i],ar[i]+j);
        }
        qsort(ar,n,sizeof(ar[0]),S_cmp);
        count = 0;
        max = 0;
        for (i = 1;i < n;i++)
        {
            if (strcmp(ar[i],ar[i-1]) == 0)
                count++;
            else
            {
                if (count > max){
                    max = count;
                }
                count = 0;
            }
        }
        if (count > max)
            max = count;
        printf("%d\n",max+1);
    }
    return 0;
}

