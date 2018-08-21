#define SIZE 1000000/8
int ar[1000000];
typedef struct {
    unsigned char * hash;
} MyHashMap;

/** Initialize your data structure here. */
MyHashMap* myHashMapCreate() {
    MyHashMap* H = (MyHashMap*)malloc(sizeof(MyHashMap));
    H->hash = (int*)malloc(sizeof(unsigned char)* SIZE);
    memset(H->hash,0,sizeof(unsigned char)* SIZE);
    return H;
}

/** value will always be positive. */
void myHashMapPut(MyHashMap* obj, int key, int value) {
    int i = key / 8;
    int j = key % 8;
    obj->hash[i] |= 1 << j;
    ar[key] = value;
}

/** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
int myHashMapGet(MyHashMap* obj, int key) {
    int i = key / 8;
    int j = key % 8;
    if (obj->hash[i] & 1 << j)
        return ar[key];
    else
        return -1;
}

/** Removes the mapping of the specified value key if this map contains a mapping for the key */
void myHashMapRemove(MyHashMap* obj, int key) {
    int i = key / 8;
    int j = key % 8;
    obj->hash[i] &= ~(1<<j);
}

void myHashMapFree(MyHashMap* obj) {
    free(obj->hash);
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
