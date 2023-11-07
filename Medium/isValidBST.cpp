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

    bool check(TreeNode* root, long max, long min)
    {
        if(root == nullptr) return true;
        if(long(root->val) >=max || long(root->val) <=min) return false;
        return check(root->left,long(root->val),min) && check(root->right,max,long(root->val));
    }
    bool isValidBST(TreeNode* root) {
        if(root == nullptr) return true;
        long max = LONG_MAX;
        long min = LONG_MIN;
        return check(root->left,root->val,min) && check(root->right,max,root->val);
        //return check(root,max,min);
    }
};
