/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
bool isSameTree(struct TreeNode* p, struct TreeNode* q){
    bool *c = malloc(sizeof(bool));
    *c = true;
    recursive(p,q,c);
    return *c;
}
void recursive(struct TreeNode* p, struct TreeNode* q,bool* c)
{
    if(p == NULL && q == NULL)
    {
        return;
    }
    if(!p || !q)
    {
        *c = false;
        return;
    }
    if(p->val != q->val)
    {
        *c = false;
    }
    recursive(p->left,q->left,c);
    recursive(p->right,q->right,c);
}
