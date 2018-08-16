/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
typedef struct{
    struct TreeNode *front;
    struct TreeNode *rear;
    int n;
}Queue; 

void Push(Queue *ptr,struct TreeNode* p)
{
    *ptr->rear++ = *p;
    ptr->n++;
}
struct TreeNode* Pop(Queue *ptr)
{
    ptr->n--;
    return ptr->front++;
}
Queue* creatqueue()
{
    Queue *Q =(Queue*)malloc(sizeof(Queue));
    Q->front = Q->rear = (struct TreeNode*)malloc(sizeof(struct TreeNode) * 20000);
    Q->n = 0;
    return Q;
}

int depth(struct TreeNode* p)
{
    if (p == NULL)
        return 0;
    else
    {
        int l_len = depth(p->left);
        int r_len = depth(p->right);
        return 1 + (l_len > r_len ? l_len : r_len);
    }
}
double* averageOfLevels(struct TreeNode* root, int* returnSize)
{
    if (!root)  return NULL;
    Queue *Q = creatqueue();
    struct TreeNode* head = Q->front;

    *returnSize = depth(root);
    double* ar = (double*)malloc(*returnSize * sizeof(double));
    int i;
    int level = 0;
    struct TreeNode* p = root;
    Push(Q,p);
    while (Q->front != Q->rear)
    {
        double sum = 0;
        int size = Q->n;
        for (i = 0; i < size;i++)
        {
            p = Pop(Q);
            sum += p->val;
            if (p->left)
                Push(Q,p->left);
            if (p->right)
                Push(Q,p->right);
        }
        ar[level++] = sum / size;
    }
    free(Q);
    free(head);
    return ar;  
}
