void recursive(struct TreeNode* root,int* ans,int* returnSize)
{
    if(!root)
        return;
    
    
    recursive(root->left,ans,returnSize);
    recursive(root->right,ans,returnSize);
    ans[*returnSize] = root->val;
    *returnSize+=1;
    return;
}


int* postorderTraversal(struct TreeNode* root, int* returnSize){
    *returnSize = 0;
    int* ans = (int*)malloc(101*sizeof(int));
    recursive(root,ans,returnSize);
    return ans;
}
