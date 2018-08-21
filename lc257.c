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
int Leafcount(struct TreeNode* T)
{
    int n = 0;
    if (!T) return 0;
	  if(T->left==NULL && T->right==NULL)
	  {
		    n++;
	  }			
	  return n + Leafcount(T->left) + Leafcount(T->right);
}
void strcpy_s(char* s,int* temp,int id)
{
    int t = 0;
    for (int i= 0;i < id;i++)
    {
        t += sprintf(s+t,"%d->",temp[i]);
    }
    s[t-2] = '\0';
}
void dfs(struct TreeNode* root,char** s,int* returnSize,int* temp,int* id)
{
    temp[(*id)++] = root->val;
    if (root->left== NULL && root->right== NULL)
    {
        s[(*returnSize)] = (char*)malloc(sizeof(char) * 100);
        strcpy_s(s[(*returnSize)],temp,*id);
        (*returnSize)++;
        (*id)--;
        return;
    }
    if (root->left != NULL)
        dfs(root->left,s,returnSize,temp,id);
    if (root->right != NULL)
        dfs(root->right,s,returnSize,temp,id);
    (*id)--;
}
char** binaryTreePaths(struct TreeNode* root, int* returnSize)
{
    if (!root)  return NULL;
    *returnSize = 0;
    int n = Leafcount(root);
    char** s = (char**)malloc(n * sizeof(char*));
    int* temp = (int*)malloc(sizeof(int)* 100);
    int id = 0;
    dfs(root,s,returnSize,temp,&id);
    free(temp);
    
    return s;
}
