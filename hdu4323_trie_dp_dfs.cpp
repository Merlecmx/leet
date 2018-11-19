#include <stdio.h>
#include<string.h>
#include <malloc.h>
#define SIZE 11   //整数的长度
int pos = 0;    //阀值
int count_t = 0;  //满足条件的个数
typedef struct node {
    struct node *child[10];
    char dist[SIZE];
    char have[SIZE];   //当前节点的元素，have[0]存放总个数,  have[1 to 10]依次存放是什么元素
    bool flag;
    char ch;    //当前节点的 前驱元素
}node;

#define min(a, b) ((a) < (b) ? (a) :(b))

inline char min_s(char a, char b,char c)
{
    char t = a<b? a:b;
    return t<c? t:c;
}

node pool[20005];
int used;
inline node* creatnode()
{
    node* p = pool + used++;
    memset(p->child, 0, sizeof(node *) * 10);
    p->have[0] = 0;     //[0]位置初始化为0
    p->flag = false;
    return p;
}
node* root;
void insert(char *s)
{
    node* p = root;
    while (*s)
    {
        node **q = &p->child[*s-'0'];
        if (!*q)
        {
            *q = creatnode();
            p->have[++(p->have[0])] = *s-'0';
        }
        p = *q;
        p->ch = *s++;
    }
    p->flag  = true;
}
int s_len;
void tree_dfs(char depth, node *father, node* pt, char* s)
{
    int i,j,k,id;

    pt->dist[0] = depth;
    int m = depth;
    for (k = 1;k <= s_len;k++)
    {
        pt->dist[k] = min_s(father->dist[k] + 1, pt->dist[k-1] + 1, father->dist[k-1] + (pt->ch == s[k-1] ? 0 : 1)) ;
        m = min(pt->dist[k], m);
    }
    if (m > pos) return;
    for (id = 1;id <= pt->have[0];id++)
    {
        i = pt->have[id];
        tree_dfs(depth+1, pt, pt->child[i], s);
    }
    if (pt->flag) {    //说明当前节点是尾节点
        count_t += pt->dist[s_len] <= pos;
    }
}
void tree_search(char *s)
{
    s_len = strlen(s);
    for (int j = 0;j < s_len;j++)
        root->dist[j] = j;
    for (int id = 1;id <= root->have[0];id++)
        tree_dfs(1, root, root->child[root->have[id]] , s);
}
int main()
{
    int id,T;
    scanf("%d" , &T);
    char res[11];
    for (id = 1;id <= T;id++)
    {
        printf("Case #%d:\n", id);
        used = 0;
        root = creatnode();
        int n,m;

        scanf("%d%d", &n, &m);
        for (int i = 0;i < n;i++)
        {
            scanf("%s", res);
            insert(res);
        }
        for (int j = 0;j < m;j++)
        {
            scanf("%s%d", res, &pos);
            count_t = 0;
            tree_search(res);
            printf("%d\n", count_t);
        }
    }
    return 0;
}
