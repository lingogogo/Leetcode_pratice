/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int recursive(struct TreeNode* root)
{
    if(!root)
        return 0;
    if(!root->left && !root->right)
    {
        return 1;
    }
    int k1 = recursive(root->left);
    
    int k2 = recursive(root->right);
    if(k1==-1 || k2==-1)
        return -1;
    
    if(abs(k1-k2)>1)
        return -1;
    
    if(k1>=k2)
        return ++k1;
    else
        return ++k2;
}
bool isBalanced(struct TreeNode* root){
    if(!root)
        return true;
    return recursive(root)!=-1;
}
