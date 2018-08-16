/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *columnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
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

int** levelOrder(struct TreeNode* root, int** columnSizes, int* returnSize)
{
    if(!root) return NULL;
    *returnSize = depth(root);
    Queue *Q =(Queue*)malloc(sizeof(Queue));
    Q->front = Q->rear = (struct TreeNode*)malloc(sizeof(struct TreeNode) * 20000);
    struct TreeNode* head = Q->front;
    Q->n = 0;

    int **ar = (int**)malloc(*returnSize * sizeof(int*));
    *columnSizes= (int*)malloc(*returnSize * sizeof(int));
    memset(*columnSizes,0,*returnSize*sizeof(int));
    int i;
    int level = 0;
    struct TreeNode* p = root;
    Push(Q,p);
    while (Q->front != Q->rear)
    {
        int size = Q->n;
        ar[level] = (int*)malloc(sizeof(int)*size);
        
        (*columnSizes)[level]=size;
        for (i = 0; i < size;i++)
        {
            p = Pop(Q);
            ar[level][i] = p->val;
            if (p->left != NULL)
                Push(Q,p->left);
            if (p->right != NULL)
                Push(Q,p->right);
        }
        level++;
    }
    free(Q);
    free(head);
    return ar;
}
