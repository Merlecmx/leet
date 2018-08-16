#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct node{
        char res[31];
        struct node *left,*right;
        int num;
}node;
void dfsmax(node* p,int *t)
{
    if (!p) return ;
    dfsmax(p->left,t);
    if (*t < p->num)
        *t = p->num;
    dfsmax(p->right,t);
}
node* creatnode(char *s)
{
    node* p = (node*)malloc(sizeof(node));
    strcpy(p->res,s);
    p->left = p->right = NULL;
    p->num = 1;
    return p;
}
node* root;
void insert(char *s)
{
     node *p = root;
     node *f;
     if (!p){
        root = creatnode(s);
        return ;
     }
     int i,z;
     while (p)
     {
         z = strcmp(s,p->res);
         if (z == 0){
             p->num++;
             return ;
         }
         else if (z < 0){
             f = p;
             p = p->left;
         }
         else{
             f = p;
             p = p->right;
         }
     }
     if (z < 0) f->left = creatnode(s);
     else f->right = creatnode(s);
}

int main()
{
    int i,n,max;
    char s[32];
    while (scanf("%d",&n)!= EOF)
    {
        max = 1;
        root = NULL;
        while (n--)
        {
            scanf("%s",s);
            for (i = 0;s[i] == '0';i++);
            strcpy(s,s+i);
            insert(s);
        }
        dfsmax(root,&max);
        printf("%d\n",max);
    }
}
