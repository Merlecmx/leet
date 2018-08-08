#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
typedef struct node{
        char res[31];
        int num;
        int bf;
        struct node *l,*r;
}node;
node* creatnode(char* s)
{
      node* p = (node*)malloc(sizeof(node));
      strcpy(p->res,s);
      p->l = p->r = NULL;
      p->num = 1;
      p->bf = 0;
      return p;
}
void r_rotate(node** root)
{
    node* lc = (*root)->l;
    (*root)->l = lc->r;
    lc->r = *root;
    *root = lc;
}
void l_rotate(node** root)
{
    node* rc = (*root)->r;
    (*root)->r = rc->l;
    rc->l = *root;
    *root = rc; 
}
void left_balance(node** root)
{
    node* lc = (*root)->l;
    switch(lc->bf)
    {
        case 1:
            (*root)->bf = lc->bf = 0;
            r_rotate(root);
            break;
        case -1:
            node *rd = lc->r;
            switch(rd->bf){
                case 1:(*root)->bf = -1; lc->bf = 0; break;
                case 0:(*root)->bf = lc->bf = 0; break;
                case -1:(*root)->bf = 0; lc->bf = 1; break;
            }
            rd->bf=0;
            l_rotate(&((*root)->l));
            r_rotate(root);
    }
}
void right_balance(node** root)
{
    node* rc = (*root)->r;
    switch(rc->bf)
    {
        case -1:
            (*root)->bf = rc->bf = 0;
            l_rotate(root);
            break;
        case 1:
            node *ld = rc->l;
            switch(ld->bf)
            {
                case 1: (*root)->bf = 0; rc->bf = -1; break;
                case 0: (*root)->bf = rc->bf = 0; break;
                case -1: (*root)->bf = 1; rc->bf = 0;break;
            }
            ld->bf = 0;
            r_rotate(&((*root)->r));
            l_rotate(root);
    }
}
void dfsmax(node* p,int *t)
{
    if (!p) return ;
    dfsmax(p->l,t);
    if (*t < p->num)
        *t = p->num;
    dfsmax(p->r,t);
}
bool insert_avl(node** root,char* s,bool* taller)
{
     if (*root == NULL){
         *root = creatnode(s);
         *taller = 1;
         return true;
     }
     if (strcmp((*root)->res,s) == 0)
     {
         *taller = 0;
         (*root)->num++;
         return false;
     }
     if(strcmp(s,(*root)->res) < 0)
     {
        if(!insert_avl(&((*root)->l),s,taller))return false;
        if(taller){
            switch((*root)->bf){
                case 1: left_balance(root);*taller = false; break;
                case 0: (*root)->bf = 1; *taller = true; break;
                case -1: (*root)->bf = 0; *taller = false; break;
            }
        }
    }
    else
    {
        if(!insert_avl(&((*root)->r),s,taller)) return false;
        if(taller){
            switch((*root)->bf){
                case 1: (*root)->bf = 0; *taller = false; break;
                case 0: (*root)->bf = -1; *taller = true; break;
                case -1: right_balance(root); *taller = false; break;
            }
        }
    }
    return true;
}
              
int main()
{
    int i,n,max;
    bool taller;
    char s[31];
    while (scanf("%d",&n) != EOF)
    {
        max= 1;
        node* root = NULL;
        while (n--){
            scanf("%s",s);
            for (i = 0;s[i] == '0';i++);
            strcpy(s,s+i);
            insert_avl(&root,s,&taller);
        }
        dfsmax(root,&max);
        printf("%d\n",max);
    }
    return 0;
}
