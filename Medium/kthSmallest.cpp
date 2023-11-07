/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void dothejob(TreeNode* r,int& k, int& ans){
        if(r == nullptr){
            return;
        } 
        
        dothejob(r->left,k,ans);
        if(k == 1) ans = r->val;
        k--;
        dothejob(r->right,k,ans);
        
        return;
    }

    int kthSmallest(TreeNode* root, int k) {
        int ans = 0;
        int temp = k;
        dothejob(root,temp,ans);
        return ans;
    }
    
};
