#include<stdio.h>
#include<stdlib.h>
typedef struct node{
        struct node *child[10];
        int num;
}node,*tree;
node* creatnode()
{
      node* p = (node*)malloc(sizeof(node));
      p->num = 0;
      for (int i = 0;i < 10;i++)
      {
          p->child[i] = NULL;
      }
      return p;
}
node* root;
int insert(char* s)
{
    node* p = root;
    int i;
    for (i = 0;s[i] == '0';i++);
    while (s[i] != '\0')
    {
        if (p->child[s[i]-'0'] == NULL)
        {
           p->child[s[i]-'0'] = creatnode();
        }
        p = p->child[s[i]-'0'];
        i++;
    }
    p->num++;
    return p->num;
}
int main()
{
    int t,n,max;
    char s[32];
    while (scanf("%d",&n)!= EOF)
    {
        max = 1;
        root = creatnode();
        while (n--)
        {
            scanf("%s",s);
            t = insert(s);
            if (max < t)
                max = t;
        }
        printf("%d\n",max);
    }
}
