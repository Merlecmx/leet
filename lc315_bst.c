/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
typedef struct node{
    int val;
    int n;       //val元素的个数 
    int leftnum;     //小于val元素的个数 
    struct node *left,*right;
}node;
node* creatnode(int key)
{
    node* p = (node*)malloc(sizeof(node));
    p->left = p->right = NULL;
    p->val = key;
    p->n = 1;
    p->leftnum = 0;
    return p;
}
node* root;
void insert(int key,int* ar,int id)
{
    if (!root){
        root = creatnode(key);
        ar[id] = 0;
        return ;
    }
    node* p = root;
    node* f = NULL;
    int count = 0;
    while (p)
    {
        if (key == p->val){
            ar[id] = count+p->leftnum;
            p->n++;
            return ;
        }
        else if (key < p->val){
            p->leftnum++;
            f = p;
            p = p->left;
        }
        else{
            count += (p->n + p->leftnum);
            f = p;
            p = p->right;
        }
    }
    if (key < f->val)
        f->left = creatnode(key);
    else       
        f->right = creatnode(key);
    ar[id] = count;
}
int* countSmaller(int* nums, int numsSize, int* returnSize)
{
    int* ar = (int*)malloc(sizeof(int)* numsSize);
    *returnSize = numsSize;
    root = NULL;
    int i;
    for (i = numsSize-1;i >= 0;i--)
    {
        insert(nums[i],ar,i);
    }
    return ar;
}
