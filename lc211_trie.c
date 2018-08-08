typedef struct {
    char* child[26];
    int num;
} WordDictionary;

/** Initialize your data structure here. */
WordDictionary* wordDictionaryCreate() {
    WordDictionary* p = (WordDictionary*)malloc(sizeof(WordDictionary));
    for (int i = 0;i < 26;i++)
        p->child[i] = NULL;
    p->num = 0;
    return p;
}

/** Adds a word into the data structure. */
void wordDictionaryAddWord(WordDictionary* obj, char* word) {
    WordDictionary* p = obj;
    int i = 0;
    while (word[i] != '\0')
    {
        int k = word[i] - 'a';
        if (p->child[k] == NULL)
        {
            p->child[k] = wordDictionaryCreate();
        }
        p = p->child[k];
        i++;
    }
    p->num = 1;
}

/** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
bool wordDictionarySearch(WordDictionary* obj, char* word) {
    if (*word == '\0')
        return (obj->num) ? true : false;
    if (obj == NULL)
        return false;
    int i = 0;
    int flag = false;
    if (*word == '.')
    {
        for (int i= 0;i < 26;i++)
        {
            if (obj->child[i])
            {
                int t =  wordDictionarySearch(obj->child[i],word+1);
                if (t)
                    flag = true;
            }
        }
        return flag;
    }
    else
    {
        int k = *word - 'a';
        if (obj->child[k] == NULL)
            return false;
        else
            return wordDictionarySearch(obj->child[k],word+1);
    }
}

void wordDictionaryFree(WordDictionary* obj) {
    if (!obj)
        return;
    for (int i = 0;i < 26;i++)
    {
        wordDictionaryFree(obj->child[i]);
    }
    free(obj);
}

/**
 * Your WordDictionary struct will be instantiated and called as such:
 * struct WordDictionary* obj = wordDictionaryCreate();
 * wordDictionaryAddWord(obj, word);
 * bool param_2 = wordDictionarySearch(obj, word);
 * wordDictionaryFree(obj);
 */
