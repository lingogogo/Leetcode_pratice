/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
bool isSameTree(struct TreeNode* p, struct TreeNode* q){
    if(p==NULL && q==NULL)
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
    bool take1 = isSameTree(p->left,q->left);
    bool take2 = isSameTree(p->right,q->right);
    return (true && take1 && take2);

}
