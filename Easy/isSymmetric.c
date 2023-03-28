/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

bool isSymmetric(struct TreeNode* root){
    bool recursive(struct TreeNode*,struct TreeNode*);
    bool ans = recursive(root->left,root->right);
    return ans;
}
bool recursive(struct TreeNode* p,struct TreeNode* q)
{
    if(!p && !q)
    {
        return true;
    }
    if(!p || !q)
    {
        return false;
    }
    if(p->val != q->val)
    {
        return false;
    }
    bool b1 = recursive(p->left,q->right);
    bool b2 = recursive(p->right,q->left);
    return (b1 && b2);
}
