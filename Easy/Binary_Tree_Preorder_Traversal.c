/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */


void recursive(struct TreeNode* root,int* ans,int* returnSize)
{
    if(!root)
        return;
    
    ans[*returnSize] = root->val;
    *returnSize+=1;
    recursive(root->left,ans,returnSize);
    recursive(root->right,ans,returnSize);
    return;
}

int* preorderTraversal(struct TreeNode* root, int* returnSize){
    *returnSize = 0;
    int* ans = (int*)malloc(101*sizeof(int));
    recursive(root,ans,returnSize);
    return ans;

}
