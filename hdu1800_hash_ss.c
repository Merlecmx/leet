#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include<string.h>
#define SIZE 4000
#define COL 31
char hash[SIZE][COL];
int count[SIZE];
int max;

unsigned int BKDRHash(char *s)
{
    unsigned int seed = 131;
    unsigned int hash = 0;
    while (*s)
    {
        hash = hash * seed + *s++;
    }
    return (hash% INT_MAX);
}
void hashit(char *s)
{
     int k,t;
     while (*s == '0')
         s++;
     k = BKDRHash(s);
     t = k % SIZE;
     while (count[t]!= -1 && strcmp(hash[t],s) != 0)
         t = (t+10)% SIZE;
     if (count[t] == -1)
     {
         strcpy(hash[t],s);
         count[t] = 1;
     }
     else
     {
         count[t]++;
         if (count[t] > max)
             max = count[t];
     }
}
int main()
{
    int n;
    char s[32];
    while (scanf("%d",&n)!= EOF)
    {
        max = 1;
        memset(count,-1,sizeof(int)*SIZE);
        while (n--)
        {
            scanf("%s",s);
            hashit(s);
        }
        printf("%d\n",max);
    }
    return 0;
}
