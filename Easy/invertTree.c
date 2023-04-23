/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
void recursive(struct TreeNode* r)
{
    if(r == NULL)
    {
        return;
    }
    struct TreeNode* temp = r->right;
    r->right = r->left;
    r->left = temp;
    recursive(r->left);
    recursive(r->right);
}

struct TreeNode* invertTree(struct TreeNode* root){
    recursive(root);
    return root;
}
