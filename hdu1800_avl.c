#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <stdbool.h>
#define LH 1
#define EH 0
#define RH -1
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
      p->bf = EH;
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
    node* rd = NULL;
    switch(lc->bf)
    {
        case LH:
            (*root)->bf = lc->bf = EH;
            r_rotate(root);
            break;
        case RH:
            rd = lc->r;
            switch(rd->bf){
                case LH:(*root)->bf = RH; lc->bf = EH; break;
                case EH:(*root)->bf = lc->bf = EH; break;
                case RH:(*root)->bf = EH; lc->bf = LH; break;
            }
            rd->bf=EH;
            l_rotate(&((*root)->l));
            r_rotate(root);
    }
}
void right_balance(node** root)
{
    node* rc = (*root)->r;
    node* ld = NULL;
    switch(rc->bf)
    {
        case RH:
            (*root)->bf = rc->bf = EH;
            l_rotate(root);
            break;
        case LH:
            ld = rc->l;
            switch(ld->bf)
            {
                case LH: (*root)->bf = EH; rc->bf = RH; break;
                case EH: (*root)->bf = rc->bf = EH; break;
                case RH: (*root)->bf = LH; rc->bf = EH;break;
            }
            ld->bf = EH;
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
                case LH: left_balance(root);*taller = false; break;
                case EH: (*root)->bf = LH; *taller = true; break;
                case RH: (*root)->bf = EH; *taller = false; break;
            }
        }
    }
    else
    {
        if(!insert_avl(&((*root)->r),s,taller)) return false;
        if(taller){
            switch((*root)->bf){
                case LH: (*root)->bf=EH; *taller = false; break;
                case EH: (*root)->bf=RH; *taller = true; break;
                case RH: right_balance(root); *taller = false; break;
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
