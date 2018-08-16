#include<stdio.h>
#include<string.h> 
char ar[3001][31];
int count[3001];
int max;
int k = 0;    //存入ar的行数 
void insert(char *s)
{
     int i,j;
     int len = strlen(s);
     for (i = 0;i < k;i++)
     {
         for (j = 0;j < len;j++)
         {
             if (ar[i][j] != s[j])
                 break;
         }
         if (j == len)
         {
             count[i]++;
             if (count[i] > max)
                  max = count[i];
             break;
         }
     }
     if (j < len)
     {
         strcpy(ar[k],s);
         count[k] = 1;
         k++;
     }
}
int main()
{
    int i,ct,n;
    char s[32];
    while (scanf("%d",&n)!= EOF)
    {
        max = 1;
        memset(count,0,sizeof(int)*3001);
        for (ct = 0;ct < n;ct++)
        {
            scanf("%s",s);
            for (i = 0;s[i] == '0';i++);
            strcpy(s,s+i);
            insert(s);
        }
        printf("%d\n",max);
    }
}
