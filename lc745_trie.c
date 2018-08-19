#define SIZE 10
typedef struct{
    char* child[26];
    int* ar;        //��ž��д�ǰ׺/��׺��Ȩ��i 
    int arSize;     //ar���ڴ��С 
    int num;      //arԪ�صĸ��� 
}trie;
typedef struct {
    trie* pre;
    trie* suf;
} WordFilter;

trie* triecreat()
{
    trie* p = (trie*)malloc(sizeof(trie));
    for (int i = 0;i < 26;i++)
        p->child[i] = NULL;
    p->ar = (int*)malloc(sizeof(int)* SIZE);
    p->arSize = SIZE;
    p->num = 0;
    return p;
}

WordFilter* wordFilterCreate(char** words) {
    WordFilter* obj = (WordFilter*)malloc(sizeof(WordFilter));
    obj->pre = triecreat();
    obj->suf = triecreat();
    int i,j;
    trie* p = NULL;
    for (i = 0;words[i] != 0;i++)
    {
        j = 0;
        p = obj->pre;
        while (words[i][j] != '\0')         //i���ַ�����ǰ�������pre�ֵ��� 
        {
            int k = words[i][j] - 'a';
            if (p->child[k] == NULL)
            {
                p->child[k] = triecreat();
            }
            p = p->child[k];
            if (p->num == p->arSize)
            {
                p->ar = (int*)realloc(p->ar,(p->arSize + SIZE)* sizeof(int));
                p->arSize += SIZE;
            }
            p->ar[p->num] = i;
            p->num++;
            j++;
        }
        p = obj->suf;
        j--;
        
        while (j >= 0)              //i���ַ����Ӻ�ǰ����suf�ֵ��� 
        {
            int k = words[i][j] - 'a';
            if (p->child[k] == NULL)
            {
                p->child[k] = triecreat();
            }
            p = p->child[k];
            if (p->num == p->arSize)
            {
                p->ar = (int*)realloc(p->ar,(p->arSize + SIZE)* sizeof(int));
                p->arSize += SIZE;
            }
            p->ar[p->num] = i;
            p->num++;
            j--;
        }
    }
    return obj;
}

int wordFilterF(WordFilter* obj, char* prefix, char* suffix) {
    trie* p =obj->pre;
    int i = 0;
    while (prefix[i] != '\0')       //�ҵ���prefixΪǰ׺������i 
    {
        int k = prefix[i] - 'a';
        if (p->child[k] == NULL)
            return -1;
        p = p->child[k];
        i++;
    }
    int j = strlen(suffix);
    trie* q = obj->suf;
    while (j > 0)      //��suffixΪ��׺
    {
        int k = suffix[j-1] - 'a';
        if (q->child[k] == NULL)
            return -1;
        q = q->child[k];
        j--;
    }
    i = p->num-1;
    j = q->num-1;
    if (prefix[0] == '\0') return q->ar[j];
    if (suffix[0] == '\0') return p->ar[i];
    while (i >= 0 && j >= 0)           //����ar������ǵݼ��������� 
    {
        if (p->ar[i] == q->ar[j])
            return p->ar[i];
        else if (p->ar[i] < q->ar[j])
            j--;
        else
            i--;
    }
    return -1;
}
void triefree(trie* p)
{
    if (!p)
        return;
    for (int i = 0;i < 26;i++)
    {
        triefree(p->child[i]);
    }
    free(p->ar);
    free(p);
}
void wordFilterFree(WordFilter* obj) {
    triefree(obj->pre);
    triefree(obj->suf);
    free(obj);
}

/**
 * Your WordFilter struct will be instantiated and called as such:
 * struct WordFilter* obj = wordFilterCreate(words);
 * int param_1 = wordFilterF(obj, prefix, suffix);
 * wordFilterFree(obj);
 */
