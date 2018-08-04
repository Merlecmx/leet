/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode* Binary_dfs(int* nums,int left,int right)
{
    if (left > right)
        return NULL;
    int mid = (left+right) /2;
    struct TreeNode* root = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    root->val = nums[mid];
    root->left = Binary_dfs(nums,left,mid-1);
    root->right = Binary_dfs(nums,mid+1,right);
    return root;
}
struct TreeNode* sortedArrayToBST(int* nums, int numsSize)
{
    
    return Binary_dfs(nums,0,numsSize-1);
}
