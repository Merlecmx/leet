#define SIZE 20000
typedef struct {
    int* hash;
    int* visited;
} MyHashSet;

/** Initialize your data structure here. */
MyHashSet* myHashSetCreate() {
    MyHashSet* H = (MyHashSet*)malloc(sizeof(MyHashSet));
    H->hash = (int*)malloc(sizeof(int)* SIZE);
    H->visited = (int*)malloc(sizeof(int)* SIZE);
    memset(H->hash,0,sizeof(int)* SIZE);
    memset(H->visited,0,sizeof(int)* SIZE);
    return H;
}
int myhashfun(int k)
{
    return (k % SIZE);
}
void myHashSetAdd(MyHashSet* obj, int key) {
    int t = myhashfun(key);
    while (obj->visited[t] != 0 && obj->hash[t] != key)
        t = myhashfun(t+1);
    if (obj->visited[t] == 0)
    {
        obj->hash[t] = key;
        obj->visited[t] = 1;
    }
}

void myHashSetRemove(MyHashSet* obj, int key) {
    int t = myhashfun(key);
    while (obj->visited[t] != 0 && obj->hash[t] != key)
        t = myhashfun(t+1);
    if (obj->hash[t] == key)
    {
        obj->hash[t] = 0;
        obj->visited[t] = 0;
    }
}

/** Returns true if this set did not already contain the specified element */
bool myHashSetContains(MyHashSet* obj, int key) {
    int t = myhashfun(key);
    while (obj->visited[t] != 0 && obj->hash[t] != key)
        t = myhashfun(t+1);
    if (obj->visited[t] == 0)
        return false;
    else
        return true;
}

void myHashSetFree(MyHashSet* obj) {
    free(obj->hash);
    free(obj->visited);
    free(obj);
}

/**
 * Your MyHashSet struct will be instantiated and called as such:
 * struct MyHashSet* obj = myHashSetCreate();
 * myHashSetAdd(obj, key);
 * myHashSetRemove(obj, key);
 * bool param_3 = myHashSetContains(obj, key);
 * myHashSetFree(obj);
 */
