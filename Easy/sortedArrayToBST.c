/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


struct TreeNode* recursive(int *nums, int beg, int end){
    if(end < beg)
    {
        return NULL;
    }
        
    int mid = (beg + end)/2 ;

    struct TreeNode* r = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    r->val = nums[mid];
    r->left = recursive(nums, beg, mid-1);
    r->right = recursive(nums, mid+1, end);
    return r;
}
struct TreeNode* sortedArrayToBST(int* nums, int numsSize){
    return recursive(nums, 0, numsSize-1);
}
