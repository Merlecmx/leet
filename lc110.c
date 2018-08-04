/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int depth(struct TreeNode* p)
{
    if (p == NULL)
        return 0;
    //else if (!p->left && !p->right)
        //return 1;
    else
    {
        int l_len = depth(p->left);
        int r_len = depth(p->right);
        return 1 + (l_len > r_len ? l_len : r_len);
    }
}
bool isBalanced(struct TreeNode* root)
{
    if (root == NULL)
        return true;
    int x = depth(root->left) - depth(root->right);
    if (x < -1 || x > 1)
        return false;
    else
        return isBalanced(root->left) && isBalanced(root->right);
}
