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
    if(!root) return 0;
    if(!root->left && !root->right) return 1;
    int c1 = recursive(root->left);
    int c2 = recursive(root->right);

    if((c1==0 || c2==0))
        return fmax(c1,c2)+1;
    else if((c1!=0 && c2!=0))
        return fmin(c1,c2)+1;
    else 
        return -1;
}
int minDepth(struct TreeNode* root){
    if(!root) return 0;
    return recursive(root);
}
