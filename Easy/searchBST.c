/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

struct TreeNode* Recursive(struct TreeNode* root, int val)
{
    if(root==NULL) {
        return NULL;
    }
    if(root->val == val)
    {
        return root;
    }
    
    struct TreeNode* return_left = Recursive(root->left,val);
    if(return_left != NULL) return return_left;
    struct TreeNode* return_right = Recursive(root->right,val);
    if(return_right != NULL) return return_right;
    // if the two return pointer are equal to null pointer, return nothing.
    return NULL;
}

struct TreeNode* searchBST(struct TreeNode* root, int val){
    struct TreeNode* ans = Recursive(root,val);
    return ans;
}
