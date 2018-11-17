#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
#define SIZE 11   //�����ĳ��� 
int pos = 0;    //��ֵ
int count_t = 0;  //���������ĸ��� 
typedef struct node {
    struct node *child[10];
    int dist[SIZE];
    int have[SIZE];   //��ǰ�ڵ��Ԫ�أ�have[0]����ܸ���,  have[1 to 10]���δ����ʲôԪ��
    int n;     //�жϵ�ǰ�ڵ��Ƿ�Ϊ�ַ�����β�ڵ� 
    char ch;    //��ǰ�ڵ�� ǰ��Ԫ��
}node;

node* creatnode()
{
      node* p = (node*)malloc(sizeof(node));
      p->ch = '#';
      p->have[0] = 0;     //[0]λ�ó�ʼ��Ϊ0 
      p->n = 0;
      for (int i = 0;i < 10;i++)
      {
          p->child[i] = NULL;
      }
      return p;
}
node* root;
void insert(const string &s)
{
    node* p = root;
    int i = 0;
    while (s[i] != '\0')
    {
        if (p->child[s[i]-'0'] == NULL)
        {
           p->child[s[i]-'0'] = creatnode();
           p->have[++(p->have[0])] = s[i] - '0';
        }
        p = p->child[s[i]-'0'];
        p->ch = s[i];
        i++;
    }
    p->n = 1;
}
void tree_dfs(node* father,node* pt,const string &s,int lev)
{
    if (lev > s.size() + pos)    //��֧ 
        return ;
    int i,j,k,id;
    pt->dist[0] = lev;
    for (k = 1;k <= s.size();k++)
    {
        pt->dist[k] = min(min(father->dist[k] + 1, pt->dist[k-1] + 1), father->dist[k-1] + (pt->ch == s[k-1] ? 0 : 1));
    }
    for (id = 1;id <= pt->have[0];id++)
    {
        i = pt->have[id];
        tree_dfs(pt, pt->child[i], s, lev+1);
    }
    if (pt->n == 1) {    //˵����ǰ�ڵ���ĳ�ַ�����β�ڵ� 
        count_t += pt->dist[s.size()] <= pos;
    }
}
void tree_search(const string &s)
{
    for (int j = 0;j <= s.size();j++)
        root->dist[j] = j;
    for (int id = 1;id <= root->have[0];id++)
        tree_dfs(root, root->child[root->have[id]] , s, 1);
}
int main()
{
    int id,T;
    cin >> T;
    for (id = 1;id <= T;id++)
    {
        cout << "Case #" << id << ":" << endl;
        root = creatnode();
        int i,j;
        int n,m;
        string res;
        cin >> n >> m;
        for (i = 0;i < n;i++)
        {
            cin >> res;
            insert(res);
        }
        for (j = 0;j < m;j++)
        {
            cin >> res >> pos;
            count_t = 0;
            tree_search(res);
            cout << count_t << endl;
        }
    }
    return 0;
}
