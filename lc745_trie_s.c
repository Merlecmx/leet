typedef struct {
    struct WordFilter *child[27];
    int weight;
} WordFilter;

WordFilter* creat()
{
    WordFilter* p = (WordFilter*)malloc(sizeof(WordFilter));
    for (int i = 0;i < 27;i++)
        p->child[i] = NULL;
    p->weight = -1;
    return p;
}
void connection(char* s,char* p,char* q)
{
    s[0] = '\0';
    strcat(s,p);
    strcat(s,"{");
    strcat(s,q);
}
WordFilter* wordFilterCreate(char** words) {
    WordFilter* obj = creat();
    char temp[22];
    int i,j;
    for (i = 0;words[i] != 0;i++)
    {
        int end = 0;
        for (int id = 0;words[i][id];id++)
        {
            if (words[i][id] < 'a' || words[i][id] > 'z')
                end = 1;
        }
        if (end)  break;
        connection(temp,words[i],words[i]);
        int len = strlen(words[i]);
        for (j = 0;j <= len;j++)
        {
            //printf("j=%d\n",j);
            int t = 0;
            WordFilter* p = obj;
            while (temp[j+t] != '\0')
            {
                //printf("%d  ",t);
                int k = temp[j+t] - 'a';
                if (p->child[k] == NULL)
                {
                    p->child[k] = creat();
                }
                p = p->child[k];
                p->weight = i;                //ШЈжи
                t++;
            }
            //printf("\n");
        }
    }
    return obj;
}

int wordFilterF(WordFilter* obj, char* prefix, char* suffix) {
    char temp[22];
    connection(temp,suffix,prefix);
    WordFilter* p = obj;
    int i = 0;
    while (temp[i] != '\0')
    {
        int k = temp[i] - 'a';
        if (p->child[k] == NULL)
            return -1;
        p = p->child[k];
        i++;
    }
    return p->weight;
}

void wordFilterFree(WordFilter* obj) {
    if (!obj)
        return;
    for (int i = 0;i < 27;i++)
    {
        wordFilterFree(obj->child[i]);
    }
    free(obj);
}

/**
 * Your WordFilter struct will be instantiated and called as such:
 * struct WordFilter* obj = wordFilterCreate(words);
 * int param_1 = wordFilterF(obj, prefix, suffix);
 * wordFilterFree(obj);
 */
