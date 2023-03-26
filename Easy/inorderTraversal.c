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

 // try to use recursive
int c = 0;

int* inorderTraversal(struct TreeNode* root, int* returnSize){
    int tot_s = 100;
    int* ans = malloc(tot_s*sizeof(int));
    recursive(root,ans);
    
    *returnSize = c;
    c=0;
    return ans;
}
void recursive(struct TreeNode* now,int* ans)
{
    if(now!=NULL)
    {
        //First, all the root go to the left bottom node.
        //If there is no left node, the function will start return number.
        recursive(now->left,ans);
        ans[c++] = now->val;
        recursive(now->right,ans);
    }
}
