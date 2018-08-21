#define SIZE 50000
struct node {
    int key;
    int val;
    struct node* next;
};
typedef struct {
    struct node* head[SIZE];
} MyHashMap;

/** Initialize your data structure here. */
MyHashMap* myHashMapCreate() {
    MyHashMap* obj = (MyHashMap*)malloc(sizeof(MyHashMap));
    for (int i = 0;i < SIZE;i++)
        obj->head[i] = NULL;
    return obj;
}
void creat(MyHashMap* obj,int key,int value)
{
    struct node* p = (struct node*)malloc(sizeof(struct node));
    p->key = key;
    p->val = value;
    p->next = obj->head[key%SIZE];
    obj->head[key%SIZE] = p;
}
/** value will always be positive. */
void myHashMapPut(MyHashMap* obj, int key, int value) {
    int t = key % SIZE;
    if (obj->head[t] == NULL)
    {
        creat(obj,key,value);
    }
    else
    {
        struct node* p = obj->head[t];
        while (p && p->key != key)  p = p->next;
        if (p == NULL)
        {
            creat(obj,key,value);
        }
        else
        {
            p->val = value;
        }
    }
}

/** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
int myHashMapGet(MyHashMap* obj, int key) {
    int t = key % SIZE;
    if (obj->head[t] != NULL)
    {
        struct node* p = obj->head[t];
        while (p && p->key != key)  p = p->next;
        if (p->key == key)
            return p->val;
    }
    return -1;
}

/** Removes the mapping of the specified value key if this map contains a mapping for the key */
void myHashMapRemove(MyHashMap* obj, int key) {
    int t = key % SIZE;
    if (obj->head[t] != NULL)
    {
        struct node* p = obj->head[t];
        struct node* fp = p;
        while (p && p->key != key)
        {
            fp = p;
            p = p->next;
        }
        if (p != NULL && fp != p)
            fp->next = p->next;
        if (fp == p)
            obj->head[t] = p->next;
    }
}

void myHashMapFree(MyHashMap* obj) {
    for (int i = 0;i < SIZE;i++)
    {
        struct node* p = obj->head[i];
        while (p)
        {
            struct node* q = p->next;
            free(p);
            p = q;
        }
    }
    free(obj);
}

/**
 * Your MyHashMap struct will be instantiated and called as such:
 * struct MyHashMap* obj = myHashMapCreate();
 * myHashMapPut(obj, key, value);
 * int param_2 = myHashMapGet(obj, key);
 * myHashMapRemove(obj, key);
 * myHashMapFree(obj);
 */
