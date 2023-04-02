/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
bool recursive(struct TreeNode* root, int t)
{
    if(!root)
    {
        return false;
    }
    t -= root->val;
    if(t == 0 && !root->right && !root->left)
        return true;
    

    bool k = recursive(root->right, t);
    bool k1 =recursive(root->left,t);
    if(k==true || k1==true)
    {
        return true;
    }else
    {
        return false;
    }
}

bool hasPathSum(struct TreeNode* root, int targetSum){
    if(!root)
    {
        return false;
    }
    return recursive(root,targetSum);
}
